#include "firstdialog.h"
#include "ui_firstdialog.h"
#include<vector>
#include<string>
#include<QString>
#include<fstream>
#include<QPixmap>
#include<QMessageBox>
#include<QFile>
#include<QTextStream>
#include<QPrinter>
#include <QPrintDialog>

FirstDialog::FirstDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FirstDialog)
{
    ui->setupUi(this);

    QPixmap img("/home/badal/Documents/projectStoreApp/kirana.png");
    int a=ui->labelimgk->width();
    int b=ui->labelimgk->height();
    ui->labelimgk->setPixmap(img.scaled(a,b,Qt::KeepAspectRatio));


    QPixmap im("/home/badal/Documents/projectStoreApp/bill2.png");
    int d=ui->bill2img->width();
    int e=ui->bill2img->height();
    ui->bill2img->setPixmap(im.scaled(d,e,Qt::KeepAspectRatio));

    QPixmap image("/home/badal/Documents/projectStoreApp/bill.png");
    int x=ui->billimg->width();
    int y=ui->billimg->height();
    ui->billimg->setPixmap(image.scaled(x,y,Qt::KeepAspectRatio));


    QPixmap pimg("/home/badal/Documents/projectStoreApp/payment.jpg");
    int ac=ui->paymentimg->width();
    int bc=ui->paymentimg->height();
    ui->paymentimg->setPixmap(pimg.scaled(ac,bc,Qt::KeepAspectRatio));


    QPixmap imge("/home/badal/Documents/projectStoreApp/cart.jpeg");
    int ab=ui->cartimg->width();
    int ba=ui->cartimg->height();
    ui->cartimg->setPixmap(imge.scaled(ab,ba,Qt::KeepAspectRatio));



    QPixmap coke("/home/badal/Documents/projectStoreApp/coke.jpeg");
    int w=ui->cokepic->width();
    int h=ui->cokepic->height();
    ui->cokepic->setPixmap(coke.scaled(w,h,Qt::KeepAspectRatio));

    QPixmap parle("/home/badal/Documents/projectStoreApp/parle.jpeg");
    int wi=ui->parlepic->width();
    int he=ui->parlepic->height();
    ui->parlepic->setPixmap(parle.scaled(wi,he,Qt::KeepAspectRatio));

    QPixmap amul("/home/badal/Documents/projectStoreApp/Amul.jpg");
    int wid=ui->amulpic->width();
    int hei=ui->amulpic->height();
    ui->amulpic->setPixmap(amul.scaled(wid,hei,Qt::KeepAspectRatio));

    QPixmap bread("/home/badal/Documents/projectStoreApp/bread.jpg");
    int width=ui->breadpic->width();
    int height=ui->breadpic->height();
    ui->breadpic->setPixmap(bread.scaled(width,height,Qt::KeepAspectRatio));
}

FirstDialog::~FirstDialog()
{
    delete ui;
}

struct itemPrice
{
    std::string itemName;
    int itemPrice;
};

//global variable
std::vector<itemPrice> v;
int total=0;

//used for navigation

void FirstDialog::on_pushButtonViewCart_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);

   std::  string str;
     for(int i=0; i < v.size();i++)
     {
        str=v[i].itemName + "\t\t" +std::to_string(v[i].itemPrice);
        ui->list_itemlist->addItem(str.c_str());
        total += v[i].itemPrice;
     }
     str=std::to_string(total);
     ui->totalprice->setText(str.c_str());

}

void FirstDialog::on_pushButtonBackToSelection_clicked()
{
    ui->list_itemlist->clear();
       ui->stackedWidget->setCurrentIndex(0);
}

void FirstDialog::on_pushButtonviewPay_clicked()
{

     std::string str=std::to_string(total);
     ui->totalprice_Pay->setText(str.c_str());

     ui->stackedWidget->setCurrentIndex(2);
}

struct reciptinfo
{
    int recieptNum;
    QString customerName, cardNum;
};


