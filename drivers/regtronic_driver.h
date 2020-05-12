#pragma once
//#include "presentationmodel.h"
#include "../lib/presentationmodel.h"
#include "ipressureregulator.h"
#include "idatalink.h"
#include <memory>
#include <QMutex>

namespace ASCII2 {
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
}

class RegtronicDriver : public PresentationModel, public IPressureRegulator
{
    Q_OBJECT
public:
    explicit RegtronicDriver(std::shared_ptr<IDataLink> linker, QObject *parent = nullptr);
    virtual ~RegtronicDriver();
    bool open(const QString &address);
    bool close();

    void setPressure(float bar);
    float pressure();

protected:
    bool startModel();

private:
    std::shared_ptr<IDataLink> m_linker;
    QString m_address;
    QMutex m_mutex;

    float m_pressure{};
};
