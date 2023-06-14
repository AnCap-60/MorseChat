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
			if (nextBlockSize == 0)
			{
				if (socket->bytesAvailable() < 2)
					break;

				in >> nextBlockSize;
			}
			if (socket->bytesAvailable() < nextBlockSize)
				break;

			QTime time;
			in >> time;

			QString message;
			in >> message;

			nextBlockSize = 0;

			SendToClient(message);

			break;
		}
	}
	else
		qDebug() << "QDataStream error";
}

void Server::SendToClient(QString str)
{
	data.clear();
	QDataStream out(&data, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_6_5);

	out << str;
	socket->write(data);
}