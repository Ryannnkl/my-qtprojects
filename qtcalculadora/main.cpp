#include "calculator.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Calculator calculadora;

    calculadora.show();

    return app.exec();
}
