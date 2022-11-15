#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "firstdialog.h"
#include "dialogbill.h"
#include<QMessageBox>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    FirstDialog *first_Dialog;
    Dialogbill *second_Dialog;
    int itemPrice;
    int recieptNum;
    QString customerName, cardNum;

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
