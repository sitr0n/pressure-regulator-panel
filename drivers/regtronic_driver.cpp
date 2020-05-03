#include "regtronic_driver.h"
#include <QMutexLocker>

RegtronicDriver::RegtronicDriver(std::shared_ptr<ExternalDevice> device)
    : m_device(device)
    , m_pressure(0)
{
}

RegtronicDriver::~RegtronicDriver()
{
    exitEventLoop();
}

bool RegtronicDriver::open(const QString &address)
{
    if (!exitEventLoop()) {
        emit error(QString("RegtronicDriver::open(%0) - Couldn't stop current thread").arg(address));
    }
    m_address = address;
    return startEventLoop();
}

void RegtronicDriver::setPressure(float bar)
{
    enqueue([&, bar]{
        if (!m_device->write(QChar(0b0011011))) { // ASCII BIN CODE FOR ESC
            return false;
        }
        if (!m_device->write('P')) { // lower?
            return false;
        }
        if (!m_device->write(QString::number(bar))) { // works for float too?
            return false;
        }
        return true;
    });
}

float RegtronicDriver::pressure()
{
    QMutexLocker lock(&m_mutex);
    return m_pressure;
}

void RegtronicDriver::run()
{
    QMutexLocker lock(&m_mutex);
    if (!m_device->connect(m_address)) {
        return;
    }
    while (!m_events.empty()) {
        auto event = m_events.dequeue();
        m_mutex.unlock();
        auto delivered = event();
        m_mutex.lock();
        if (!delivered) {
            m_events.enqueue(event);
        }
    }
    m_device->close();
}

bool RegtronicDriver::startEventLoop()
{
    enqueue([&]{
        if (!m_device->write(QChar(0b0011011))) { // ASCII BIN CODE FOR ESC
            return false;
        }
        if (!m_device->write('i')) { // Upper?
            return false;
        }
        bool converted;
        auto data = m_device->read().toFloat(&converted);
        if (converted) {
            QMutexLocker lock(&m_mutex);
            m_pressure = data;
        }
        return converted;
    });

    start();
    return isRunning();
}

bool RegtronicDriver::exitEventLoop()
{
    m_mutex.lock();
    m_events.clear();
    m_mutex.unlock();
    return wait();
}

void RegtronicDriver::enqueue(std::function<bool()> event)
{
    QMutexLocker lock(&m_mutex);
    m_events.enqueue(event);
}
