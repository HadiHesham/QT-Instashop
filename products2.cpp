#include "products2.h"
#include "ui_products2.h"
#include "purchaced.h"

products2::products2(QString b,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::products2)
{
    ui->setupUi(this);
    ui->label_5->setText(ui->label_5->text()+b);
    Chicken[0]="None";
    Chicken[1]="Chicken Burger";
    Chicken[2]="Chicken Pasta";
    Chicken[3]="Chicken Wrap";
    Meat[0]="None";
    Meat[1]="Meat Burger";
    Meat[2]="Meat Pasta";
    Meat[3]="Meat Wrap";
    ChickenPrice[0]=0;
    ChickenPrice[1]=20;
    ChickenPrice[2]=40;
    ChickenPrice[3]=60;
    MeatPrice[0]=0;
    MeatPrice[1]=30;
    MeatPrice[2]=50;
    MeatPrice[3]=70;
    totalprice=0;
    NumOfItems=0;
    Purchased=0;
    Balance=b;
}
products2::~products2()
{
    delete ui;
}


void products2::on_pushButton_clicked()
{
   ui->label_3->setText("Number of items added: ");
   if(ui->comboBox->currentText()=="None" && ui->comboBox_2->currentText()=="None"){
       ui->label_3->setText("Choose an item first ");
       return;
   }
   for(int i=0;i<4;i++){
       if(Chicken[i]==ui->comboBox->currentText() && ui->comboBox->currentText()!="None"){
           totalprice=totalprice+ChickenPrice[i];
           NumOfItems++;
           PurchasedItems[Purchased]=Chicken[i]+": "+QString::number(ChickenPrice[i]);
           Purchased++;
       }
       if(Meat[i]==ui->comboBox_2->currentText() && ui->comboBox_2->currentText()!="None"){
           totalprice=totalprice+MeatPrice[i];
           NumOfItems++;
           PurchasedItems[Purchased]=Meat[i]+": "+QString::number(MeatPrice[i]);
           Purchased++;
       }
   }
   ui->label_3->setText("Items Price: "+QString::number(totalprice));
   ui->label_4->setText("Number of items added: "+QString::number(NumOfItems));
}


void products2::on_pushButton_2_clicked()
{
    hide();
    purchaced p(PurchasedItems,Purchased,Balance,QString::number(totalprice));
    p.setModal(true);
    p.exec();
}

