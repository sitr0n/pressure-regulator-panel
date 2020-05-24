#pragma once
#include <QString>

template <typename T>
class IDataLink
{
public:
    virtual ~IDataLink() { }
    virtual bool connect(const QString &address) = 0;
    virtual void close() = 0;
    virtual bool write(const T &message) = 0;
    virtual T read() = 0;
};

//template class IDataLink<int>;

