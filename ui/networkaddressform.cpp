#include "networkaddressform.h"
#include <QRegExp>

NetworkAddressForm::NetworkAddressForm(const QString &name, QWidget *parent)
    : SettingsTextField(name, parent)
{
    setPlaceholderText("Enter IP Address here...");

    connect(this, &QTextEdit::textChanged, [this]{
        setStyleSheet("color: #000000");
    });
}

void NetworkAddressForm::save()
{
    const QRegExp validator = QRegExp("(\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1,3})");
    auto value = toPlainText();
    if (validator.exactMatch(value)) {
        store(value);
    } else {
        setStyleSheet("color: #FF0000");
        notify("Enter IP Addresses only!");
    }
}
