#include "UdpReceiver.h"
#include <QtNetwork>


UdpReceiver::UdpReceiver(QHostAddress localIp, int localPort, QObject *p)
{
	uSocket = new QUdpSocket;
	uSocket->bind(localIp, localPort);
	connect(uSocket, SIGNAL(readyRead()), this, SLOT(receive()));
}

UdpReceiver::~UdpReceiver()
{
	delete uSocket;
}

void UdpReceiver::receive()
{
	QByteArray ba;
	while (uSocket->hasPendingDatagrams())
	{
		ba.resize(uSocket->pendingDatagramSize());
		uSocket->readDatagram(ba.data(), ba.size());
		//qDebug() << ba.data();
		//int a = ba[0];
		//qDebug() << a << "  " << ba.size();
	}
}