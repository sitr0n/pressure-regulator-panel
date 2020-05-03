#ifndef REGTRONICDRIVER_H
#define REGTRONICDRIVER_H
#include "externaldevice.h"
#include "ipressureregulator.h"
#include <QThread>
#include <QQueue>
#include <memory>
#include <QMutex>
#include <functional>

namespace ASCII {
const unsigned char ESC = 0x1B;
const unsigned char P = 0x50;
const unsigned char c = 0x63;
const unsigned char d = 0x64;
const unsigned char b = 0x62;
const unsigned char E = 0x45;
const unsigned char e = 0x64;
const unsigned char O = 0x4F;
const unsigned char p = 0x70;
const unsigned char i = 0x69;
const unsigned char c0 = 0x30;
const unsigned char c1 = 0x31;
const unsigned char c2 = 0x32;
const unsigned char c3 = 0x33;
const unsigned char c4 = 0x34;
const unsigned char c5 = 0x35;
const unsigned char c6 = 0x36;
const unsigned char c7 = 0x37;
const unsigned char c8 = 0x38;
const unsigned char c9 = 0x39;
}

class RegtronicDriver : public QThread, public IPressureRegulator
{
    Q_OBJECT
public:
    RegtronicDriver(std::shared_ptr<ExternalDevice> device);
    ~RegtronicDriver();
    bool open(const QString &address);

    void setPressure(float bar);
    float pressure();

signals:
    void error(const QString &message);

protected:
    virtual void run() override;
    bool startEventLoop();
    bool exitEventLoop();
    void enqueue(std::function<bool()> event);

private:
    std::shared_ptr<ExternalDevice> m_device;
    float m_pressure;

    QQueue<std::function<bool()>> m_events;
    QMutex m_mutex;

    QString m_address;
};

#endif // REGTRONICDRIVER_H
