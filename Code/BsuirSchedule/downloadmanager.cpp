#include "downloadmanager.h"

DownloadManager::DownloadManager(QObject *parent) : QObject(parent)
{
    scheduleDownloader_ = new QNetworkAccessManager();
    connect(scheduleDownloader_, &QNetworkAccessManager::finished, this, &DownloadManager::onScheduleRequestResult);
    checker_ = new QNetworkAccessManager();
    connect(checker_, &QNetworkAccessManager::finished, this, &DownloadManager::onCheckRequestResult);
}

DownloadManager::DownloadManager()
{
    scheduleDownloader_ = new QNetworkAccessManager();
    connect(scheduleDownloader_, &QNetworkAccessManager::finished, this, &DownloadManager::onScheduleRequestResult);
    checker_ = new QNetworkAccessManager();
    connect(checker_, &QNetworkAccessManager::finished, this, &DownloadManager::onCheckRequestResult);
}

void DownloadManager::onScheduleRequestResult(QNetworkReply *reply)
{   
    QNetworkReply::NetworkError error = reply->error();

    if(error == QNetworkReply::NoError){

        QJsonDocument document = QJsonDocument::fromJson(reply->readAll());
        //Преобразумем весь ответ в JsonObject
        QJsonObject root = document.object();

        // Получаем вложение studebntGroup
        QJsonObject studentGroup = root.value("studentGroup").toObject();

        Group newGroup;
        newGroup.setNumber(studentGroup.value("name").toString().toStdString());
        newGroup.setCourse(short(studentGroup.value("course").toInt()));
        // <<тут добавить определение факультета и специальности>>
        
        newSchedule = new Schedule();
        Week firstWeek;
        Week secondWeek;
        Week thirdWeek;
        Week fourthWeek;

        firstWeek.setNumber(1);
        secondWeek.setNumber(2);
        thirdWeek.setNumber(3);
        fourthWeek.setNumber(4);

        QJsonArray schedules = root.value("schedules").toArray();
        int schedulesSize = schedules.count();
        for(int i = 0; i < schedulesSize; i++){
            QJsonObject schedule = schedules.at(0).toObject();

            Day dayForFirstWeek;
            Day dayForSecondWeek;
            Day dayForThirdWeek;
            Day dayForFourthWeek;

            dayForFirstWeek.setName(schedule.value("weekDay").toString().toStdString());
            dayForSecondWeek.setName(schedule.value("weekDay").toString().toStdString());
            dayForThirdWeek.setName(schedule.value("weekDay").toString().toStdString());
            dayForFourthWeek.setName(schedule.value("weekDay").toString().toStdString());

            QJsonArray daySchedule = schedule.value("schedule").toArray();
            int dayScheduleSize = daySchedule.count();
            for(int i = 0; i < dayScheduleSize; i++){
                QJsonObject jsonLesson = daySchedule.at(i).toObject();

                Time tmpTime;
                tmpTime.setStart(jsonLesson.value("startLessonTime").toString().toStdString());
                tmpTime.setEnd(jsonLesson.value("endLessonTime").toString().toStdString());

                Lesson tmpLesson;
                tmpLesson.setTime(tmpTime);
                tmpLesson.setClassroom(jsonLesson.value("auditory").toArray().at(0).toString().toStdString());
                tmpLesson.setSubject(jsonLesson.value("subject").toString().toStdString());
                tmpLesson.setType(jsonLesson.value("lessonType").toString().toStdString());
                tmpLesson.setNote(jsonLesson.value("note").toString().toStdString());
                tmpLesson.setSubgroupNumber(short(jsonLesson.value("numSubgroup").toInt()));

                QJsonArray weekArray = jsonLesson.value("week").toArray();
                int weekArraySize = weekArray.count();
                for(int i = 0; i < weekArraySize; i++){
                    switch(weekArray.at(i).toInt()){
                    case 0: {
                        dayForFirstWeek.addLesson(tmpLesson);
                        dayForSecondWeek.addLesson(tmpLesson);
                        dayForThirdWeek.addLesson(tmpLesson);
                        dayForFourthWeek.addLesson(tmpLesson);

                        // TODO: make function
                        weekArraySize = 0;
                        break;
                    }
                    case 1: {
                        dayForFirstWeek.addLesson(tmpLesson);
                        break;
                    }
                    case 2: {
                        dayForSecondWeek.addLesson(tmpLesson);
                        break;
                    }
                    case 3: {
                        dayForThirdWeek.addLesson(tmpLesson);
                        break;
                    }
                    case 4: {
                        dayForFourthWeek.addLesson(tmpLesson);
                        break;
                    }
                    }
                }
            }

            if(!dayForFirstWeek.empty()){
                firstWeek.addDay(dayForFirstWeek);
            }
            if(!dayForSecondWeek.empty()){
                secondWeek.addDay(dayForSecondWeek);
            }
            if(!dayForThirdWeek.empty()){
                thirdWeek.addDay(dayForThirdWeek);
            }
            if(!dayForFourthWeek.empty()){
                fourthWeek.addDay(dayForFourthWeek);
            }
        }
        
        newSchedule->setWeekOne(firstWeek);
        newSchedule->setWeekTwo(secondWeek);
        newSchedule->setWeekTree(thirdWeek);
        newSchedule->setWeekFour(fourthWeek);

        emit succes();

    } else {


    }
    
}

void DownloadManager::onCheckRequestResult(QNetworkReply *reply)
{
    QJsonDocument document = QJsonDocument::fromJson(reply->readAll());
    QJsonObject root = document.object();
    QJsonArray array = document.array();
    for(int i = 0; i < array.count(); i++){
        QString name = array.at(i).toObject().value("name").toString();
        if(name == groupNumber_){
           makeScheduleRequest();
        }
        else {
            emit unavailableGroup();
        }
    }
}

void DownloadManager::addGroup(QString groupNumber)
{
    this->groupNumber_ = groupNumber;
    makeCheckRequest();
}

void DownloadManager::makeScheduleRequest()
{
    QSslConfiguration config = QSslConfiguration::defaultConfiguration();
    config.setProtocol(QSsl::TlsV1_2);
    QNetworkRequest request(QUrl("https://journal.bsuir.by/api/v1/studentGroup/schedule?studentGroup=" + groupNumber_));
    request.setSslConfiguration(config);
    request.setHeader(QNetworkRequest::ServerHeader, "application/json");
    scheduleDownloader_->get(request);
}

void DownloadManager::makeCheckRequest()
{
    QSslConfiguration config = QSslConfiguration::defaultConfiguration();
    config.setProtocol(QSsl::TlsV1_2);
    QNetworkRequest request(QUrl("https://journal.bsuir.by/api/v1/groups"));
    request.setSslConfiguration(config);
    request.setHeader(QNetworkRequest::ServerHeader, "application/json");
    checker_->get(request);    
}
