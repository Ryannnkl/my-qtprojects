#include "digitalclok.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    DigitalClok clock;
    clock.show();
    return app.exec();
}
