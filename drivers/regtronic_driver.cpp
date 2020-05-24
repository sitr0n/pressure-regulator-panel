#include "regtronic_driver.h"
#include <QMutexLocker>

RegtronicDriver::RegtronicDriver(std::shared_ptr<IDataLink<QString>> linker, QObject *parent)
    : PresentationModel(parent)
    , m_linker(linker)
{
    initialize(Action([this]{
        m_linker->connect(m_address);
        return true;
    }));

    teardown(Action([this]{
        m_linker->close();
        return true;
    }));
}

RegtronicDriver::~RegtronicDriver()
{

}

bool RegtronicDriver::open(const QString &address)
{
    if (!stop()) {
        emit error(QString("RegtronicDriver::open(%0) : Failed to stop previous model").arg(address));
    }
    m_address = address;
    return startModel();
}

bool RegtronicDriver::close()
{
    return PresentationModel::stop();
}

void RegtronicDriver::setPressure(float bar)
{
    subscribe(Action([&, bar]{
        return (m_linker->write(QString(ASCII2::ESC)) && m_linker->write(QString(ASCII2::P)) && m_linker->write(QString::number(bar)));
    }));
}

float RegtronicDriver::pressure()
{
    QMutexLocker lock(&m_mutex);
    return m_pressure;
}

bool RegtronicDriver::startModel()
{
    subscribe(Action([&]{
        if (!m_linker->write(QString(ASCII2::ESC))) { // Ascii symbol for ESC - Signals the start of a command
            return false;
        }
        if (!m_linker->write(QString(ASCII2::i))) { // Capital?
            return false;
        }
        bool converted;
        auto data = m_linker->read().toFloat(&converted);
        QMutexLocker lock(&m_mutex);
        if (converted) {
            m_pressure = data;
        }
        return true;
    }));
    //start();
    //return isRunning();
    return PresentationModel::start();
}

