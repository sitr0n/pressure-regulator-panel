#pragma once
#include <QWidget>
#include "../drivers/ipressureregulator.h"
#include <memory>
#include <QLCDNumber>
#include <QPushButton>
#include <QTimer>
#include <vector>
#if defined(__clang__) || defined (__GNUC__)
# define ATTRIBUTE_NO_SANITIZE_ADDRESS __attribute__((no_sanitize_address))
#else
# define ATTRIBUTE_NO_SANITIZE_ADDRESS
#endif

class PressurePanel : public QWidget
{
    Q_OBJECT
public:
    PressurePanel(std::shared_ptr<IPressureRegulator> regulator, QWidget *parent = nullptr);
    void addButton(float bars);
    std::vector<QPushButton*> getButtons() const;
    float getPressure() const;

protected:
    void refresh();
    QPushButton *createPressureButton(float bars);

private:
    std::shared_ptr<IPressureRegulator> m_regulator;
    QLCDNumber *m_pressureDisplay;
    std::vector<QPushButton*> m_buttons;
    QTimer m_refresher;

    const int FONT_SIZE = 24;
    const int REFRESH_RATE = 500;
};
