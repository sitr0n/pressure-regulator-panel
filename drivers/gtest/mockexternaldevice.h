#pragma once
#include <externaldevice.h>
#include <gmock/gmock.h>

class MockExternalDevice : public ExternalDevice
{
public:
    ~MockExternalDevice() { }
    MOCK_METHOD1(connect, bool(const QString &address));
    MOCK_METHOD0(close, void());
    MOCK_METHOD1(write, bool(const QString &message));
    MOCK_METHOD0(read, QString());
};
