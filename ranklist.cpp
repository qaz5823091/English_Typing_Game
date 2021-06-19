#include "ranklist.h"
#include "ui_ranklist.h"
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
#include<QTime>
#include<QDebug>
#include<QtAlgorithms>
#include <QSet>

ranklist::ranklist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ranklist)
{
    ui->setupUi(this);
}

ranklist::~ranklist()
{
    delete ui;
}

void ranklist::on_pushButton_clicked()
{
    time.clear();
    name.clear();

    QString str = ui->textBrowser->toPlainText();
    QTextStream in(&str);

    int numOfRank = 1;
    QString result="";
    QStringList list;
    if(in.atEnd()){
        QMessageBox::warning(this,"注意","不能為空");
    }
     while (!in.atEnd()) {
         QString fileLine = in.readLine();
         list = fileLine.split(" ");
         if(list[1].size() >2 && list[1].size() <6 ){
             QMessageBox::warning(this,"注意","格式錯誤，要到小數點後4位");
             break;
         }
         else{
               time.push_back(list[1]);
               name.push_back(list[0]);
         }
    }

     sortForGrade(time,name);

     int length = time.size();
     for(int i=0; i<length; i++) {
         QStringList test;
         result += "第 " + QString(numOfRank+'0') + " 名: " + name[i] + " " + time[i] + "秒\n";
         numOfRank++;
     }
     ui->textBrowser->setText(result);

}

void ranklist::sortForGrade(std::vector<QString> &time, std::vector<QString> &name){
    int length_time = time.size();
    QString tmp="";

    for(int i=length_time-1; i>0; i--){
        for(int j=0; j<i; j++){

            qDebug() << time[j] << " " << time[j+1] << '\n';
            if(time[j].size() < time[j+1].size())
                continue;
            if(time[j].size() > time[j+1].size() ){
                tmp = time[j];
                time[j] = time[j+1];
                time[j+1] = tmp;

                tmp = name[j];
                name[j] = name[j+1];
                name[j+1] = tmp;
            }

            if(time[j] > time[j+1]){
                tmp = time[j];
                time[j] = time[j+1];
                time[j+1] = tmp;

                tmp = name[j];
                name[j] = name[j+1];
                name[j+1] = tmp;
            }
        }
    }

}
