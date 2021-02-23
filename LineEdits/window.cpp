#include "window.h"

#include <QGroupBox>
#include <QGridLayout>
#include <QLabel>
#include <QComboBox>

Window::Window(QWidget *parent)
    : QWidget(parent)
{
    QGroupBox *echoGroup = new QGroupBox(tr("Esconder"));

    QLabel *echoLabel = new QLabel(tr("Modo:"));
    QComboBox *echoComboBox = new QComboBox;
    echoComboBox->addItem(tr("Normal"));
    echoComboBox->addItem(tr("Nenha"));
    echoComboBox->addItem(tr("EsconderAposTerminar"));
    echoComboBox->addItem(tr("Sem esconder"));

    echoLineEdit = new QLineEdit;
    echoLineEdit->setPlaceholderText("Placeholder Text");
    echoLineEdit->setFocus();

    QGroupBox *validatorGroup = new QGroupBox(tr("Validação"));

    QLabel *validatorLabel = new QLabel(tr("Tipo:"));
    QComboBox *validatorComboBox = new QComboBox;
    validatorComboBox->addItem(tr("Sem validação"));
    validatorComboBox->addItem(tr("Valor inteiro"));
    validatorComboBox->addItem(tr("Valor real"));

    validatorLineEdit = new QLineEdit;
    validatorLineEdit->setPlaceholderText("Placeholder Text");


    QGroupBox *alignmentGroup = new QGroupBox(tr("Alinhamento"));

    QLabel *alignmentLabel = new QLabel(tr("Tipo:"));
    QComboBox *alignmentComboBox = new QComboBox;
    alignmentComboBox->addItem(tr("Esquerda"));
    alignmentComboBox->addItem(tr("Centralizado"));
    alignmentComboBox->addItem(tr("Direita"));

    alignmentLineEdit = new QLineEdit;
    alignmentLineEdit->setPlaceholderText("Placeholder Text");


    QGroupBox *inputMaskGroup = new QGroupBox(tr("Mascara"));

    QLabel *inputMaskLabel = new QLabel(tr("Tipo:"));
    QComboBox *inputMaskComboBox = new QComboBox;
    inputMaskComboBox->addItem("Sem mascara");
    inputMaskComboBox->addItem("Numero de celular");
    inputMaskComboBox->addItem("Data");
    inputMaskComboBox->addItem("Chave de acesso");

    inputMaskLineEdit = new QLineEdit;
    inputMaskLineEdit->setPlaceholderText("Placeholder Text");

    QGroupBox *accessGroup = new QGroupBox(tr("Acesso"));

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

void Window::echoChanged(int index)
{
    switch (index) {
    case 0:
        echoLineEdit->setEchoMode(QLineEdit::Normal);
        break;
    case 1:
        echoLineEdit->setEchoMode(QLineEdit::Password);
        break;
    case 2:
        echoLineEdit->setEchoMode(QLineEdit::PasswordEchoOnEdit);
        break;
    case 3:
        echoLineEdit->setEchoMode(QLineEdit::NoEcho);
    default:
        echoLineEdit->setEchoMode(QLineEdit::Normal);
        break;
    }
}

void Window::validatorChanged(int index)
{
    switch (index) {
    case 0:
        validatorLineEdit->setValidator(nullptr);
        break;
    case 1:
        validatorLineEdit->setValidator(new QIntValidator(validatorLineEdit));
        break;
    case 2:
        validatorLineEdit->setValidator(new QDoubleValidator(-999.0, 999.0, 2, validatorLineEdit));
        break;
    default:
        validatorLineEdit->setValidator(nullptr);
        break;
    }
    validatorLineEdit->clear();
}

void Window::alignmentChanged(int index)
{
    switch (index) {
    case 0:
        alignmentLineEdit->setAlignment(Qt::AlignLeft);
        break;
    case 1:
        alignmentLineEdit->setAlignment(Qt::AlignCenter);
        break;
    case 2:
        alignmentLineEdit->setAlignment(Qt::AlignRight);
        break;
    default:
        alignmentLineEdit->setAlignment(Qt::AlignLeft);
        break;
    }
}

void Window::inputMaskChanged(int index)
{
    switch (index) {
    case 0:
        inputMaskLineEdit->setInputMask("");
        break;
    case 1:
        inputMaskLineEdit->setInputMask("+99 (99) 99999-9999;_");
        break;
    case 2:
        inputMaskLineEdit->setInputMask("00-00-0000");
        inputMaskLineEdit->setText("00000000");
        inputMaskLineEdit->setCursorPosition(0);
        break;
    case 3:
        inputMaskLineEdit->setInputMask(">AAAAA-AAAAA-AAAAA-AAAAA-AAAAA;#");
        break;
    default:
        break;
    }

}

void Window::accessChanged(int index)
{
    switch (index) {
    case 0:
        accessLineEdit->setReadOnly(false);
        break;
    case 1:
        accessLineEdit->setReadOnly(true);
        break;
    default:
        accessLineEdit->setReadOnly(false);
        break;
    }
}
