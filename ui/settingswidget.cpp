//#include "settingswidget.h"
//#include <QSettings>
//#include <QToolTip>

//SettingsWidget::SettingsWidget(const QString &name, QWidget *parent)
//    : QWidget(parent)
//    , m_name(name)
//{

//}

//void SettingsWidget::save()
//{

//}

//void SettingsWidget::cancel()
//{

//}

//bool SettingsWidget::reset()
//{

//}

//void SettingsWidget::setDefault(QVariant value)
//{
//    m_default = value;
//}

//QVariant SettingsWidget::load()
//{
//    QSettings store("SettingsWidget", m_name);
//    return store.value(m_name, m_default);
//}

//void SettingsWidget::save(QVariant value)
//{
//    QSettings store("SettingsWidget", m_name);
//    store.setValue(m_name, value);
//}

//void SettingsWidget::alert(const QString &message)
//{
//    setStyleSheet("color: #FF0000");
//    notify(message);
//}

//void SettingsWidget::notify(const QString &message)
//{
//    QToolTip::showText(mapToGlobal(QPoint(0, 0)), message);
//}
