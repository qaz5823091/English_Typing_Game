#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Timer.h"

#include <QKeyEvent>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QDir>


int MainWindow::index = 0;

MainWindow::MainWindow(QWidget *parent, QString location)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    gameStart(location);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    setLabelHint("");

    QString key;
    switch(event->key()) {
        case Qt::Key_Return:
        case Qt::Key_Enter:
            judge();
            break;
        case Qt::Key_Backspace:
            reply.chop(1);
            break;
        default:
            key = char(event->key());
            if (key > 'Z' || key < 'A')
                break;

            // combine shift and another key
            if ( event->modifiers().testFlag(Qt::ShiftModifier) )
                key = key.toUpper();
            else
                key = key.toLower();

            reply += key;

            break;
    }
    setLabelReply(reply);
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

void MainWindow::setWord(QString location) {
    //QString location = ":/txt/vocabulary.txt";
    readFile(location);
    length = word.size();
}

void MainWindow::setLabelQuestion(QString question) {
    ui->question->setText(question);
}

void MainWindow::setLabelReply(QString reply) {
    ui->input->setText(reply);
}

void MainWindow::setLabelHint(QString hint) {
    ui->hint->setText(hint);
}

void MainWindow::setLCDCounter(int second) {
    ui->downCounter->display(second);
}

void MainWindow::gameStart(QString loc) {

    timer = new QTimer();
    seconds = 30;
    connect(timer, SIGNAL(timeout()), this, SLOT(slot()));

    setWord(loc);
    setLabelQuestion("Question :   "+word[index].getWord());
    setLCDCounter(seconds);

    timer->start(1000);
}

void MainWindow::gameStop() {
    timer->stop();

    setLabelQuestion("Time is up!");
}

void MainWindow::judge() {
    if (reply == word[index].getWord()) {
        setLabelHint("Correct!");
        ++index;
        if (index < length) {
            setLabelQuestion(word[index].getWord());
        }
        else {
            gameStop();
            rank = new RecordRank();
            rank->sendGrade(length, seconds);
            rank->show();
            setLabelQuestion("Finish!");
        }
    }
    else {
        setLabelHint("Fail");
    }

    reply = "";
}

void MainWindow::slot() {
    --seconds;

    if (seconds == 0) {
        gameStop();
    }

    setLCDCounter(seconds);
}
