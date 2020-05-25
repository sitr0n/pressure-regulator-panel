#pragma once
#include "settingstextfield.h"

class NetworkAddressField : public SettingsTextField
{
    Q_OBJECT
public:
    explicit NetworkAddressField(std::shared_ptr<IDataLink<QString>> storage, QWidget *parent = nullptr);
    virtual bool save() override;
};

