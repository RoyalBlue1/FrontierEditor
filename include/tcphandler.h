#ifndef TCPHANDLER_H
#define TCPHANDLER_H

#include <QJsonDocument>
#include <QTcpSocket>

class TCPHandler : public QObject
{
	Q_OBJECT
  public:
	explicit TCPHandler(QHostAddress address, quint16 port, QObject* parent = nullptr);
	~TCPHandler();
  public slots:
	void sendMessage(QJsonDocument json);

  signals:
	void messageReceived(QJsonDocument json);
	void connected();

  private:
	QByteArray readBuffer;
	QTcpSocket* socket;
  private slots:
	void onMessage();
	//	void onConnect();
};

#endif // TCPHANDLER_H
