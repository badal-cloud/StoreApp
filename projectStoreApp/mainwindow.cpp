#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    QPixmap kirana("/home/badal/Documents/projectStoreApp/kirana.png");
    int wi=ui->kiranapic->width();
    int he=ui->kiranapic->height();
    ui->kiranapic->setPixmap(kirana.scaled(wi,he,Qt::KeepAspectRatio));



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString user=ui->lineEdit_userName->text();
    QString pass=ui->lineEdit_pass->text();

    if(user=="Rohan" && pass=="123!@#")
    {
        QMessageBox::information(this,"Info","Welcome to Kirana Store");
        FirstDialog *first_Dialog=new FirstDialog(this);
        first_Dialog->show();


    }
    else
    {

        QMessageBox::information(this,"Info","UserName & Password is Incorrect ");

    }
}
