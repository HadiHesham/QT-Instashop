#include "purchaced.h"
#include "ui_purchaced.h"
#include "products2.h"

purchaced::purchaced(QString ar[],int s,QString b,QString t,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::purchaced)
{
    balance=b.toInt();
    total=t.toInt();
    p=s;
    ui->setupUi(this);
    for(int i=0;i<s;i++)
        ui->label_5->setText(ui->label_5->text()+ar[i]+"\n");
    ui->label_2->setText("Total: "+t);
    ui->label_3->setText("Account Balance: "+b);
}

purchaced::~purchaced()
{
    delete ui;
}

void purchaced::on_pushButton_2_clicked()
{
    if((ui->lineEdit_2->text()).toInt()>0){
        balance=balance+(ui->lineEdit_2->text()).toInt();
        ui->label_3->setText("Account Balance: "+QString::number(balance));
        ui->lineEdit_2->setText("");
    }
    else
        ui->lineEdit_2->setText("Cant enter a negative value");
}


void purchaced::on_pushButton_clicked()
{
    if(p!=0){
        if(balance>=total){
            ui->label_4->setText("Purchase is complete, enjoy your meal :)");
            balance=balance-total;
            ui->label_3->setText("Account Balance: "+QString::number(balance));
        }
        else
            ui->label_4->setText("Sorry, you cant proceed without recharging your balance");
    }
    else
        ui->label_4->setText("Cart is empty, if you want to buy items press 'Shop Again'");
}


void purchaced::on_pushButton_3_clicked()
{
    hide();
    products2 v(QString::number(balance));
    v.setModal(true);
    v.exec();
}

