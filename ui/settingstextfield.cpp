#include "settingstextfield.h"
#include <QToolTip>

SettingsTextField::SettingsTextField(const QString &name, QWidget *parent)
    : QTextEdit(parent)
    , ISettingsWidget(name)
{
    setPlaceholderText("Enter text here...");
}

void SettingsTextField::save()
{
    store(QVariant(toPlainText()));
}

void SettingsTextField::cancel()
{
    setText(load().toString());
}

bool SettingsTextField::reset()
{
    if (!getDefault().isNull()) {
        setText(getDefault().toString());
    } else {
        notify("No default value found");
    }
    return getDefault().isNull();
}

void SettingsTextField::notify(const QString &message)
{
    QToolTip::showText(mapToGlobal(QPoint(0, 0)), message);
}
