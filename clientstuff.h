#ifndef CLIENTSTUFF_H
#define CLIENTSTUFF_H

#include <QString>
#include <QTcpSocket>
#include <QDataStream>
#include <QTimer>

class ClientStuff : public QObject
{
    Q_OBJECT

public:
    ClientStuff(const QString host, int port);

    QTcpSocket *tcpSocket;
    bool getStatus();

public slots:
    void closeConnection();
    void connectToServer();

signals:
    void statusChanged(bool);
    void hasReadSome(QString msg);

private slots:
    void readyRead();
    void connected();
    void connectionTimeout();

private:
    QString host;
    int port;
    bool status;
    quint16 m_nNextBlockSize;
    QTimer *timeoutTimer;
};

#endif // CLIENTSTUFF_H
