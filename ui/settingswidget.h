#pragma once
#include <QWidget>
#include <QVariant>

//class SettingsWidget : public QWidget, public ISettingsWidget
//{
//    Q_OBJECT
//public:
//    explicit SettingsWidget(const QString &name, QWidget *parent = nullptr);
//    virtual ~SettingsWidget() = default;

//    virtual void save();
//    virtual void cancel();
//    virtual bool reset();
//    void setDefault(QVariant value);

//protected:
//    QVariant load();
//    void save(QVariant value);

//    void alert(const QString &message);
//    void notify(const QString &message);


//private:
//    QString m_name;
//    QVariant m_default;
//    const QString TAG = "SettingsWidget";
//};
