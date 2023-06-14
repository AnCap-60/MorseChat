#include <QTcpSocket>
#include <QTime>

class ServerAPI : QObject
{
	Q_OBJECT

public:
	static void ConnectToServer(QString IPv4);

private:
	static ServerAPI* GetInstance();

#define Instance GetInstance()

	static ServerAPI* instance;

	QTcpSocket* socket;
	QByteArray data;

	void SendToServer(QString str);

	quint16 nextBlockSize;

public slots:
	static void SlotReadyRead();
};