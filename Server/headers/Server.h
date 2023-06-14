#pragma once

#include <QTcpServer>
#include <QTcpSocket>
#include <QTime>
#include <map>

class Server : public QTcpServer
{
	Q_OBJECT

public:
	Server();
	QTcpSocket* socket;

private:	
	std::map<QTime, QString> history;	

	QVector<QTcpSocket*> sockets;
	QByteArray data;

	quint16 nextBlockSize = 0;

	void SendToClients(QTime time, QString message);
	void SendToClient(QTcpSocket* soc, QTime time, QString message);

public slots:
	void SlotReadyRead();
	void incomingConnection(qintptr socketDescriptor);
	void ConnectionLost();
};

