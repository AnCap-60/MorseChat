#pragma once

#include <QTcpSocket>
#include <QTime>

/// <summary>
/// Singleton, use static functions
/// </summary>
class ServerAPI : public QObject
{
	Q_OBJECT

public:
	static void ConnectToServer(QString IPv4);

	void SendToServer(QString str);

	static ServerAPI* GetInstance();
	#define Instance GetInstance()

private:
	ServerAPI() {}

	static ServerAPI* instance;

	QTcpSocket* socket = nullptr;
	QByteArray data;
	quint16 nextBlockSize = 0;

public slots:
	void SlotReadyRead();

signals:
	void NewMessage(QTime time, QString message);
};