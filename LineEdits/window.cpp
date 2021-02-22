#include "window.h"

#include <QGroupBox>
#include "QGridLayout"
#include "QLabel"
#include <QComboBox>

Window::Window(QWidget *parent)
    : QWidget(parent)
{
    QGroupBox *echoGroup = new QGroupBox(tr("echo"));

    QLabel *echoLabel = new QLabel(tr("Mode:"));
    QComboBox *echoComboBox = new QComboBox;
    echoComboBox->addItem(tr("Normal"));
    echoComboBox->addItem(tr("Password"));
    echoComboBox->addItem(tr("passwordEchoEdit"));
    echoComboBox->addItem(tr("No echo"));

    echoLineEdit = new QLineEdit;
    echoLineEdit->setPlaceholderText("Placeholder Text");
    echoLineEdit->setFocus();

    QGroupBox *validatorGroup = new QGroupBox(tr("Validator"));

    QLabel *validatorLabel = new QLabel(tr("Type:"));
    QComboBox *validatorComboBox = new QComboBox;
    validatorComboBox->addItem(tr("No validator"));
    validatorComboBox->addItem(tr("Integer validator"));
    validatorComboBox->addItem(tr("Double validator"));

    validatorLineEdit = new QLineEdit;
    validatorLineEdit->setPlaceholderText("Placeholder Text");


    QGroupBox *alignmentGroup = new QGroupBox(tr("Alignment"));

    QLabel *alignmentLabel = new QLabel(tr("Type:"));
    QComboBox *alignmentComboBox = new QComboBox;
    alignmentComboBox->addItem(tr("left"));
    alignmentComboBox->addItem(tr("Centered"));
    alignmentComboBox->addItem(tr("right"));

    alignmentLineEdit = new QLineEdit;
    alignmentLineEdit->setPlaceholderText("Placeholder Text");


    QGroupBox *inputMaskGroup = new QGroupBox(tr("Input Mask"));

    QLabel *inputMaskLabel = new QLabel(tr("Type"));
    QComboBox *inputMaskComboBox = new QComboBox;
    inputMaskComboBox->addItem("No mask");
    inputMaskComboBox->addItem("Phone Number");
    inputMaskComboBox->addItem("ISO date");
    inputMaskComboBox->addItem("License key");

    inputMaskLineEdit = new QLineEdit;
    inputMaskLineEdit->setPlaceholderText("Placeholder Text");

    QGroupBox *accessGroup = new QGroupBox(tr("Access"));

    QLabel *accessLabel = new QLabel(tr("Read-only"));
    QComboBox *accessComboBox = new QComboBox;
    accessComboBox->addItem(tr("False"));
    accessComboBox->addItem(tr("True"));

    accessLineEdit = new QLineEdit;
    accessLineEdit->setPlaceholderText("Placeholder Text");

    connect(echoComboBox, QOverload<int>::of(&QComboBox::activated),
            this, &Window::echoChanged);
    connect(validatorComboBox, QOverload<int>::of(&QComboBox::activated),
            this, &Window::validatorChanged);
    connect(alignmentComboBox, QOverload<int>::of(&QComboBox::activated),
            this, &Window::alignmentChanged);
    connect(inputMaskComboBox, QOverload<int>::of(&QComboBox::activated),
            this, &Window::inputMaskChanged);
    connect(accessComboBox, QOverload<int>::of(&QComboBox::activated),
            this, &Window::accessChanged);

    QGridLayout *echoLayout = new QGridLayout;
    echoLayout->addWidget(echoLabel, 0, 0);
    echoLayout->addWidget(echoComboBox, 0, 1);
    echoLayout->addWidget(echoLineEdit, 1, 0, 1, 2);
    echoGroup->setLayout(echoLayout);

    QGridLayout *validatorLayout = new QGridLayout;
    validatorLayout->addWidget(validatorLabel, 0, 0);
    validatorLayout->addWidget(validatorComboBox, 0, 1);
    validatorLayout->addWidget(validatorLineEdit, 1, 0, 1, 2);
    validatorGroup->setLayout(validatorLayout);

    QGridLayout *alignmentLayout = new QGridLayout;
    alignmentLayout->addWidget(alignmentLabel, 0, 0);
    alignmentLayout->addWidget(alignmentComboBox, 0, 1);
    alignmentLayout->addWidget(alignmentLineEdit, 1, 0, 1, 2);
    alignmentGroup->setLayout(alignmentLayout);

    QGridLayout *inputMaksLayout = new QGridLayout;
    inputMaksLayout->addWidget(inputMaskLabel, 0, 0);
    inputMaksLayout->addWidget(inputMaskComboBox, 0, 1);
    inputMaksLayout->addWidget(inputMaskLineEdit, 1, 0, 1, 2);
    inputMaskGroup->setLayout(inputMaksLayout);

    QGridLayout *accessLayout = new QGridLayout;
    accessLayout->addWidget(accessLabel, 0, 0);
    accessLayout->addWidget(accessComboBox, 0, 1);
    accessLayout->addWidget(accessLineEdit, 1, 0, 1, 2);
    accessGroup->setLayout(accessLayout);

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(echoGroup, 0, 0);
    mainLayout->addWidget(validatorGroup, 1, 0);
    mainLayout->addWidget(alignmentGroup, 2, 0);
    mainLayout->addWidget(inputMaskGroup, 0, 1);
    mainLayout->addWidget(accessGroup, 1, 1);
    setLayout(mainLayout);

    setWindowTitle("Line Edits");

}

void Window::echoChanged(int value)
{

}

void Window::validatorChanged(int value)
{

}

void Window::alignmentChanged(int value)
{

}

void Window::inputMaskChanged(int value)
{

}

void Window::accessChanged(int value)
{

}
