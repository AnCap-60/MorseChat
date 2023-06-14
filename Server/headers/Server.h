#pragma once

#include <QTcpServer>
#include <QTcpSocket>
#include <QTime>

class Server : public QTcpServer
{
	Q_OBJECT

public:
	Server();
	QTcpSocket* socket;

private:	
	QVector<QTcpSocket*> sockets;
	QByteArray data;

	quint16 nextBlockSize = 0;

	void SendToClient(QString str);

public slots:
	void SlotReadyRead();
	void IncommingConnection(qintptr socketDescriptor);
};

