#ifndef FIRSTDIALOG_H
#define FIRSTDIALOG_H

#include <QDialog>

namespace Ui {
class FirstDialog;
}

class FirstDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FirstDialog(QWidget *parent = nullptr);
    ~FirstDialog();

private slots:
    void on_pushButtonViewCart_clicked();

    void on_pushButtonBackToSelection_clicked();

    void on_pushButtonviewPay_clicked();

    void on_pushButtonviewConfirm_clicked();

    void on_pushButtonview_home_clicked();

    void on_pushButtoncoke_clicked();

    void on_pushButtonbiscuit_clicked();

    void on_pushButtonmilk_clicked();

    void on_pushButtonbread_clicked();

    void on_pushButton_clicked();

    void on_seedetails_clicked();


private:
    Ui::FirstDialog *ui;

};

#endif // FIRSTDIALOG_H
