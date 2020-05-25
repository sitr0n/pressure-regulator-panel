#include "networkaddressfield.h"
#include <QRegExp>

NetworkAddressField::NetworkAddressField(std::shared_ptr<IDataLink<QString>> storage, QWidget *parent)
    : SettingsTextField(storage, parent)
{
    setPlaceholderText("Enter IP Address here...");

    connect(this, &QTextEdit::textChanged, [this]{
        setStyleSheet("color: #000000");
    });
}

bool NetworkAddressField::save()
{
    const QRegExp validator = QRegExp("(\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1,3})");
    auto value = toPlainText();
    if (validator.exactMatch(value)) {
        return m_storage->write(value);
    } else {
        setStyleSheet("color: #FF0000");
        notify("Enter IP Addresses only!");
        return false;
    }
}
