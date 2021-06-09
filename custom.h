#ifndef CUSTOM_H
#define CUSTOM_H

#include <QMainWindow>

namespace Ui {
class Custom;
}

class Custom : public QMainWindow
{
    Q_OBJECT

public:
    explicit Custom(QWidget *parent = nullptr);
    ~Custom();

signals:
    void sendCustom(QString location);

private slots:

    void on_pushButton_clicked();

private:
    Ui::Custom *ui;
};

#endif // CUSTOM_H
