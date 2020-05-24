#include <gtest/gtest.h>
#include <memory>
#include <qstorage.h>
#include <QString>
#include <string>

TEST(QStorage, testInteger)
{
    auto device = std::make_shared<QStorage<int>>("test");
    device->connect("integer");
    for (const int &integer : {42, 43, 44}) {
        ASSERT_TRUE(device->write(integer));
        ASSERT_EQ(device->read(), integer);
    }
}

TEST(QStorage, testFloatingPoint)
{
    auto device = std::make_shared<QStorage<float>>("test");
    device->connect("floatingpoint");
    for (const float &floatingpoint : {12.3, 45.6, 78.9}) {
        ASSERT_TRUE(device->write(floatingpoint));
        ASSERT_EQ(device->read(), floatingpoint);
    }
}

TEST(QStorage, testDoublePrecision)
{
    auto device = std::make_shared<QStorage<double>>("test");
    device->connect("doubleprecision");
    for (const double &doubleprecision : {12.3, 45.6, 78.9}) {
        ASSERT_TRUE(device->write(doubleprecision));
        ASSERT_EQ(device->read(), doubleprecision);
    }
}

TEST(QStorage, testBoolean)
{
    auto device = std::make_shared<QStorage<float>>("test");
    device->connect("boolean");
    for (const bool &boolean : {false, true}) {
        ASSERT_TRUE(device->write(boolean));
        ASSERT_EQ(device->read(), boolean);
    }
}

TEST(QStorage, testString)
{
    auto device = std::make_shared<QStorage<std::string>>("test");
    device->connect("string");
    for (const std::string &string : {"test1", "test2", "test3"}) {
        ASSERT_TRUE(device->write(string));
        ASSERT_EQ(device->read(), string);
    }
}

TEST(QStorage, testQString)
{
    auto device = std::make_shared<QStorage<QString>>("test");
    device->connect("qstring");
    for (const QString &qstring : {"test1", "test2", "test3"}) {
        ASSERT_TRUE(device->write(qstring));
        ASSERT_EQ(device->read(), qstring);
    }
}
