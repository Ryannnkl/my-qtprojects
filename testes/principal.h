#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QWidget>
#include <QLineEdit>

class Principal : public QWidget
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
private slots:
    void loginClicked();

private:
    QLineEdit *email;
    QLineEdit *password;
};

#endif // PRINCIPAL_H
