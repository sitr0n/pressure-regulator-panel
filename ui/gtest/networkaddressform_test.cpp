#include <gtest/gtest.h>
#include <networkaddressform.h>
//#include "../drivers/gtest/mockipressureregulator.h"

//using ::testing::_;
//using ::testing::Return;
//using ::testing::AtLeast;

TEST(NetworkAddressForm, testConstruction)
{
    auto form = std::make_shared<NetworkAddressForm>("test");


    ASSERT_EQ(1,1);

    //const float pressure = 3.0;
    //EXPECT_CALL(*driver, pressure()).Times(AtLeast(1)).WillRepeatedly(Return(pressure));
    //auto panel = std::make_shared<PressurePanel>(driver);

    //ASSERT_EQ(panel->getPressure(), pressure);
}
