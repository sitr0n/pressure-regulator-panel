#pragma once
#include "../ipressureregulator.h"
#include <gmock/gmock.h>

class MockIPressureRegulator : public IPressureRegulator
{
public:
    ~MockIPressureRegulator() { }
    MOCK_METHOD1(setPressure, void(float bar));
    MOCK_METHOD0(pressure, float());
};
