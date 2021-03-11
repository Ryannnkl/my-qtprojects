#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "button.h"

#include <QMainWindow>
#include "QLineEdit"

class Calculator : public QWidget
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);

public slots:
    void digitClicked();
    void unaryOperatorClicked();
    void additiveOperatorClicked();
    void multiplicativeOperatorClicked();
    void equalClicked();
    void pointClicked();
    void changeSingClicked();
    void backspaceClicked();
    void clear();
    void clearAll();
    void clearMemory();
    void readMemory();
    void setMemory();
    void addToMemory();
    void testeContextMenu();

private:
    Button *createButton(const QString &text, const char *member);
    void abortOperation();

    bool calculate(double rightOperand, const QString &pendingOperator);

    double sumInMemory;
    double sumSoFar;
    double factorSoFar;
    QString pendingAdditiveOperator;
    QString pendingMultiplicationOperator;
    bool waitingForOperand;

    QLineEdit *display;

    enum { NumDigitButtons = 10 };
    Button *digitButtons[NumDigitButtons];
};

#endif // CALCULATOR_H
