#include "wmain.h"
#include "ui_wmain.h"
#include "dquery.h"
#include "dstorage.h"
#include "dbook.h"
#include "dcard.h"

WMain::WMain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WMain)
{
    ui->setupUi(this);
}

WMain::~WMain()
{
    delete ui;
}

void WMain::on_pushButtonquery_clicked()
{
    DQuery d;
    d.show();
    if(d.exec()==QDialog::Accepted){
        WMain w;
        w.show();
    }
}

void WMain::on_pushButtonstorage_clicked()
{
    DStorage d;
    d.show();
    if(d.exec()==QDialog::Accepted){
        WMain w;
        w.show();
    }
}

void WMain::on_pushButtonbook_clicked()
{
    DBook d;
    d.show();
    if(d.exec()==QDialog::Accepted){
        WMain w;
        w.show();
    }
}

void WMain::on_pushButtoncard_clicked()
{
    DCard d;
    d.show();
    if(d.exec()==QDialog::Accepted){
        WMain w;
        w.show();
    }
}
