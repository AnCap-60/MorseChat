#pragma once

#include <QTcpServer>
#include <QTcpSocket>

class Server : public QTcpServer
{
	Q_OBJECT

public:
	Server();
	QTcpSocket* socket;

private:	
	QVector<QTcpSocket*> sockets;
	QByteArray data;

	void SendToClient(QString str);

public slots:
	void SlotReadyRead();
	void IncommingConnection(qintptr socketDescriptor);
};

