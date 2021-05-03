#pragma once

#include <QDateTime>
#include <QNetworkAccessManager>
#include <QNetworkReply>

#include "ipo.hpp"

#define DATE_SOURCE_NASDAQ_DATE_FORMAT "MM/dd/yyyy"
#define DATE_SOURCE_NASDAQ_DATE_FORMAT_URL "yyyy-MM"

class DataSourceNasdaq: public QObject
{
    Q_OBJECT

public:
    explicit DataSourceNasdaq(QObject *parent = nullptr);
    ~DataSourceNasdaq();

    QList<Ipo> queryData();

private:
    QString getCurrentDate();

    QDateTime lastUsed;
    QString baseUrl = QString("https://api.nasdaq.com/api");
    QNetworkAccessManager manager;
    QNetworkReply *reply;
    QUrl url = QUrl(baseUrl + "/ipo/calendar");
};
