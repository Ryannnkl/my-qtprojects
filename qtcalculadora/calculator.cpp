#include "calculator.h"
#include "button.h"

#include "QGridLayout"
#include "QFont"
#include "QtMath"

Calculator::Calculator(QWidget *parent)
    : QWidget(parent), sumInMemory(0.0), sumSoFar(0.0)
    , factorSoFar(0.0), waitingForOperand(true)
{
    display = new QLineEdit("0");
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    display->setMaxLength(15);

    QFont font = display->font();
    font.setPointSize(font.pointSize() + 8);
    display->setFont(font);

    for(int i = 0; i < NumDigitButtons; ++i)
        digitButtons[i] = createButton(QString::number(i), SLOT(digitClicked()));

    Button *pointButton = createButton(tr("."), SLOT(pointClicked()));
    Button *changeSingButton = createButton(tr("\302\261"), SLOT(changeSingClicked()));

    Button *backspaceButton = createButton(tr("Backspace"), SLOT(backspaceClicked()));
    Button *clearButton = createButton(tr("Clear"), SLOT(clear()));
    Button *clearAllButton = createButton(tr("Clear All"), SLOT(clearAll()));

    Button *clearMemoryButton = createButton(tr("MC"), SLOT(clearMemory()));
    Button *readMemoryButton = createButton(tr("MR"), SLOT(readMemory()));
    Button *setMemoryButton = createButton(tr("MS"), SLOT(setMemory()));
    Button *addToMemoryButton = createButton(tr("M+"), SLOT(addToMemory()));

    Button *divisionButton = createButton(tr("\303\267"), SLOT(multiplicativeOperatorClicked()));
    Button *timesButton = createButton(tr("\303\227"), SLOT(multiplicativeOperatorClicked()));
    Button *minusButton = createButton(tr("-"), SLOT(additiveOperatorClicked()));
    Button *plusButton = createButton(tr("+"), SLOT(additiveOperatorClicked()));

    Button *squareRootButton  = createButton(tr("Sqrt"), SLOT(unaryOperatorClicked()));
    Button *powerButton = createButton(tr("x\302\262"), SLOT(unaryOperatorClicked()));
    Button *reciprocalButton = createButton(tr("1/x"), SLOT(unaryOperatorClicked()));
    Button *equalButton = createButton(tr("="), SLOT(equalClicked()));

    QGridLayout *mainLayot = new QGridLayout;

    mainLayot->setSizeConstraint(QLayout::SetMinAndMaxSize);
    mainLayot->addWidget(display, 0, 0, 1, 6);
    mainLayot->addWidget(backspaceButton, 1, 4, 1, 2);
    mainLayot->addWidget(clearButton, 1, 2, 1, 2);
    mainLayot->addWidget(clearAllButton, 1, 0, 1, 2);

    mainLayot->addWidget(clearMemoryButton, 2, 0);
    mainLayot->addWidget(readMemoryButton, 3, 0);
    mainLayot->addWidget(setMemoryButton, 4, 0);
    mainLayot->addWidget(addToMemoryButton, 5, 0);

    for(int i = 0; i< NumDigitButtons; i++) {
        int row = ((9 - i) / 3) + 2;
        int column = ((i - 1) % 3) + 1;
        mainLayot->addWidget(digitButtons[i], row, column);
    }

    mainLayot->addWidget(digitButtons[0], 5, 1);
    mainLayot->addWidget(pointButton, 5, 2);
    mainLayot->addWidget(changeSingButton, 5, 3);

    mainLayot->addWidget(divisionButton, 2, 4);
    mainLayot->addWidget(timesButton, 3, 4);
    mainLayot->addWidget(minusButton, 4, 4);
    mainLayot->addWidget(plusButton, 5, 4);

    mainLayot->addWidget(squareRootButton, 2, 5);
    mainLayot->addWidget(powerButton, 3, 5);
    mainLayot->addWidget(reciprocalButton, 4, 5);
    mainLayot->addWidget(equalButton, 5, 5);

    setLayout(mainLayot);

    setWindowTitle("Calculadora");
}



void Calculator::digitClicked()
{
    Button *clickedButton = qobject_cast<Button *>(sender());
    int digitValue = clickedButton->text().toInt();

    if(display->text() == "0" && digitValue == 0.0)
        return;

    if(waitingForOperand) {
        display->clear();
        waitingForOperand = false;
    }
    display->setText(display->text() + QString::number(digitValue));
}

