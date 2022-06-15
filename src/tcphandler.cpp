#include "tcphandler.h"

TCPHandler::TCPHandler(QHostAddress address, quint16 port, QObject* parent) : QObject(parent)
{
	socket = new QTcpSocket(this);
	socket->connectToHost(address, port);
	qDebug() << socket->isOpen();
	connect(socket, &QTcpSocket::connected, this, &TCPHandler::connected);
	connect(socket, &QTcpSocket::readyRead, this, &TCPHandler::onMessage);
}

TCPHandler::~TCPHandler()
{
	delete socket;
}

// void TCPHandler::onConnect()
//{
//}

void TCPHandler::onMessage()
{
	readBuffer.append(socket->readAll());
	int index = readBuffer.indexOf('\x004');
	while (index != -1)
	{
		qDebug() << readBuffer.first(index);
		QJsonParseError err;
		QJsonDocument jsonDocument = QJsonDocument::fromJson(readBuffer.first(index), &err);
		if (err.error != QJsonParseError::NoError)
		{
			qDebug() << "JSON Parse error: " << err.errorString() << " at " << err.offset;
		}
		else
		{
			qDebug() << jsonDocument;
			emit messageReceived(jsonDocument);
		}
		readBuffer.remove(0, index + 1);
		index = readBuffer.indexOf('\x004');
	}
}

void TCPHandler::sendMessage(QJsonDocument json)
{
	if (socket->isOpen())
	{
		qDebug() << "sending" << json.toJson(QJsonDocument::Compact);
		socket->write(json.toJson(QJsonDocument::Compact));
	}
}
