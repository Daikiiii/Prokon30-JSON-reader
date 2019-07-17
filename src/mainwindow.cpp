#include "MainWindow.h"
#include "ui_mainwindow.h"

#include "AnalyzeField.h"
#include "PointCalculate.h"

extern QSettings config;

//PointCalculate *pointCalculate;

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

void MainWindow::on_Button_Start_1_clicked(){
    AnalyzeField* AF;
    AF = new AnalyzeField(tile, agent, field);
    AF->setup();
    //ui->lcdNumber_red->display(PointCalculate::getAllPoints(RED));
    //ui->lcdNumber_red->display(PointCalculate::getAllPoints(BLUE));
}

void MainWindow::on_reloadButton_clicked(){

}

void MainWindow::on_pushButton_clicked()
{
    QFile Fieldfile("フィールド情報_turn0.json");
    Fieldfile.open(QFile::ReadOnly);
    QTextStream in (&Fieldfile);

    QFile Movefile("行動情報_ID5.json");
    Movefile.open(QFile::ReadOnly);
    QTextStream an (&Movefile);

    QJsonDocument jsonDoc = QJsonDocument::fromJson(in.readAll().toUtf8());
    //JSONファイルから読み込み

    QJsonObject obj = jsonDoc.object();
    QStringList keys =obj.keys();



    field.width= obj.value("width").toDouble();
    field.height= obj.value("height").toDouble();
    field.startedAtUnixTime= obj.value("height").toDouble();
    field.turn= obj.value("turn").toDouble();

    qDebug()<<field.width;
    qDebug()<<field.height;
    qDebug()<<field.startedAtUnixTime;
    qDebug()<<field.turn;

    cout<<"width "<<field.width<<endl<<
          "height "<<field.height<<endl<<
          "startedAtUnixTime "<<field.startedAtUnixTime<<endl<<
          "turn "<<field.turn<<endl;


    QByteArray data = Fieldfile.readAll();
    //QJsonDocument jsonDoc(QJsonDocument::fromJson(data));
    //QString jsonStr=jsonDoc.toJson(QJsonDocument::Compact);
    //qDebug()<<jsonStr;


Fieldfile.close();
Movefile.close();
}
