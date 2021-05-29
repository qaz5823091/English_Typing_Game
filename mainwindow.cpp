#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Timer.h"

#include <QKeyEvent>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QDir>


int MainWindow::index = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QFont font;
    font.setPointSize(20);
    ui->question->setFont(font);
    ui->input->setFont(font);
    setWord();
    setLabelQuestion(word[index].getWord());
    timer.toLabel(ui->seconds);
    timer.start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    QString key;
    key = char(event->key());
    if (index < length) {
        if (word[index].getSolved() == false) {
            if (key == Qt::Key_Space) {
                if (reply == word[index].getWord()) {
                    setLabelReply("Correct!");
                    index++;
                    if (index < length) {
                        setLabelQuestion(word[index].getWord());
                    }
                    else {
                        setLabelQuestion("Finish!");
                        timer.stop();
                        rank = new RecordRank();
                        rank->sendGrade(length, timer.counter);
                        rank->show();
                    }
                }
                else {
                    setLabelReply("Fail . .");
                }
                reply = "";
            }
            else if (key == Qt::Key_Backspace) {
                reply.chop(1);
                setLabelReply(reply);
            }
            else {
                key = key.toLower();
                reply += key;
                setLabelReply(reply);
            }
        }
    }
}


void MainWindow::readFile(QString fileName) {
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Cannot open file for reading:" << qPrintable(file.errorString());
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString fileLine = in.readLine();
        word.push_back( Word(fileLine) );
    }
    file.close();
}

void MainWindow::setWord() {
<<<<<<< HEAD
=======
    //readFile("C:\\Users\\allen\\OneDrive\\Desktop\\others\\EnglishTypingGame\\vocabulary.txt");
>>>>>>> 63b9c11b9602ed5a9352f17a00b14e8810b55c39
    QString location = ":/txt/vocabulary.txt";
    readFile(location);
    length = word.size();
}

void MainWindow::setLabelQuestion(QString question) {
    ui->question->setText(question);
}

void MainWindow::setLabelReply(QString reply) {
    ui->input->setText(reply);
}
