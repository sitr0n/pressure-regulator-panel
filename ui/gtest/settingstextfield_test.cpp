#include <gtest/gtest.h>
#include <settingstextfield.h>
#include "../peripheral/gtest/mockdatalink.h"
#include <QString>

//using ::testing::_;
using ::testing::Return;
//using ::testing::AtLeast;

TEST(SettingsTextField, testConstruction)
{
    auto storage = std::make_shared<MockDataLink<QString>>();
    auto field = std::make_shared<SettingsTextField>(storage);
}

TEST(SettingsTextField, testSave)
{
    auto storage = std::make_shared<MockDataLink<QString>>();
    auto field = std::make_shared<SettingsTextField>(storage);

    const QString input = "test input";
    field->setText(input);
    EXPECT_CALL(*storage, write(input)).Times(1);
    field->save();
}

TEST(SettingsTextField, testCancel)
{
    auto storage = std::make_shared<MockDataLink<QString>>();
    auto field = std::make_shared<SettingsTextField>(storage);

    const QString stored = "stored value";
    field->setText("Wrong input");
    EXPECT_CALL(*storage, read()).Times(1).WillOnce(Return(stored));
    field->cancel();
    ASSERT_EQ(field->toPlainText(), stored);
}

//TEST(SettingsTextField, testReset)
//{
//    auto storage = std::make_shared<MockDataLink<QString>>();
//    auto field = std::make_shared<SettingsTextField>(storage);

//    const QString stored = "default value";
//    field->setText("Wrong input");
//    EXPECT_CALL(*storage, read()).Times(1).WillOnce(Return(stored));
//    field->reset();
//    ASSERT_EQ(field->toPlainText(), stored);
//}

//TEST(SettingsTextField, testDefault)
//{
//    auto field = std::make_shared<SettingsTextField>("test");
//    field->setDefault(true);
//    ASSERT_TRUE(field->reset());
//}

//TEST(SettingsTextField, testNoDefault)
//{
//    auto field = std::make_shared<SettingsTextField>("test");
//    ASSERT_FALSE(field->reset());
//}
