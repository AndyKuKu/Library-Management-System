#include "dcard.h"
#include "ui_dcard.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>

DCard::DCard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DCard)
{
    ui->setupUi(this);
}

DCard::~DCard()
{
    delete ui;
}

void DCard::on_pushButtonestablish_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("DRIVER={SQL SERVER};" "SERVER=(local);" "DATABASE=library;");
    db.open();

    QString s;
    s=QString("insert into card values(\'%1\',\'%2\',\'%3\',\'%4\');").arg(ui->lineEditcno->text()).arg(ui->lineEditname->text()).arg(ui->lineEditdepartment->text()).arg(ui->lineEdittype->text());
    QSqlQueryModel *m=new QSqlQueryModel;
    m->setQuery(s);

    QMessageBox::about(NULL, "图书馆", "新建借书证成功!");
    ui->lineEditcno->clear();
    ui->lineEditname->clear();
    ui->lineEditdepartment->clear();
    ui->lineEdittype->clear();
}

void DCard::on_pushButtoncancel_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("DRIVER={SQL SERVER};" "SERVER=(local);" "DATABASE=library;");
    db.open();

    QString s;
    QSqlQueryModel *m=new QSqlQueryModel;

    s=QString("select*from borrow where cno=\'%1\' and return_date is null").arg(ui->lineEditcno->text());
    m->setQuery(s);
    if(m->rowCount()!=0) QMessageBox::about(NULL, "图书馆", "有书本没还!"); else {
        s=QString("delete from borrow where cno=\'%1\';").arg(ui->lineEditcno->text());
        m->setQuery(s);
        s=QString("delete from card where cno=\'%1\';").arg(ui->lineEditcno->text());
        m->setQuery(s);
        QMessageBox::about(NULL, "图书馆", "注销借书证成功!");
    }
    ui->lineEditcno->clear();
    ui->lineEditname->clear();
    ui->lineEditdepartment->clear();
    ui->lineEdittype->clear();
}
