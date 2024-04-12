#include "dstorage.h"
#include "ui_dstorage.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

DStorage::DStorage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DStorage)
{
    ui->setupUi(this);
}

DStorage::~DStorage()
{
    delete ui;
}

void DStorage::on_pushButtonstorageone_clicked()
{

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("DRIVER={SQL SERVER};" "SERVER=(local);" "DATABASE=library;");
    db.open();
    QString s;
    QSqlQueryModel *m=new QSqlQueryModel;

    s=QString("select*from book where bno=\'%1\'").arg(ui->lineEditbno->text());
    m->setQuery(s);
    if(m->rowCount()==0){
        s=QString("insert into book values(\'%1\',\'%2\',\'%3\',\'%4\',\'%5\',\'%6\',\'%7\',\'%8\',\'%9\')").arg(ui->lineEditbno->text()).arg(ui->lineEditcategory->text()).arg(ui->lineEdittitle->text()).arg(ui->lineEditpress->text()).arg(ui->lineEdityear->text()).arg(ui->lineEditauthor->text()).arg(ui->lineEditprice->text()).arg(ui->lineEditnumber->text()).arg(ui->lineEditnumber->text());
        m->setQuery(s);
    }else{
        s=QString("update book set stock=stock+%1,total=total+%2 where bno=\'%3\'").arg(ui->lineEditnumber->text()).arg(ui->lineEditnumber->text()).arg(ui->lineEditbno->text());
        m->setQuery(s);
    }

    QMessageBox::about(NULL, "图书馆", "书籍入库成功!");
    ui->lineEditbno->clear();
    ui->lineEditcategory->clear();
    ui->lineEdittitle->clear();
    ui->lineEditpress->clear();
    ui->lineEdityear->clear();
    ui->lineEditauthor->clear();
    ui->lineEditprice->clear();
    ui->lineEditnumber->clear();
    ui->lineEditaddress->clear();
}

void DStorage::on_pushButtonstorage_clicked()
{
    QFile f(ui->lineEditaddress->text());
    f.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream txtInput(&f);

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("DRIVER={SQL SERVER};" "SERVER=(local);" "DATABASE=library;");
    db.open();

    QString s,lineStr,bno,category,title,press,year,author,price,number;
    QSqlQueryModel *m=new QSqlQueryModel;
    int i;

    while(!txtInput.atEnd())
    {
        lineStr = txtInput.readLine();
        i=-1; bno=category=title=press=year=author=price=number="";
        while(lineStr[++i]!=' ')bno+=lineStr[i];
        while(lineStr[++i]!=' ')category+=lineStr[i];
        while(lineStr[++i]!=' ')title+=lineStr[i];
        while(lineStr[++i]!=' ')press+=lineStr[i];
        while(lineStr[++i]!=' ')year+=lineStr[i];
        while(lineStr[++i]!=' ')author+=lineStr[i];
        while(lineStr[++i]!=' ')price+=lineStr[i];
        while(lineStr[++i]!='\0')number+=lineStr[i];

        s=QString("select*from book where bno=\'%1\'").arg(bno);
        m->setQuery(s);
        if(m->rowCount()==0){
            s=QString("insert into book values(\'%1\',\'%2\',\'%3\',\'%4\',\'%5\',\'%6\',\'%7\',\'%8\',\'%9\')").arg(bno).arg(category).arg(title).arg(press).arg(year).arg(author).arg(price).arg(number).arg(number);
            m->setQuery(s);
        } else {
            s=QString("update book set stock=stock+%1,total=total+%2 where bno=\'%3\'").arg(number).arg(number).arg(bno);
            m->setQuery(s);
        }
    }

    f.close();
    QMessageBox::about(NULL, "图书馆", "书籍入库成功!");
    ui->lineEditbno->clear();
    ui->lineEditcategory->clear();
    ui->lineEdittitle->clear();
    ui->lineEditpress->clear();
    ui->lineEdityear->clear();
    ui->lineEditauthor->clear();
    ui->lineEditprice->clear();
    ui->lineEditnumber->clear();
    ui->lineEditaddress->clear();
}
