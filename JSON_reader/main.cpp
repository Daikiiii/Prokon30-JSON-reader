#include "mainwindow.h"
#include <QApplication>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QTextStream>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QFile file("C\\Users\\dk2s2\\Desktop\\データサンプル - コピー");
    file.open(QFile::ReadOnly);
    QTextStream in (&file);

    QJsonDocument jsonDoc = QJsonDocument::fromJson(in.readAll().toUtf8());
    //JSONファイルから読み込み
    QJsonObject obj = jsonDoc.object();
    QStringList keys =obj.keys();
    //全てのキーを取得

    /*
    foreach(QString key,keys){
        qDebug() << "key = " <<key;
        QString value = obj.value(key).toString();
        qDebug() <<"value = "<<calue;
    }*/
file.close();
    return a.exec();
}
