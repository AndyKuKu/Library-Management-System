#ifndef DDLOGIN_H
#define DDLOGIN_H

#include <QDialog>

namespace Ui {
class DDLogin;
}

class DDLogin : public QDialog
{
    Q_OBJECT

public:
    explicit DDLogin(QWidget *parent = 0);
    ~DDLogin();

private slots:
    void on_pushButtonlogin_clicked();

private:
    Ui::DDLogin *ui;
};

#endif // DDLOGIN_H
