#include "dlogin.h"
#include "ui_dlogin.h"

DLogin::DLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DLogin)
{
    ui->setupUi(this);
}

DLogin::~DLogin()
{
    delete ui;
}

void DLogin::on_pushButtonlogin_clicked()
{

}
