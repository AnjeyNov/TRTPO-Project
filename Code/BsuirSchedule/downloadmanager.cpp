#include "downloadmanager.h"

DownloadManager::DownloadManager(QObject *parent) : QObject(parent)
{
    networkManager = new QNetworkAccessManager();
    connect(networkManager, &QNetworkAccessManager::finished, this, &DownloadManager::onResult);
    // Получаем данные, а именно JSON файл с сайта по определённому url

}

DownloadManager::DownloadManager()
{
    networkManager = new QNetworkAccessManager();
    connect(networkManager, &QNetworkAccessManager::finished, this, &DownloadManager::onResult);
    // Получаем данные, а именно JSON файл с сайта по определённому url

}

void DownloadManager::onResult(QNetworkReply *reply)
{

    if(!reply->error()){

        QJsonDocument document = QJsonDocument::fromJson(reply->readAll());
        //Преобразумем весь ответ в JsonObject
        QJsonObject root = document.object();

        // Получаем вложение studebntGroup
        QJsonObject studentGroup = root.value("studentGroup").toObject();

        Group newGroup;
        newGroup.setNumber(studentGroup.value("name").toString().toStdString());
        newGroup.setCourse(short(studentGroup.value("course").toInt()));
        // <<тут добавить определение факультета и специальности>>

        Schedule newSchedule;
        Week firstWeek;
        Week secondWeek;
        Week thirdWeek;
        Week fourthWeek;

        firstWeek.setNumber(1);
        secondWeek.setNumber(2);
        thirdWeek.setNumber(3);
        fourthWeek.setNumber(4);



        QJsonArray schedules = root.value("schedules").toArray();
    }

}

void DownloadManager::makeRequest(QString groupNumber)
{
    QSslConfiguration config = QSslConfiguration::defaultConfiguration();
    config.setProtocol(QSsl::TlsV1_2);
    QNetworkRequest request(QUrl("https://journal.bsuir.by/api/v1/studentGroup/schedule?studentGroup=" + groupNumber));
    request.setSslConfiguration(config);
    request.setHeader(QNetworkRequest::ServerHeader, "application/json");
    networkManager->get(request);
}
