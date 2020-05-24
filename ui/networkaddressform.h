#pragma once
#include "settingstextfield.h"

class NetworkAddressForm : public SettingsTextField
{
    Q_OBJECT
public:
    explicit NetworkAddressForm(const QString &name, QWidget *parent = nullptr);

    virtual void save() override;

};

