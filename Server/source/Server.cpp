#include "../headers/Server.h"

Server::Server()
{
	if (this->listen(QHostAddress::Any, 2323))
		qDebug() << "Server started!\n";
	else
		qDebug() << "Error in starting server\n";
}

void Server::IncommingConnection(qintptr socketDescriptor)
{
	socket = new QTcpSocket;
	socket->setSocketDescriptor(socketDescriptor);
	connect(socket, &QTcpSocket::readyRead, this, &Server::SlotReadyRead);
	connect(socket, &QTcpSocket::disconnected, socket, &QTcpServer::deleteLater);

	sockets.push_back(socket);
	qDebug() << "client " << socketDescriptor << " connected\n";
}

void Server::SlotReadyRead()
{
	socket = (QTcpSocket*)sender();
	QDataStream in(socket);
	in.setVersion(QDataStream::Qt_6_5);
	if (in.status() == QDataStream::Ok)
	{
		qDebug() << "read...";
		
		while (true)
		{
			
		}
	}
	else
		qDebug() << "QDataStream error";
}

void Server::SendToClient(QString str)
{
	data.clear();
	QDataStream out(&data, QDataStream::WriteOnly);
	out.setVersion(QDataStream::Qt_6_5);

	out << str;
	socket->write(data);
}