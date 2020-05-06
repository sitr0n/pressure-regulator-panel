#include <QApplication>
#include <memory>
#include <drivers/comlinedevice.h>
#include <drivers/regtronic_driver.h>
#include <ui/pressurepanel.h>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    auto linker = std::make_shared<ComlineDevice>();
    auto driver = std::make_shared<RegtronicDriver>(linker);
    auto panel = std::make_shared<PressurePanel>(driver);

    for (const auto& bar : {4, 2, 1}){
        panel->addButton(bar);
    }
    panel->show();

    return a.exec();
}
