#ifndef DQUERY_H
#define DQUERY_H

#include <QDialog>

namespace Ui {
class DQuery;
}

class DQuery : public QDialog
{
    Q_OBJECT

public:
    explicit DQuery(QWidget *parent = 0);
    ~DQuery();

private slots:
    void on_pushButtonqueryall_clicked();

    void on_pushButtonquery_clicked();

private:
    Ui::DQuery *ui;
};

#endif // DQUERY_H
