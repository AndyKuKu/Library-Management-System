#include "wmain.h"
#include <QApplication>
#include "dlogin.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DLogin d;
    if(d.exec()==QDialog::Accepted){
        WMain w;
        w.show();
        return a.exec();
    }

    return a.exec();
}
