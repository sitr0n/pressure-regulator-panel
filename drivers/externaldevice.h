#ifndef EXTERNALDEVICE_H
#define EXTERNALDEVICE_H
#include <QString>

class ExternalDevice
{
public:
    virtual ~ExternalDevice() {}
    virtual bool connect(const QString &address, int port) = 0;
    virtual void close() = 0;
    virtual bool write(const QString &message) = 0;
    virtual bool read(QString &message) = 0;
};

#endif // EXTERNALDEVICE_H
