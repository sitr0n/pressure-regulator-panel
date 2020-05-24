#include <gtest/gtest.h>
#include <memory>
#include <regtronic_driver.h>
//#include "mockdatalink.h"
#include "../peripheral/gtest/mockdatalink.h"
#include <QDebug>

using ::testing::_;
using ::testing::Return;
using ::testing::AtLeast;

const QString address2 = "192.168.1.105";
//const int threadDelay = 30;

TEST(RegtronicDriver, testConstruct)
{
    auto linker = std::make_shared<MockDataLinker<QString>>();
    auto driver = std::make_shared<RegtronicDriver>(linker);

    //EXPECT_EQ(driver->setupPending(), 1);
    //EXPECT_EQ(driver->teardownPending(), 1);
}

TEST(RegtronicDriver, testOpen)
{
    auto linker = std::make_shared<MockDataLinker<QString>>();
    auto driver = std::make_shared<RegtronicDriver>(linker);

    EXPECT_CALL(*linker, connect(address2)).Times(1).WillOnce(Return(true));
    EXPECT_CALL(*linker, close()).Times(1);

    EXPECT_TRUE(driver->open(address2));
    driver->wait(10);
    EXPECT_TRUE(driver->close());
}

TEST(RegtronicDriver, testSetPressure)
{
    auto linker = std::make_shared<MockDataLinker<QString>>();
    auto driver = std::make_shared<RegtronicDriver>(linker);
    const float bars = 3.0;

    EXPECT_CALL(*linker, connect(address2))
            .Times(1)
            .WillOnce(Return(true));
    EXPECT_CALL(*linker, read())
            .Times(AtLeast(1))
            .WillRepeatedly(Return(QString::number(bars)));
    EXPECT_CALL(*linker, write(_)).Times(AtLeast(1)).WillRepeatedly(Return(true));
    EXPECT_CALL(*linker, close()).Times(1);

    driver->open(address2);
    driver->setPressure(bars);
    EXPECT_FALSE(driver->wait(30));
}

TEST(RegtronicDriver, testPressure)
{
    auto linker = std::make_shared<MockDataLinker<QString>>();
    auto driver = std::make_shared<RegtronicDriver>(linker);
    const float bars = 3.0;

    EXPECT_CALL(*linker, connect(address2))
            .Times(1)
            .WillOnce(Return(true));
    EXPECT_CALL(*linker, read())
            .Times(AtLeast(1))
            .WillRepeatedly(Return(QString::number(bars)));
    EXPECT_CALL(*linker, write(_)).Times(AtLeast(1)).WillRepeatedly(Return(true));
    EXPECT_CALL(*linker, close()).Times(1);

    driver->open(address2);
    driver->setPressure(bars);
    EXPECT_FALSE(driver->wait(30));
    EXPECT_EQ(driver->pressure(), bars);
}
