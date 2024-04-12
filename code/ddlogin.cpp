#include "ddlogin.h"
#include "ui_ddlogin.h"
#include "wmain.h"

DDLogin::DDLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DDLogin)
{
    ui->setupUi(this);
}

DDLogin::~DDLogin()
{
    delete ui;
}

void DDLogin::on_pushButtonlogin_clicked()
{
    WMain w;
    w.show();
}
