#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "products2.h"
#include <QFile>
#include <QTextStream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QFile file("user saved.txt");
    ui->setupUi(this);
    Names[0]="Hadi";
    Names[1]="Amr";
    Names[2]="Azouz";
    Passwords[0]="Zah2an";
    Passwords[1]="Kofta";
    Passwords[2]="Ayes2at";
    count=0;
    for(int i=0;i<3;i++)
        Balance[i]=QString::number((i+1)*100);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    bool found=false;
    ui->label_5->setText("Balance");
    while(count<3 && found==false){
        if(Names[count]==ui->lineEdit->text())
            found=true;
        count++;
    }

    if(found==true){
        if(Passwords[count-1]==ui->lineEdit_2->text()){
            ui->label_4->setText("Login Successful");
            ui->label_5->setText("Balance: "+Balance[count-1]);
            products2 v(Balance[count-1]);
            v.setModal(true);
            v.exec();
        }
        else
            ui->label_4->setText("Name is correct, password is wrong");
    }
    else
        ui->label_4->setText("Name not found");
    count=0;
}




