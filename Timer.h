#ifndef TIMER_H
#define TIMER_H

#include <QtCore>
#include <QLabel>

class Timer : public QObject
{
    Q_OBJECT

    public:
        Timer();
        Timer(int);
        QTimer *timer;
        QLabel *label;
        int seconds;
        int counter;

    public slots:
        void slot();
        void start();
        void stop();
        void toLabel(QLabel *label);
        void setLabelSeconds();
};



#endif // TIMER_H
