#pragma once
#include <QWidget>
#include <QPushButton>
#include <memory>
#include <isettingswidget.h>
#include <QFormLayout>

class SettingsForm : public QWidget
{
    Q_OBJECT
public:
    explicit SettingsForm(QWidget *parent = nullptr);
    QPushButton* resetButton() const;
    QPushButton* applyButton() const;
    QPushButton* cancelButton() const;

    void addField(std::shared_ptr<ISettingsWidget> field);

private:
    QFormLayout m_form;
    QPushButton *m_resetButton;
    QPushButton *m_applyButton;
    QPushButton *m_cancelButton;
    std::vector<std::shared_ptr<ISettingsWidget>> m_fields;
};
