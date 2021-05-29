#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QKeyEvent>
#include <QTimer>
#include <vector>
#include "Word.h"
//#include "Timer.h"
#include "RecordrRank.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    private:
        Ui::MainWindow *ui;

        QTimer *timer;
        QString question;
        QString reply;
        std::vector<Word> word;
        int length;
        int seconds;
        // int gameStatus;
        static int index;

        RecordRank *rank;

    public slots:
        void slot();

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

        void keyPressEvent(QKeyEvent *);
        void readFile(QString );
        void setWord();
        void setLabelQuestion(QString );
        void setLabelReply(QString );
        void setLabelSeconds(QString );
        void setLabelHint(QString );
        void setLCDCounter(int );

        void gameStart();
        void gameStop();
        void judge();

};
#endif // MAINWINDOW_H
