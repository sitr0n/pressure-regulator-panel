#include "comlinedevice.h"

ComlineDevice::ComlineDevice()
    : ExternalDevice()
    , m_baudRate(2400)
{
}

bool ComlineDevice::connect(const QString &address, int port)
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

bool ComlineDevice::read(QString &message)
{
    message.clear();
    unsigned char input = '0';
    do {
        //input = device.NextByte();
        message.append(QChar(input));
    } while (input != '0');
    return !message.isEmpty();
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
