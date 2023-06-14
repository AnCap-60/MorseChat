#include "../headers/Server.h"

Server::Server()
{
	if (this->listen(QHostAddress::Any, 2323))
		qDebug() << "Server started!\n";
	else
		qDebug() << "Error in starting server\n";
}

void Server::incomingConnection(qintptr socketDescriptor)
{
	socket = new QTcpSocket;
	socket->setSocketDescriptor(socketDescriptor);
	connect(socket, &QTcpSocket::readyRead, this, &Server::SlotReadyRead);
	connect(socket, &QTcpSocket::disconnected, socket, &QTcpServer::deleteLater);
	connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::abort);
	connect(socket, &QTcpSocket::disconnected, this, &Server::ConnectionLost);

	sockets.push_back(socket);
	qDebug() << "client " << socketDescriptor << " connected\n";

	for (auto note : history)
		SendToClient(socket, note.first, note.second);
}

void Server::ConnectionLost()
{
	for (auto soc : sockets)
		if (!socket->isValid())
		{
			sockets.removeOne(soc);
			qDebug() << "socket " << soc->socketDescriptor() << " deleted";
		}
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

			SendToClients(time, message);

			break;
		}
	}
	else
		qDebug() << "QDataStream error";
}

void Server::SendToClients(QTime time, QString message)
{
	history.emplace(time, message);

	for (QTcpSocket* soc : sockets)
		SendToClient(soc, time, message);
}

void Server::SendToClient(QTcpSocket* soc, QTime time, QString message)
{
	data.clear();
	QDataStream out(&data, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_6_5);

	out << quint16(0) << time << message;
	out.device()->seek(0);
	out << quint16(data.size() - sizeof(quint16));

	soc->write(data);
}