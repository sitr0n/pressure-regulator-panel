#pragma once
#include <idatalink.h>
#include <gmock/gmock.h>

class MockDataLink : public IDataLink
{
public:
    ~MockDataLink() { }
    MOCK_METHOD1(connect, bool(const QString &address));
    MOCK_METHOD0(close, void());
    MOCK_METHOD1(write, bool(const QString &message));
    MOCK_METHOD0(read, QString());
};
