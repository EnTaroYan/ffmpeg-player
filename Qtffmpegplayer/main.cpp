#include "Qtffmpegplayer.h"
#include <QtWidgets/QApplication>
#include "UdpReceiver.h"


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//QHostAddress localIp("192.168.0.1");
	//int localPort = 1234;
	//UdpReceiver udpReceiver(localIp, localPort);
	Qtffmpegplayer w;
	w.show();
	return a.exec();
}
