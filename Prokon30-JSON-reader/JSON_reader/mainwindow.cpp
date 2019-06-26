#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QFile file("original test.json");
    file.open(QFile::ReadOnly);
    QTextStream in (&file);

    QJsonDocument jsonDoc = QJsonDocument::fromJson(in.readAll().toUtf8());
    //JSONファイルから読み込み
    QJsonObject obj = jsonDoc.object();
    QStringList keys =obj.keys();
    //全てのキーを取得

    foreach(QString key,keys){
        qDebug() << "key = " <<key;
        QString value = obj.value(key).toString();
        qDebug() <<"value = "<<value;
    }

    QJsonArray array = obj.value("array").toArray();
    foreach(QJsonValue value, array){
        qDebug() << "value = " << value.toString("");
    }
file.close();
}
