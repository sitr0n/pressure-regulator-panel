#include <gtest/gtest.h>
#include <memory>
#include <regtronic_driver.h>
#include "mockexternaldevice.h"
#include <QDebug>

using ::testing::_;
using ::testing::Return;
using ::testing::AtLeast;

const QString address = "192.168.1.105";
const int threadDelay = 30;

TEST(RegtronicDriver, testOpen)
{
    auto linker = std::make_shared<MockExternalDevice>();
    auto driver = std::make_shared<RegtronicDriver>(linker);

    EXPECT_CALL(*linker, connect(address))
            .Times(1)
            .WillOnce(Return(true));
    EXPECT_CALL(*linker, close()).Times(1);
    EXPECT_TRUE(driver->open(address));
}

TEST(RegtronicDriver, testSetPressure)
{
    auto linker = std::make_shared<MockExternalDevice>();
    auto driver = std::make_shared<RegtronicDriver>(linker);
    const float bars = 3.0;

    EXPECT_CALL(*linker, connect(address))
            .Times(1)
            .WillOnce(Return(true));
    EXPECT_CALL(*linker, read())
            .Times(AtLeast(1))
            .WillRepeatedly(Return(QString::number(bars)));
    EXPECT_CALL(*linker, write(_)).Times(AtLeast(1)).WillRepeatedly(Return(true));
    EXPECT_CALL(*linker, close()).Times(1);

    driver->open(address);
    driver->setPressure(bars);
    EXPECT_FALSE(driver->wait(threadDelay));
}

TEST(RegtronicDriver, testPressure)
{
    auto linker = std::make_shared<MockExternalDevice>();
    auto driver = std::make_shared<RegtronicDriver>(linker);
    const float bars = 3.0;

    EXPECT_CALL(*linker, connect(address))
            .Times(1)
            .WillOnce(Return(true));
    EXPECT_CALL(*linker, read())
            .Times(AtLeast(1))
            .WillRepeatedly(Return(QString::number(bars)));
    EXPECT_CALL(*linker, write(_)).Times(AtLeast(1)).WillRepeatedly(Return(true));
    EXPECT_CALL(*linker, close()).Times(1);

    driver->open(address);
    driver->setPressure(bars);
    EXPECT_FALSE(driver->wait(threadDelay));
    EXPECT_EQ(driver->pressure(), bars);
}
