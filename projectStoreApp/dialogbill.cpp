#include "dialogbill.h"
#include "ui_dialogbill.h"
#include<QFile>
#include<QTextStream>
#include<QMessageBox>

Dialogbill::Dialogbill(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogbill)
{
    ui->setupUi(this);


}

Dialogbill::~Dialogbill()
{
    delete ui;



}

void Dialogbill::on_pushButton_clicked() //write
{

}

void Dialogbill::on_pushButton_2_clicked() //read
{

}
