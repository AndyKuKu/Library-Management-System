#ifndef DSTORAGE_H
#define DSTORAGE_H

#include <QDialog>

namespace Ui {
class DStorage;
}

class DStorage : public QDialog
{
    Q_OBJECT

public:
    explicit DStorage(QWidget *parent = 0);
    ~DStorage();

private slots:
    void on_pushButtonstorageone_clicked();

    void on_pushButtonstorage_clicked();

private:
    Ui::DStorage *ui;
};

#endif // DSTORAGE_H
