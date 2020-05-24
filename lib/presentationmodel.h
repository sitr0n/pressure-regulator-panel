#pragma once

#include <QThread>
#include <QMutex>
#include <QQueue>
#include <QMap>
#include <memory>
#include <functional>
#include <atomic>
#include <QDebug>

struct Action
{
public:
    Action(std::function<bool()> process) : m_process(process) {}
    void execute() {
        m_finished = m_process();
        if (!m_finished) {
            ++m_failedRuns;
        }
    }
    bool isFinished() const { return m_repeating ? !m_condition() : m_finished; }
    void repeat(bool enable) { m_repeating = enable; }
    void repeatWhile(std::function<bool()> condition) {
        m_repeating = true;
        m_condition = condition;
    }

private:
    std::function<bool()> m_process;
    std::function<bool()> m_condition;
    bool m_finished{false};
    bool m_repeating{false};
    int m_failedRuns{0};
};

class PresentationModel : public QThread
{
    Q_OBJECT
public:
    explicit PresentationModel(QObject *parent = nullptr);
    ~PresentationModel() override;

    void initialize(Action process);
    void subscribe(Action process);
    void dispatch(Action process);
    void teardown(Action process);

    bool setupPending();
    bool eventsPending();
    bool teardownPending();

signals:
    void error(const QString &message);

protected:
    virtual void run() override;
    bool start();
    bool stop();

private:
    bool cancelled() const;
    std::atomic_bool m_quit{false};

    QMutex m_mutex;

    std::vector<QQueue<Action>*> m_stages;
    QQueue<Action> m_setup;
    QQueue<Action> m_events;
    QQueue<Action> m_teardown;

};
