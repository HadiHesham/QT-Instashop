#ifndef PRODUCTS2_H
#define PRODUCTS2_H

#include <QDialog>

namespace Ui {
class products2;
}

class products2 : public QDialog
{
    Q_OBJECT

public:
    explicit products2(QString b,QWidget *parent = nullptr);
    ~products2();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::products2 *ui;
    QString Chicken[4];
    QString Meat[4];
    int ChickenPrice[4];
    int MeatPrice[4];
    int totalprice,NumOfItems,Purchased;
    QString PurchasedItems[50];
    QString Balance;
};

#endif // PRODUCTS2_H
