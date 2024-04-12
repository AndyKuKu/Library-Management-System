#include "dquery.h"
#include "ui_dquery.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDialog>
#include <QTableView>
#include <QHBoxLayout>
#include <QSqlQueryModel>

DQuery::DQuery(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DQuery)
{
    ui->setupUi(this);
}

DQuery::~DQuery()
{
    delete ui;
}

void DQuery::on_pushButtonqueryall_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("DRIVER={SQL SERVER};" "SERVER=(local);" "DATABASE=library;");
    db.open();

    QDialog *d = new QDialog;
    QTableView *v = new QTableView;
    QHBoxLayout *l = new QHBoxLayout;
    l->addWidget(v);
    d->setLayout(l);
    QSqlQueryModel *m=new QSqlQueryModel;
    m->setQuery("select*from book");
    v->setModel(m);
    d->adjustSize();
    d->show();

    ui->lineEditcategory->clear();
    ui->lineEdittitle->clear();
    ui->lineEditpress->clear();
    ui->lineEditauthor->clear();
    ui->lineEdityear1->clear();
    ui->lineEdityear2->clear();
    ui->lineEditprice1->clear();
    ui->lineEditprice2->clear();
}

void DQuery::on_pushButtonquery_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("DRIVER={SQL SERVER};" "SERVER=(local);" "DATABASE=library;");
    db.open();

    QDialog *d = new QDialog;
    QTableView *v = new QTableView;
    QHBoxLayout *l = new QHBoxLayout;
    QString s;

    s=QString("select*from book where 0=0");
    if(ui->lineEditcategory->text()!="")s=s+QString(" and category=\'%1\'").arg(ui->lineEditcategory->text());
    if(ui->lineEdittitle->text()!="")s=s+QString(" and title=\'%1\'").arg(ui->lineEdittitle->text());
    if(ui->lineEditpress->text()!="")s=s+QString(" and press=\'%1\'").arg(ui->lineEditpress->text());
    if(ui->lineEditauthor->text()!="")s=s+QString(" and author=\'%1\'").arg(ui->lineEditauthor->text());
    if(ui->lineEdityear1->text()!=""&&ui->lineEdityear2->text()!="")s=s+QString(" and (year between %1 and %2)").arg(ui->lineEdityear1->text()).arg(ui->lineEdityear2->text());
    if(ui->lineEditprice1->text()!=""&&ui->lineEditprice2->text()!="")s=s+QString(" and (price between %1 and %2)").arg(ui->lineEditprice1->text()).arg(ui->lineEditprice2->text());
    s=s+";";

    l->addWidget(v);
    d->setLayout(l);
    QSqlQueryModel *m=new QSqlQueryModel;
    m->setQuery(s);
    v->setModel(m);
    d->adjustSize();
    d->show();

    ui->lineEditcategory->clear();
    ui->lineEdittitle->clear();
    ui->lineEditpress->clear();
    ui->lineEditauthor->clear();
    ui->lineEdityear1->clear();
    ui->lineEdityear2->clear();
    ui->lineEditprice1->clear();
    ui->lineEditprice2->clear();
}
