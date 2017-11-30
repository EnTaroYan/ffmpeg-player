#pragma once

#include <QtNetwork>

class UdpReceiver : public QObject
{
	Q_OBJECT
public:
	UdpReceiver(QHostAddress localIp,int localPort, QObject *p = 0);
	~UdpReceiver();

public slots:
	void receive();

private:
	QUdpSocket *uSocket;
};