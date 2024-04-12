#ifndef DLOGIN_H
#define DLOGIN_H

#include <QDialog>

namespace Ui {
class DLogin;
}

class DLogin : public QDialog
{
    Q_OBJECT

public:
    explicit DLogin(QWidget *parent = 0);
    ~DLogin();

private slots:
    void on_pushButtonlogin_clicked();

private:
    Ui::DLogin *ui;
};

#endif // DLOGIN_H
