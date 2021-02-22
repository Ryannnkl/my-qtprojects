#include "principal.h"

#include "QLineEdit"
#include "QGridLayout"
#include "QToolButton"

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
{
    QGridLayout *layout = new QGridLayout;

    QToolButton *loginButton = new QToolButton;
    loginButton->setText(tr("Login"));
    connect(loginButton, SIGNAL(clicked()), this, SLOT(loginClicked()));

    email = new QLineEdit("");
    password = new QLineEdit("");

    email->setReadOnly(true);
    email->setAlignment(Qt::AlignRight);
    email->setMaxLength(15);

    password->setReadOnly(true);
    password->setAlignment(Qt::AlignRight);
    password->setMaxLength(15);
    layout->setSizeConstraint(QLayout::SetFixedSize);
    layout->addWidget(email, 0, 0, 1, 5);
    layout->addWidget(password, 1, 0, 1, 5);
    layout->addWidget(loginButton, 2, 0, 2, 4);

    setLayout(layout);
    setWindowTitle("login");
}

Principal::~Principal()
{
}

void Principal::loginClicked()
{

}

