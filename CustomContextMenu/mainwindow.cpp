#include "mainwindow.h"

#include <QPushButton>
#include <QMessageBox>
#include <QModelIndex>
#include <QMenu>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    test = new QPushButton;
    test->setText("Show");
    test->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(test, &QPushButton::clicked, this, &MainWindow::showMessage);
    connect(test, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(customMenuRequested(QPoint)));

    statusBar()->addWidget(test);

}

MainWindow::~MainWindow()
{
}

void MainWindow::showMessage()
{
    QMessageBox::about(this, "Teste", "teste");
}

void MainWindow::customMenuRequested(QPoint pos)
{
    QMenu *menu=new QMenu(this);
    menu->addAction(new QAction("Action 1", this));
    menu->addAction(new QAction("Action 2", this));
    menu->addAction(new QAction("Action 3", this));
    menu->popup(test->mapToGlobal(pos));
}
