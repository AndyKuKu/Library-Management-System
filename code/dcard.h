#ifndef DCARD_H
#define DCARD_H

#include <QDialog>

namespace Ui {
class DCard;
}

class DCard : public QDialog
{
    Q_OBJECT

public:
    explicit DCard(QWidget *parent = 0);
    ~DCard();

private slots:
    void on_pushButtonestablish_clicked();

    void on_pushButtoncancel_clicked();

private:
    Ui::DCard *ui;
};

#endif // DCARD_H
