#ifndef RANKLIST_H
#define RANKLIST_H

#include <QDialog>
#include <vector>
#include <sstream>

namespace Ui {
class ranklist;
}

class ranklist : public QDialog
{
    Q_OBJECT

public:
    explicit ranklist(QWidget *parent = nullptr);
    ~ranklist();
    void sortForGrade(std::vector<double>&, std::vector<QString>&);

private slots:
    void on_pushButton_clicked();

private:
    Ui::ranklist *ui;
    std::vector <double>time;
    std::vector <QString>name;
};

#endif // RANKLIST_H
