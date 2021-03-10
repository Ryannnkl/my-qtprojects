#include "mainwindow.h"

#include <QtCore>
#include <QFile>
#include <QLabel>
#include <QTextStream>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTextDocument>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *widget = new QWidget;
    setCentralWidget(widget);

    QLabel *label = new QLabel(tr("Keyword"));

    search = new QLineEdit;

    push = new QPushButton;
    push->setText("Find");

    connect(push, SIGNAL(clicked(bool)), this, SLOT(on_findButton_clicked()));

    QHBoxLayout *searchLayout = new QHBoxLayout;

    searchLayout->addWidget(label);
    searchLayout->addWidget(search);
    searchLayout->addWidget(push);

    text = new QTextEdit;

    QVBoxLayout *mainLayout = new QVBoxLayout;

    mainLayout->addLayout(searchLayout);
    mainLayout->addWidget(text);

    widget->setLayout(mainLayout);
    loadTextFile();
    setWindowTitle("Search word");
}

MainWindow::~MainWindow()
{
}

void MainWindow::on_findButton_clicked()
{
    QString searchString = search->text();
    text->find(searchString, QTextDocument::FindWholeWords);
}

void MainWindow::loadTextFile()
{
    QFile inputFile(":input.txt");
    inputFile.open(QIODevice::ReadOnly);

    QTextStream in(&inputFile);
    QString line = in.readAll();
    inputFile.close();

    text->setPlainText(line);

//    QTextCursor cursor = text->textCursor();
//    cursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor, 1);
}
