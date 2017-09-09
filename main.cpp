#include "tabgeneratormain.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    tabGeneratorMain w;
    w.show();

    return a.exec();
}
