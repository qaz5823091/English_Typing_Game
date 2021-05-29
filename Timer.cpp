#include "Timer.h"
#include "mainwindow.h"

#include <QtCore>
#include <QDebug>

Timer::Timer() {
    this->timer = new QTimer(this);
    this->seconds = 100;
    this->counter = 0;
    connect(timer, SIGNAL(timeout()), this, SLOT(slot()));

    // timer->start(1000);
}

Timer::Timer(int s) {
    this->timer = new QTimer(this);
    this->seconds = s;
    this->counter = 0;
    connect(timer, SIGNAL(timeout()), this, SLOT(slot()));

    // timer->start(1000);
}

void Timer::slot() {
    this->seconds--;
    this->counter++;
    if (seconds == 0)
        timer->stop();

    setLabelSeconds();
    // qDebug() << QString::number(seconds);
}

void Timer::start() {
    timer->start(1000);
}

void Timer::stop() {
    timer->stop();
}

void Timer::setLabelSeconds() {
    label->setText("倒數 " + QString::number(seconds) + " 秒");
}

void Timer::toLabel(QLabel *label) {
    this->label = label;
}
