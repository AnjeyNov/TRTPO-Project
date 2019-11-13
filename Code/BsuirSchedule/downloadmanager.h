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
    
    void groupAdded();
    void unavailableGroup();
    void succes();

public slots:
    void onScheduleRequestResult(QNetworkReply *reply);
    void onCheckRequestResult(QNetworkReply *reply);
    
    void addGroup(QString groupNumber);
    
private:
    QString groupNumber_;
    Schedule *newSchedule;
    QNetworkAccessManager *scheduleDownloader_;
    QNetworkAccessManager *checker_;
    
    
    void makeScheduleRequest();
    void makeCheckRequest();
    
};

#endif // DOWNLOADMANAGER_H
