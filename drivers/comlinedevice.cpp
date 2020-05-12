#include "comlinedevice.h"

ComlineDevice::ComlineDevice()
    : IDataLink()
    , m_baudRate(2400)
{
}

bool ComlineDevice::connect(const QString &address)
{
    //m_device.Open(address.toLatin1().data(), m_baudRate, true);
    //return m_device.Opened();
    return true;
}

void ComlineDevice::close()
{
    //m_device.Close();
}

bool ComlineDevice::write(const QString &message)
{
    for (const auto& hex : createAscii(message)) {
        //m_device.Write(&hex, sizeof(unsigned char));
    }
    return true;
}

QString ComlineDevice::read()
{
    QString message;
    unsigned char input = '0';
    do {
        //input = m_device.NextByte();
        message.append(QChar(input));
    } while (input != '0');
    return message;
}

void ComlineDevice::setBaud(const int rate)
{
    m_baudRate = rate;
}

std::vector<unsigned char> ComlineDevice::createAscii(const QString &text)
{
    std::vector<unsigned char> characters;
    for (const auto& symbol : text) {
        characters.push_back(symbol.toLatin1());
    }
    return characters;
}
