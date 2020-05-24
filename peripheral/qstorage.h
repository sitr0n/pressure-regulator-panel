#pragma once
#include "idatalink.h"
#include <type_traits>
#include <QSettings>
#include <QString>
#include <string>

template <typename T>
class QStorage : public IDataLink<T>
{
public:
    QStorage(const QString &name) : IDataLink<T>(), m_name(name) {}
    bool connect(const QString &address) {
        m_address = address;
    }
    void close() {
        m_address.clear();
    }
    bool write(const T &value){
        if (m_address.isEmpty()) {
            return false;
        }
        QSettings storage("QStorage", m_name);
        storage.setValue(m_address, value);
        return true;
    }
    T read(){
        QSettings storage("QStorage", m_name);
        return qvariant_cast<T>(storage.value(m_address));
    }

private:
    QString m_name;
    QString m_address;
};

// Specialized behavior for std::string type ( because QVariant will misbehave )
template <> bool QStorage<std::string>::write(const std::string &value) {
    if (m_address.isEmpty()) {
        return false;
    }
    QSettings storage("QStorage", m_name);
    storage.setValue(m_address, QVariant(QString::fromStdString(value)));
    return true;
}

// Specialized behavior for std::string type ( because QVariant will misbehave )
template <> std::string QStorage<std::string>::read() {
    QSettings storage("QStorage", m_name);
    return storage.value(m_address).toString().toStdString();
}
