#include "../headers/ServerAPI.h"

void ServerAPI::ConnectToServer(QString IPv4)
{
	Instance->socket = new QTcpSocket(Instance);
	Instance->connect(Instance->socket, &QTcpSocket::readyRead, Instance, &ServerAPI::SlotReadyRead);
	Instance->connect(Instance->socket, &QTcpSocket::disconnected, Instance->socket, &QTcpSocket::deleteLater);

	Instance->socket->connectToHost(IPv4, 2323);
}

ServerAPI* ServerAPI::GetInstance()
{
	if (instance == nullptr)
		instance = new ServerAPI();
	return instance;
}

void ServerAPI::SendToServer(QString str)
{
	Instance->data.clear();
	QDataStream out(&Instance->data, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_6_5);

	out << quint16(0) << QTime::currentTime() << str;
	
	out.device()->seek(0);
	out << quint16(Instance->data.size() - sizeof(quint16));
	Instance->socket->write(Instance->data);
}

void ServerAPI::SlotReadyRead()
{
	QDataStream in(Instance->socket);
	in.setVersion(QDataStream::Qt_6_5);
	if (in.status() == QDataStream::Ok)
	{
		while (true)
		{
			if (Instance->nextBlockSize == 0)
			{
				if (Instance->socket->bytesAvailable() < 2)
					break;

				in >> Instance->nextBlockSize;
			}
			if (Instance->socket->bytesAvailable() < Instance->nextBlockSize)
				break;

			QTime time;
			in >> time;

			QString message;
			in >> message;

			Instance->nextBlockSize = 0;

			//TODO: show message and time on chat screen
			break;
		}
	}
	else;
		//TODO: show error
}
