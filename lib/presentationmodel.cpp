#include "presentationmodel.h"
#include <QMutexLocker>
#include <QDebug>

PresentationModel::PresentationModel(QObject *parent)
    : QThread(parent)
{
    m_stages.push_back(&m_setup);
    m_stages.push_back(&m_events);
    m_stages.push_back(&m_teardown);
}

PresentationModel::~PresentationModel()
{
    if (!stop()) {
        emit error("PresentationModel::~PresentationModel() : Failed to stop thread");
    }
}

void PresentationModel::initialize(Action process)
{
    QMutexLocker lock(&m_mutex);
    m_setup.push_back(process);
}

void PresentationModel::subscribe(Action process)
{
    QMutexLocker lock(&m_mutex);
    process.repeatWhile([&]{
        return !cancelled();
    });
    m_events.enqueue(process);
}

void PresentationModel::dispatch(Action process)
{
    QMutexLocker lock(&m_mutex);
    m_events.enqueue(process);
}

void PresentationModel::teardown(Action process)
{
    QMutexLocker lock(&m_mutex);
    m_teardown.enqueue(process);
}

bool PresentationModel::setupPending()
{
    QMutexLocker lock(&m_mutex);
    return !m_setup.empty();
}

bool PresentationModel::eventsPending()
{
    QMutexLocker lock(&m_mutex);
    return !m_events.empty();
}

bool PresentationModel::teardownPending()
{
    QMutexLocker lock(&m_mutex);
    return !m_teardown.empty();
}

void PresentationModel::run()
{
    QMutexLocker lock(&m_mutex);
    for (auto& stage : m_stages) {
        while (!stage->isEmpty()) {
            auto routine = stage->dequeue();
            m_mutex.unlock();
            routine.execute();
            m_mutex.lock();
            if (!routine.isFinished()) {
                stage->enqueue(routine);
            }
        }
    }
}

bool PresentationModel::start() {
    m_quit = false;
    QThread::start();
    return isRunning();
}

bool PresentationModel::stop()
{
    m_quit = true;
    return wait();
}

bool PresentationModel::cancelled() const
{
    return m_quit;
}
