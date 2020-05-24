#include <gtest/gtest.h>
#include <QApplication>
#include <drivers/gtest/regtronicdriver_test.cpp>
#include <lib/gtest/presentationmodel_test.cpp>
#include <peripheral/gtest/qstorage_test.cpp>
#include <ui/gtest/pressurepanel_test.cpp>
#include <ui/gtest/networkaddressform_test.cpp>
#include <ui/gtest/isettingswidget_test.cpp>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
