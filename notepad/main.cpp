#include "qwriteapplication.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWriteApplication w;
    w.setWindowTitle("QWrite");

    w.show();
    return a.exec();
}
