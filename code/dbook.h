#ifndef DBOOK_H
#define DBOOK_H

#include <QDialog>

namespace Ui {
class DBook;
}

class DBook : public QDialog
{
    Q_OBJECT

public:
    explicit DBook(QWidget *parent = 0);
    ~DBook();

private slots:
    void on_pushButtonborrow_clicked();

    void on_pushButtonreturn_clicked();

    void on_pushButtonrecord_clicked();

private:
    Ui::DBook *ui;
};

#endif // DBOOK_H
