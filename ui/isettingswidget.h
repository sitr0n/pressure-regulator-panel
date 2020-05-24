#pragma once
#include <QVariant>

class ISettingsWidget
{
public:
    ISettingsWidget(const QString &name);
    virtual ~ISettingsWidget() = default;

    virtual void save() = 0;
    virtual void cancel() = 0;
    virtual bool reset() = 0;

    void setDefault(QVariant value);
    QVariant getDefault() const;

protected:
    QVariant load();
    void store(QVariant value);

private:
    QString m_name;
    QVariant m_default;
};