void Calculator::unaryOperatorClicked()
{
    Button *clickedButton = qobject_cast<Button *>(sender());
    QString clickedOperator = clickedButton->text();

    double operand = display->text().toDouble();
    double result = 0.0;

    if(clickedOperator == tr("Sqrt")) {
        if(operand < 0.0) {
            abortOperation();
            return;
        }
        result = std::sqrt(operand);
    } else if(clickedOperator == tr("x\302\262")) {
        result = std::pow(operand, 2.0);
    } else if(clickedOperator == tr("1/x")) {
        if(operand == 0.0) {
            abortOperation();
            return;
        }
        result = 1.0 / operand;
    }

    display->setText(QString::number(result));
    waitingForOperand = true;
}

void Calculator::additiveOperatorClicked()
{
    Button *clickedButton = qobject_cast<Button *>(sender());
    if(!clickedButton)
        return;
    QString clickedOperator = clickedButton->text();
    double operand = display->text().toDouble();

    if(!pendingMultiplicationOperator.isEmpty()) {
        if(!calculate(operand, pendingAdditiveOperator)) {
            abortOperation();
            return;
        }
        display->setText(QString::number(factorSoFar));
        operand = factorSoFar;
        factorSoFar = 0;
        pendingAdditiveOperator.clear();
    }

    if (!pendingAdditiveOperator.isEmpty()) {
        if(!calculate(operand, pendingAdditiveOperator)) {
            abortOperation();
            return;
        }
        display->setText(QString::number(sumSoFar));
    } else {
        sumSoFar = operand;
    }

    pendingAdditiveOperator = clickedOperator;
    waitingForOperand = true;
}

void Calculator::multiplicativeOperatorClicked()
{
    Button *clickedButton = qobject_cast<Button *>(sender());
    if(!clickedButton)
        return;
    QString clickedOperator = clickedButton->text();
    double operand = display->text().toDouble();

    if(!pendingMultiplicationOperator.isEmpty()) {
        if(!calculate(operand, pendingMultiplicationOperator)) {
            abortOperation();
            return;
        }
        display->setText(QString::number(factorSoFar));
    } else {
        factorSoFar = operand;
    }

    pendingMultiplicationOperator =  clickedOperator;
    waitingForOperand =  true;
}

void Calculator::equalClicked()
{
    double operand = display->text().toDouble();

    if(!pendingMultiplicationOperator.isEmpty()) {
        if(!calculate(operand, pendingMultiplicationOperator)) {
            abortOperation();
            return;
        }
        operand =  factorSoFar;
        factorSoFar =  0.0;
        pendingMultiplicationOperator.clear();
    }
    if(!pendingAdditiveOperator.isEmpty()) {
        if(!calculate(operand, pendingAdditiveOperator)) {
            abortOperation();
            return;
        }
        pendingAdditiveOperator.clear();
    } else {
        sumSoFar = operand;
    }

    display->setText(QString::number(sumSoFar));
    sumSoFar = 0.0;
    waitingForOperand = true;
}

void Calculator::pointClicked()
{
    QString text = display->text();
    double value = text.toDouble();

    if(value > 0.0) {
        text.prepend(tr("-"));
    } else if(value < 0.0) {
        text.remove(0,1);
    }

    display->setText(text);
}

void Calculator::backspaceClicked()
{
    if (waitingForOperand)
        return;

    QString text = display->text();
    text.chop(1);
    if(text.isEmpty()) {
        text = "0";
        waitingForOperand = true;
    }
    display->setText(text);
}

void Calculator::clear()
{
    if(waitingForOperand)
        return;
    display->setText("0");
    waitingForOperand = true;
}

void Calculator::clearAll()
{
    sumSoFar = 0.0;
    factorSoFar = 0.0;
    pendingAdditiveOperator.clear();
    pendingMultiplicationOperator.clear();
    display->setText("0");
    waitingForOperand = true;
}

void Calculator::clearMemory()
{
    sumInMemory =  0.0;
}

void Calculator::readMemory()
{
    display->setText(QString::number(sumInMemory));
    waitingForOperand = true;
}

void Calculator::setMemory()
{
    equalClicked();
    sumInMemory = display->text().toDouble();
}

void Calculator::addToMemory()
{
    equalClicked();
    sumInMemory += display->text().toDouble();
}

Button *Calculator::createButton(const QString &text, const char *member)
{
    Button *button = new Button(text);
    connect(button, SIGNAL(clicked()), this, member);
    return button;
}

void Calculator::abortOperation()
{
    clearAll();
    display->setText(tr("####"));
}

bool Calculator::calculate(double rightOperand, const QString &pendingOperator)
{
    if(pendingOperator == tr("+")) {
        sumSoFar += rightOperand;
    } else if(pendingOperator == tr("-")) {
        sumSoFar -= rightOperand;
    } else if(pendingOperator == tr("\303\227")) {
        factorSoFar *= rightOperand;
    } else if(pendingOperator == tr("\303\267")) {
        if( rightOperand == 0.0 )
            return false;
        factorSoFar /= rightOperand;
    }
    return true;
}
void Calculator::changeSingClicked() {

}