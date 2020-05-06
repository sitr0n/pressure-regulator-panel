#include "pressurepanel.h"
#include <QVBoxLayout>

PressurePanel::PressurePanel(std::shared_ptr<IPressureRegulator> regulator, QWidget *parent)
    : QWidget(parent)
    , m_regulator(regulator)
    , m_pressureDisplay(new QLCDNumber(6, this))
{
    setMinimumSize(500, 400);
    auto form = new QVBoxLayout(this);
    form->addWidget(m_pressureDisplay);
    m_pressureDisplay->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

    connect(&m_refresher, &QTimer::timeout, this, &PressurePanel::refresh);
    m_refresher.start(REFRESH_RATE);
    refresh();
}

void PressurePanel::addButton(float bars)
{
    auto button = createPressureButton(bars);
    m_buttons.emplace_back(button);
    layout()->addWidget(button);
}

std::vector<QPushButton*> PressurePanel::getButtons() const
{
    return m_buttons;
}

float PressurePanel::getPressure() const
{
    return m_pressureDisplay->value();
}

void PressurePanel::refresh()
{
    m_pressureDisplay->display(QString::number(m_regulator->pressure(), 'f', 4));
}

QPushButton *PressurePanel::createPressureButton(float bars)
{
    auto button = new QPushButton(QString("%0 bar").arg(bars), this);
    auto font = button->font();
    font.setPointSize(FONT_SIZE);
    button->setFont(font);
    button->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    button->setFocusPolicy(Qt::NoFocus);

    connect(button, &QPushButton::clicked, [this, bars]{
        m_regulator->setPressure(bars);
    });
    return button;
}
