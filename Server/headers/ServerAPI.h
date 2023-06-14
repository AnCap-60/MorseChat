#include <QTcpSocket>
#include <QTime>

/// <summary>
/// Singleton, use static functions
/// </summary>
class ServerAPI : QObject
{
	Q_OBJECT

public:
	static void ConnectToServer(QString IPv4);

	void SendToServer(QString str);

private:
	ServerAPI() {}

	static ServerAPI* instance;
	static ServerAPI* GetInstance();

#define Instance GetInstance()

	QTcpSocket* socket = nullptr;
	QByteArray data;
	quint16 nextBlockSize = 0;

public slots:
	static void SlotReadyRead();

signals:
	static void NewMessage(QTime time, QString message);
};