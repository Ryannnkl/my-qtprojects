#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include <QLineEdit>

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();
private slots:
    void loginClicked();

private:
    QLineEdit *email;
    QLineEdit *password;
};

#endif // PRINCIPAL_H
