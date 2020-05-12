#ifndef IDATALINK_H
#define IDATALINK_H
#include <QString>

class IDataLink
{
public:
    virtual ~IDataLink() {}
    virtual bool connect(const QString &address) = 0;
    virtual void close() = 0;
    virtual bool write(const QString &message) = 0;
    virtual QString read() = 0;
};

#endif // IDATALINK_H
