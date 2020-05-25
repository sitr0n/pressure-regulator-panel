#include "settingstextfield.h"
#include <QToolTip>

SettingsTextField::SettingsTextField(std::shared_ptr<IDataLink<QString>> storage, QWidget *parent)
    : QTextEdit(parent)
    , ISettingsWidget()
    , m_storage(storage)
{
    setPlaceholderText("Enter text here...");
}

bool SettingsTextField::save()
{
    auto saved = m_storage->write(toPlainText());
    if (!saved) {
        notify("Failed to save data");
    }
    return saved;
}

void SettingsTextField::cancel()
{
    setText(m_storage->read());
}

bool SettingsTextField::reset()
{
//    if (!getDefault().isNull()) {
//        setText(getDefault().toString());
//    } else {
//        notify("No default value found");
//    }
//    return getDefault().isNull();
}

void SettingsTextField::notify(const QString &message)
{
    QToolTip::showText(mapToGlobal(QPoint(0, 0)), message);
}
