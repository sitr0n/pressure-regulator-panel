#pragma once
#include <QTextEdit>
#include "isettingswidget.h"
#include "../peripheral/idatalink.h"
#include <memory>

class SettingsTextField : public QTextEdit, public ISettingsWidget
{
    Q_OBJECT
public:
    explicit SettingsTextField(std::shared_ptr<IDataLink<QString>> storage, QWidget *parent = nullptr);
    virtual ~SettingsTextField() = default;

    virtual bool save();
    virtual void cancel();
    virtual bool reset();

protected:
    void notify(const QString &message);
    std::shared_ptr<IDataLink<QString>> m_storage;

};
