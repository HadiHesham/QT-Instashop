#ifndef PURCHACED_H
#define PURCHACED_H

#include <QDialog>

namespace Ui {
class purchaced;
}

class purchaced : public QDialog
{
    Q_OBJECT

public:
    explicit purchaced(QString ar[],int s,QString b,QString t,QWidget *parent = nullptr);
    ~purchaced();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::purchaced *ui;
    int balance;
    int total,p;
};

#endif // PURCHACED_H
