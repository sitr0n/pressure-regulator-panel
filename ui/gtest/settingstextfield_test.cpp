#include <gtest/gtest.h>
#include <settingstextfield.h>
//#include "../drivers/gtest/mockipressureregulator.h"
//using ::testing::_;
//using ::testing::Return;
//using ::testing::AtLeast;

TEST(SettingsTextField, testConstruction)
{
    auto field = std::make_shared<SettingsTextField>("test");
}

TEST(SettingsTextField, testDefault)
{
    auto field = std::make_shared<SettingsTextField>("test");
    field->setDefault(true);
    ASSERT_TRUE(field->reset());
}

TEST(SettingsTextField, testNoDefault)
{
    auto field = std::make_shared<SettingsTextField>("test");
    ASSERT_FALSE(field->reset());
}
