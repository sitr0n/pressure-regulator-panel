#include "settingsform.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSpacerItem>
#include <QMessageBox>

SettingsForm::SettingsForm(QWidget *parent)
    : QWidget(parent)
    , m_resetButton(new QPushButton("Reset", this))
    , m_applyButton(new QPushButton("Apply", this))
    , m_cancelButton(new QPushButton("Cancel", this))
{
    auto form = new QVBoxLayout(this);
    auto wrapper = new QWidget(this);
    wrapper->setLayout(&m_form);
    form->addWidget(wrapper);

    auto buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(m_resetButton);
    buttonLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum));
    buttonLayout->addWidget(m_applyButton);
    buttonLayout->addWidget(m_cancelButton);
    auto buttonBar = new QWidget(this);
    buttonBar->setLayout(buttonLayout);

}

QPushButton *SettingsForm::resetButton() const
{
    return m_resetButton;
}

QPushButton *SettingsForm::applyButton() const
{
    return m_applyButton;
}

QPushButton *SettingsForm::cancelButton() const
{
    return m_cancelButton;
}

void SettingsForm::addField(std::shared_ptr<ISettingsWidget> field)
{
    m_fields.push_back(field);
}
