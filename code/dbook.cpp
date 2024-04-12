#include "dbook.h"
#include "ui_dbook.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDialog>
#include <QTableView>
#include <QHBoxLayout>
#include <QMessageBox>
//#include "qdebug.h"
//#include "stdio.h"

DBook::DBook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DBook)
{
    ui->setupUi(this);
}

DBook::~DBook()
{
    delete ui;
}

void DBook::on_pushButtonborrow_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("DRIVER={SQL SERVER};" "SERVER=(local);" "DATABASE=library;");
    db.open();

    QString s;
    QSqlQueryModel *m=new QSqlQueryModel;

    s=QString("select*from book where bno=\'%1\' and stock>0;").arg(ui->lineEditbno->text());
    m->setQuery(s);
    if(m->rowCount()==0) QMessageBox::about(NULL, "图书馆", "没有库存!"); else {
        s=QString("insert into borrow values(\'%1\',\'%2\',GETDATE(),null,\'%3\');").arg(ui->lineEditcno->text()).arg(ui->lineEditbno->text()).arg("a1");
        m->setQuery(s);
        s=QString("update book set stock=stock-1 where bno=\'%1\'").arg(ui->lineEditbno->text());
        m->setQuery(s);
        QMessageBox::about(NULL, "图书馆", "借书成功!");
    }

    ui->lineEditbno->clear();
    ui->lineEditcno->clear();
}

void DBook::on_pushButtonreturn_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("DRIVER={SQL SERVER};" "SERVER=(local);" "DATABASE=library;");
    db.open();

    QString s;
    QSqlQueryModel *m=new QSqlQueryModel;

    s=QString("update borrow set return_date=GETDATE() where cno=\'%1\' and bno=\'%2\'").arg(ui->lineEditcno->text()).arg(ui->lineEditbno->text());
    m->setQuery(s);

    s=QString("update book set stock=stock+1 where bno=\'%1\'").arg(ui->lineEditbno->text());
    m->setQuery(s);

    QMessageBox::about(NULL, "图书馆", "还书成功!");
    ui->lineEditbno->clear();
    ui->lineEditcno->clear();
}

void DBook::on_pushButtonrecord_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("DRIVER={SQL SERVER};" "SERVER=(local);" "DATABASE=library;");
    db.open();

    QDialog *d = new QDialog;
    QTableView *v = new QTableView;
    QHBoxLayout *l = new QHBoxLayout;
    QString s;
    s=QString("select*from borrow where cno=\'%1\'").arg(ui->lineEditcno->text());

    l->addWidget(v);
    d->setLayout(l);
    QSqlQueryModel *m=new QSqlQueryModel;
    m->setQuery(s);
    v->setModel(m);
    d->adjustSize();
    d->show();

    ui->lineEditbno->clear();
    ui->lineEditcno->clear();
}
