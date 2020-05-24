#include "isettingswidget.h"
#include <QSettings>

ISettingsWidget::ISettingsWidget(const QString &name)
    : m_name(name)
{
}

void ISettingsWidget::setDefault(QVariant value)
{
    m_default = value;
}

QVariant ISettingsWidget::getDefault() const
{
    return m_default;
}

QVariant ISettingsWidget::load()
{
    QSettings store("SettingsWidget", m_name);
    return store.value(m_name, m_default);
}

void ISettingsWidget::store(QVariant value)
{
    QSettings store("SettingsWidget", m_name);
    store.setValue(m_name, value);
}
