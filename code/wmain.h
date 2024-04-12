#ifndef WMAIN_H
#define WMAIN_H

#include <QMainWindow>

namespace Ui {
class WMain;
}

class WMain : public QMainWindow
{
    Q_OBJECT

public:
    explicit WMain(QWidget *parent = 0);
    ~WMain();

private slots:
    void on_pushButtonquery_clicked();

    void on_pushButtonstorage_clicked();

    void on_pushButtonbook_clicked();

    void on_pushButtoncard_clicked();

private:
    Ui::WMain *ui;
};

#endif // WMAIN_H
