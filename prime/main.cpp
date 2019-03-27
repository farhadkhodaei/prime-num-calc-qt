#include "InitialDialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    InitialDialog w;
    w.show();

    return a.exec();
}
