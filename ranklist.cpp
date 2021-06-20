#include "ranklist.h"
#include "ui_ranklist.h"
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
#include<QTime>
#include<QDebug>
#include<QtAlgorithms>
#include <QSet>
#include <qmath.h>

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
    bool hasSpace=false;
    if(in.atEnd())
        QMessageBox::warning(this,"注意","不能為空");
    while(!in.atEnd()){     //to check whether there is a space
        qDebug() << "test";
        QString tmp = in.readLine();
        hasSpace = false;
        int length = tmp.size();
        for(int i=0; i<length; i++){
            if(tmp[i] == " ")
                hasSpace = true;
        }
        if( !hasSpace ){
           break;
        }
    }

    if(!hasSpace)
        QMessageBox::warning(this,"注意","名字跟秒數間要空格");
    if(hasSpace){

        QString str = ui->textBrowser->toPlainText();
        QTextStream in(&str);
        int numOfRank = 1;
        QString result="";
        QStringList list; //to split the string with space
             while (!in.atEnd()) {
                 double total=0;
                 int powTenth = 0, powDigit=1;
                 QString fileLine = in.readLine();
                 list = fileLine.split(" ");
                 int lengthOfList = list[1].size();
                 int i, j;

                 for(i = 0; i<lengthOfList; i++){
                     if(list[1][i] == ".")
                         break;
                 }
                 j = i;
                 for(--j; j>=0; j--){
                     total += (list[1][j].digitValue()) * qPow(10, powTenth++);
                     qDebug() << total << " ";
                 }
                 for(++i; i<lengthOfList; i++){
                     total += (list[1][i].digitValue()) * qPow(10, (-1)*powDigit);
                     powDigit++;
                 }

                 time.push_back(total);
                 name.push_back(list[0]);

            }

             sortForGrade(time,name);
             qDebug() << time[0] << " ";

             int length = time.size();
             for(int i=0; i<length; i++) {
                 result += "第 " + QString(numOfRank+'0') + " 名: " + name[i] + " " + QString::number(time[i]) + "秒\n";
                 numOfRank++;
             }
             ui->textBrowser->setText(result);
    }

}

void ranklist::sortForGrade(std::vector<double> &time, std::vector<QString> &name){
    int length_time = time.size();
    QString tmp="";
    double tmpNum=0;

    for(int i=length_time-1; i>0; i--){
        for(int j=0; j<i; j++){
            if(time[j] > time[j+1]){
                tmpNum = time[j];
                time[j] = time[j+1];
                time[j+1] = tmpNum;

                tmp = name[j];
                name[j] = name[j+1];
                name[j+1] = tmp;
            }
        }
    }

}
