#ifndef REGTRONICDRIVER_H
#define REGTRONICDRIVER_H

//#include "commline.h"
#include <QObject>
#include <QTextStream>

namespace Ui {
class PressureControl;
}

namespace Pressure {
const int BYTE_RANGE = 5;
}

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

class RegtronicDriver
{

public:
    RegtronicDriver(QTextStream *out);
    ~RegtronicDriver();
    bool start(QString address);
    void setPressure(int setpoint);
    bool getPressure(int &out);

    //Implement restart function for when address has changed while running..

private:
    //CommLine device;
    QTextStream *m_out;

    bool open(QString address);
    bool isReady();
    void writeNumber(int number, int bytes);
    bool isRunning;
};

#endif // REGTRONICDRIVER_H
