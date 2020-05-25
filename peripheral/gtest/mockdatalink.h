#pragma once
//#include <idatalink.h>
#include "../idatalink.h"
#include <gmock/gmock.h>

template <typename T>
class MockDataLink : public IDataLink<T>
{
public:
    ~MockDataLink() { }
    MOCK_METHOD1(connect, bool(const QString &address));
    MOCK_METHOD0(close, void());
    MOCK_METHOD1(write, bool(const T &message));
    MOCK_METHOD0(read, T());
};
