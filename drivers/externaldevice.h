#ifndef EXTERNALDEVICE_H
#define EXTERNALDEVICE_H
#include <QString>

class ExternalDevice
{
public:
    virtual ~ExternalDevice() {}
    virtual bool connect(const QString &address) = 0;
    virtual void close() = 0;
    virtual bool write(const QString &message) = 0;
    virtual bool write(const QChar &token) = 0;
    virtual QString read() = 0;
};

#endif // EXTERNALDEVICE_H
