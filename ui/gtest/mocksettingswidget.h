#pragma once
#include <isettingswidget.h>
#include <gmock/gmock.h>

class MockSettingsWidget : public ISettingsWidget
{
public:
    //MockSettingsWidget(const QString &name) : ISettingsWidget(name) {}
    ~MockSettingsWidget() { }
    MOCK_METHOD0(save, bool());
    MOCK_METHOD0(cancel, void());
    MOCK_METHOD0(reset, bool());
};
