#pragma once

class IPressureRegulator
{
public:
    virtual ~IPressureRegulator() {}
    virtual void setPressure(float bar) = 0;
    virtual float pressure() = 0;
};
