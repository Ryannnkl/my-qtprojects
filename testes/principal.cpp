#include "principal.h"

#include <QGridLayout>
#include <QToolButton>
#include <QLineEdit>
#include <QLabel>

Principal::Principal(QWidget *parent)
    : QWidget(parent)
{
    QLabel *label = new QLabel(tr("Login"));
    label->setStyleSheet("color: #333; font-size:23px; font-weight: bold; margin: 0 auto;");

    QToolButton *loginButton = new QToolButton;
    loginButton->setText(tr("Login"));
    loginButton->setMinimumWidth(100);
    loginButton->setMaximumWidth(150);
    loginButton->setFixedHeight(32);
    loginButton->setStyleSheet("border: none; background-color: #345476; color: #FEFEFE; font-size: 16px; border-radius: 4px;");

    connect(loginButton, SIGNAL(clicked()), this, SLOT(loginClicked()));

    email = new QLineEdit;
    email->setMaxLength(15);
    email->setPlaceholderText("E-mail");
    email->setMinimumWidth(300);
    email->setMaximumWidth(500);
    email->setFixedHeight(28);
    email->setStyleSheet("border: 1px solid #345476; border-radius: 14px; padding: 0 8px;");

    password = new QLineEdit;
    password->setMaxLength(15);
    password->setPlaceholderText("Password");
    password->setMinimumWidth(300);
    password->setMaximumWidth(500);
    password->setFixedHeight(28);
    password->setStyleSheet("border: 1px solid #345476; border-radius: 14px; padding: 0 8px;");
    password->setEchoMode(QLineEdit::Password);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(label, 0, 1, 1, 2);
    layout->addWidget(email, 1, 0, 1, 4 );
    layout->addWidget(password, 2, 0, 1, 4);
    layout->addWidget(loginButton, 3, 1, 1, 2);
    layout->setSpacing(24);

    setLayout(layout);
    setWindowTitle("login");
}

void Principal::loginClicked()
{

}
