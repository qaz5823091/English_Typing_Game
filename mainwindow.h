#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QKeyEvent>
#include <vector>
#include "Word.h"
#include "Timer.h"
#include "RecordrRank.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;

    Timer timer;
    QString question;
    QString reply;
    std::vector<Word> word;
    int length;
    static int index;

    RecordRank *rank;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void keyPressEvent(QKeyEvent *);
    void readFile(QString );
    void setWord();
    void setLabelQuestion(QString );
    void setLabelReply(QString );
    void setLabelSeconds(QString );

};
#endif // MAINWINDOW_H
