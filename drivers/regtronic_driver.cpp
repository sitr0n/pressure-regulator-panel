#include "regtronic_driver.h"
#include <QString>
#define REGTRONIC_BAUD 2400
#define MAX_PRESSURE 99999
#define UPDATE_FREQ 500
#define MAX_SAMPLING_INTERVAL 9999999 // Find QTimer limit
#define MIN_SAMPLING_INTERVAL 100 // Find regtronic regulator limit

RegtronicDriver::RegtronicDriver(QTextStream *out) :
    m_out(out),
    isRunning(false)
{
}

RegtronicDriver::~RegtronicDriver() try
{
    //device.Close();
} catch (...) { }

bool RegtronicDriver::start(QString address)
{
    //return true;
    if (isRunning) {
        return true;
    } else {
        isRunning = open(address);
        return isRunning;
    }
}

bool RegtronicDriver::open(QString address) try
{
    //device.Open(address.toLatin1().data(), REGTRONIC_BAUD, true); // What happens if i set _server = true
    //device.Close();
    return isReady();
} catch (...) {
    //*m_out << QString("Regtronic was not found on the given address");
    return false;
}

bool RegtronicDriver::isReady() try
{
//    *m_out << "in isReady--------";
//    bool is_rdy = false;
//    if (device.Opened()) {
//        *m_out << "device is opened??--------";
//        is_rdy = true;
//    } else {
//        *m_out << QString("Regtronic communication is closed");
//    }
    //return is_rdy;
    return false; // Temp
} catch (...) {
    //*m_out << QString("Regtronic is not connected");
    return false;
}

void RegtronicDriver::setPressure(int setpoint) try
{
    if (isRunning) {
        //device.Write(&ASCII::ESC, sizeof(unsigned char)); // Prepare device to receive command
        //device.Write(&ASCII::P, sizeof(unsigned char)); // Specify command type
        writeNumber(setpoint, Pressure::BYTE_RANGE);
    }

} catch (...) {
    //*m_out << QString("Rare exception while setPressure! setpoint:%1;isRunning:%2").arg(setpoint).arg(isRunning);
}

bool RegtronicDriver::getPressure(int &out) try
{
    //device.Write(&ASCII::ESC, sizeof(unsigned char));
    //device.Write(&ASCII::i, sizeof(unsigned char));
    unsigned char input = '0';
    while (input != ASCII::i) { // Implement watchdog condition
        //*m_out << "reading like a mad man";
        //input = device.NextByte();
    }
    int pressure = 0;
    int power_factor = 10000;
    for (int i = Pressure::BYTE_RANGE; 0 < i; --i) {
        //input = device.NextByte();
        int digit = input - '0';
        if (digit < 0 || 9 < digit) {
            //*m_out << QString("Error while reading pressure! Got %1 as the digit in byte position %2...").arg(digit).arg(i);
            return false;
        }
        pressure += digit * power_factor;
        power_factor /= 10;
    }
    out = pressure;
    return true;
} catch (...) {
    //*m_out << QString("Exception while reading pressure");
    out = 0;
    return false;
}

void RegtronicDriver::writeNumber(int number, int bytes) try
{
    if (bytes < 1) {
        return;
    }
    int divisor = 1;
    for (int i = 0; i < (bytes - 1); ++i) {
        divisor *= 10;
    }
    unsigned char digit;
    switch ((int) (number / divisor) % 10) {
    case 0 :
        digit = ASCII::c0;
        break;
    case 1 :
        digit = ASCII::c1;
        break;
    case 2 :
        digit = ASCII::c2;
        break;
    case 3 :
        digit = ASCII::c3;
        break;
    case 4 :
        digit = ASCII::c4;
        break;
    case 5 :
        digit = ASCII::c5;
        break;
    case 6 :
        digit = ASCII::c6;
        break;
    case 7 :
        digit = ASCII::c7;
        break;
    case 8 :
        digit = ASCII::c8;
        break;
    case 9 :
        digit = ASCII::c9;
        break;
    }
    //device.Write(&digit, sizeof(unsigned char));
    writeNumber(number, bytes - 1);
} catch (...) {
    //*m_out << QString("Exception while writing value to Regtronic");
}
