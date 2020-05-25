#include <gtest/gtest.h>
#include <isettingswidget.h>
#include <mocksettingswidget.h>
//using ::testing::_;
//using ::testing::Return;
//using ::testing::AtLeast;



//TEST(ISettingsWidget, testConstruction)
//{
//    auto widget = std::make_shared<MockSettingsWidget>("test");
//}

//TEST(ISettingsWidget, testDefault)
//{
//    auto widget = std::make_shared<MockSettingsWidget>("test");

//    const float value = 12.3;
//    widget->setDefault(value);
//    bool valid;
//    ASSERT_EQ(widget->getDefault().toFloat(&valid), value);
//    EXPECT_TRUE(valid);
//}

//TEST(SettingsWidget, testSave)
//{
//    auto widget = std::make_shared<SettingsWidget>("test");
//    //widget->save(2);
//}

//TEST(PressurePanel, testClickButton)
//{
//    auto driver = std::make_shared<MockIPressureRegulator>();
//    EXPECT_CALL(*driver, pressure()).Times(AtLeast(1)).WillRepeatedly(Return(0));
//    auto panel = std::make_shared<PressurePanel>(driver);
//    for (const auto& bar : {1.2, 3.4, 5.6, 7.8}) {
//        panel->addButton(bar);
//        EXPECT_CALL(*driver, setPressure(bar)).Times(1);
//    }

//    for (const auto& button : panel->getButtons()) {
//        button->click();
//    }
//}

// Lower og higher temperature
// Min og max accelerometer value
// Max depth offset
// slope
