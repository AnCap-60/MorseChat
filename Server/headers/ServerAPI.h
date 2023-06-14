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

	static ServerAPI* GetInstance();

#define Instance GetInstance()

	static ServerAPI* instance;

	QTcpSocket* socket;
	QByteArray data;
	quint16 nextBlockSize = 0;

public slots:
	static void SlotReadyRead();
};