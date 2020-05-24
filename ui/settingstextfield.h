#pragma once
#include "isettingswidget.h"
#include <QTextEdit>

class SettingsTextField : public QTextEdit, public ISettingsWidget
{
    Q_OBJECT
public:
    explicit SettingsTextField(const QString &name, QWidget *parent = nullptr);
    virtual ~SettingsTextField() = default;

    virtual void save();
    virtual void cancel();
    virtual bool reset();

protected:
    void notify(const QString &message);
};
