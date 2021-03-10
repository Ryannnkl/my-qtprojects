#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_findButton_clicked();

private:
    void loadTextFile();

    QLineEdit *search;
    QPushButton *push;
    QTextEdit *text;
};
#endif // MAINWINDOW_H
