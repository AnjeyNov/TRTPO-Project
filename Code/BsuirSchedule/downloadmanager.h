#ifndef DOWNLOADMANAGER_H
#define DOWNLOADMANAGER_H
#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QUrlQuery>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkAccessManager>
#include <QUrl>

#include "group.h"


class DownloadManager : public QObject
{
    Q_OBJECT
public:
    explicit DownloadManager(QObject *parent = nullptr);
    DownloadManager();





signals:

public slots:

    void onResult(QNetworkReply *reply);
    void makeRequest(QString groupNumber);

private:
    QNetworkAccessManager *networkManager;

};

#endif // DOWNLOADMANAGER_H
