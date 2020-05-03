#ifndef COMLINEDEVICE_H
#define COMLINEDEVICE_H

#include "externaldevice.h"
//#include "commline.h"
#include <vector>

class ComlineDevice : public ExternalDevice
{
public:
    ComlineDevice();
    bool connect(const QString &address);
    void close();
    bool write(const QString &message);
    bool write(const QChar &token);
    QString read();

    void setBaud(const int rate);

protected:
    std::vector<unsigned char> createAscii(const QString &text);

private:
    int m_baudRate;
    //CommLine m_device;
};

#endif // COMLINEDEVICE_H
