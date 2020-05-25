#include <gtest/gtest.h>
#include <networkaddressfield.h>
#include "../peripheral/gtest/mockdatalink.h"
//#include "../drivers/gtest/mockipressureregulator.h"

using ::testing::_;
using ::testing::Return;
//using ::testing::AtLeast;

TEST(NetworkAddressField, testSave)
{
    auto storage = std::make_shared<MockDataLink<QString>>();
    auto field = std::make_shared<NetworkAddressField>(storage);

    field->setText("1.1.1.1");
    for (const auto& success : {false, true}) {
        EXPECT_CALL(*storage, write(_)).Times(1).WillOnce(Return(success));
        ASSERT_EQ(field->save(), success);
    }
}

TEST(NetworkAddressField, testFaultyInput)
{
    auto storage = std::make_shared<MockDataLink<QString>>();
    auto field = std::make_shared<NetworkAddressField>(storage);

    EXPECT_CALL(*storage, write(_)).Times(0);
    for (const auto& input : {"abc", "1.1.1.a", "1.a.1.1", "1.1.1.1.1"}) {
        field->setText(input);
        ASSERT_FALSE(field->save());
    }
}
