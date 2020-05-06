#include <gtest/gtest.h>
#include <pressurepanel.h>
#include "../drivers/gtest/mockipressureregulator.h"

using ::testing::_;
using ::testing::Return;
using ::testing::AtLeast;

TEST(PressurePanel, testDisplay)
{
    auto driver = std::make_shared<MockIPressureRegulator>();
    const float pressure = 3.0;
    EXPECT_CALL(*driver, pressure()).Times(AtLeast(1)).WillRepeatedly(Return(pressure));
    auto panel = std::make_shared<PressurePanel>(driver);

    ASSERT_EQ(panel->getPressure(), pressure);
}

TEST(PressurePanel, testAddButton)
{
    auto driver = std::make_shared<MockIPressureRegulator>();
    EXPECT_CALL(*driver, pressure()).Times(AtLeast(1)).WillRepeatedly(Return(0));
    auto panel = std::make_shared<PressurePanel>(driver);
    const size_t NUM_BUTTONS = 12;
    for (int iota = 0; iota < NUM_BUTTONS; ++iota) {
        panel->addButton(iota);
    }
    ASSERT_EQ(panel->getButtons().size(), NUM_BUTTONS);
}

TEST(PressurePanel, testClickButton)
{
    auto driver = std::make_shared<MockIPressureRegulator>();
    EXPECT_CALL(*driver, pressure()).Times(AtLeast(1)).WillRepeatedly(Return(0));
    auto panel = std::make_shared<PressurePanel>(driver);
    for (const auto& bar : {1.2, 3.4, 5.6, 7.8}) {
        panel->addButton(bar);
        EXPECT_CALL(*driver, setPressure(bar)).Times(1);
    }

    for (const auto& button : panel->getButtons()) {
        button->click();
    }
}