void FirstDialog::on_pushButtonviewConfirm_clicked()
{
    std::ofstream outputFile;
    reciptinfo ri;
    ri.recieptNum = rand()%(100000000-1000000 + 1)+ 10000000;
    ri.customerName=ui->textEditName ->toPlainText();
    ri.cardNum=ui->textEditCardNum->toPlainText();

    outputFile.open("SalesData.txt",std::ios::app);
    if(outputFile)
    {
        outputFile<<"Receipt Number:"<<ri.recieptNum<<"\n";
        outputFile<<"Customer Name:"<<ri.customerName.toStdString()<<"\n";
        outputFile<<"Card Information:"<<ri.cardNum.toStdString()<<"\n";
        outputFile<<"------------------------------------------\n";
        outputFile<<"Items\t\tPrice\n";
        for(int i=0; i<v.size();i++)
        {
            outputFile<<v[i].itemName <<"\t\t"<< v[i].itemPrice<<"\n";
        }
         outputFile<<"\nTotal:\t\t"<<total<<"\n\n\n End of this Receipt \n\n\n ";
    }

    //create a another txt file

//     QFile file("/home/badal/Documents/build-projectStoreApp-Desktop-Debug");
//     QString filename=ui->textEditName->toPlainText();
//     file.setFileName(filename);
//     if(!file.open(QFile::WriteOnly | QFile::Text))
//     {
//         QMessageBox::warning(this,"warn","file not open");
//     }


    std::ofstream outputFil;
    reciptinfo rw;
    rw.recieptNum = rand()%(100000000-1000000 + 1)+ 10000000;
    rw.customerName=ui->textEditName ->toPlainText();
    rw.cardNum=ui->textEditCardNum->toPlainText();

    outputFil.open("RWData.txt",std::ios::app);
    if(outputFil)
    {
        outputFil<<"Receipt Number:"<<rw.recieptNum<<"\n";
        outputFil<<"Customer Name:"<<rw.customerName.toStdString()<<"\n";
        outputFil<<"Card Information:"<<rw.cardNum.toStdString()<<"\n";
        outputFil<<"------------------------------------------\n";
        outputFil<<"Items\t\tPrice\n";
        for(int i=0; i<v.size();i++)
        {
            outputFil<<v[i].itemName <<"\t\t"<< v[i].itemPrice<<"\n";
        }
         outputFil<<"\nTotal:\t\t"<<total<<"\n\n\n End of this Receipt \n\n\n ";
    }









    QMessageBox::StandardButton reply= QMessageBox::question(this,"Bill Detail","Do you want see detail" , QMessageBox:: Yes | QMessageBox:: No);
    if(reply==QMessageBox::Yes)
    {

       ui->stackedWidget->setCurrentIndex(3);
    }
    else
    {
        QApplication Quit();

    }




 ui->plainTextEdit->clear();

}

void FirstDialog::on_pushButtonview_home_clicked()
{
    ui->list_itemlist->clear();
    ui->textEditCardNum->clear();
    ui->textEditName ->clear();
    v.clear();
    total=0;
    ui->stackedWidget->setCurrentIndex(0);
}

//adding add items

void FirstDialog::on_pushButtoncoke_clicked()
{

    itemPrice ip;
    ip.itemName ="Coke";
    ip.itemPrice=40;

    v.push_back(ip);



//    ui->dummy-setText(v[0].c_str());
}

void FirstDialog::on_pushButtonbiscuit_clicked()
{
    itemPrice ip;
    ip.itemName ="Parle-G";
    ip.itemPrice=10;

    v.push_back(ip);
}

void FirstDialog::on_pushButtonmilk_clicked()
{
    itemPrice ip;
    ip.itemName ="Amul Milk";
    ip.itemPrice=36;

    v.push_back(ip);
}

void FirstDialog::on_pushButtonbread_clicked()
{
    itemPrice ip;
    ip.itemName ="Bread";
    ip.itemPrice=40;

    v.push_back(ip);
}

void FirstDialog::on_pushButton_clicked() //home
{
   QFile File("RWData.txt");
   File.remove();
   ui->plainTextEdit->clear();
    ui->stackedWidget->setCurrentIndex(4);
}

void FirstDialog::on_seedetails_clicked()
{
    QFile file("/home/badal/Documents/build-projectStoreApp-Desktop-Debug/RWData.txt");
    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this,"title","file not open");
    }
    QTextStream in(&file);
    QString text=in.readAll();

    ui->plainTextEdit->setPlainText(text);

    file.close();
}


