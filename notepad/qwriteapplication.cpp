#include "qwriteapplication.h"
#include "codeeditor.h"

#include <QPushButton>

QWriteApplication::QWriteApplication(QWidget *parent) : QMainWindow(parent)
{
    createActions();
    createMenuButtons();
    setCentralWidget(new CodeEditor);
    resize(400, 450);
}

void QWriteApplication::createMenuButtons()
{
    file = menuBar()->addMenu(tr("File"));
    edit = menuBar()->addMenu(tr("Edit"));
    bookmarks = menuBar()->addMenu(tr("Bookmarks"));
    tools = menuBar()->addMenu(tr("Tools"));
    settings = menuBar()->addMenu(tr("Settings"));
    help = menuBar()->addMenu(tr("Help"));

    QToolBar *toolBar = addToolBar("File");
    // toolBar->addWidget(file);
    toolBar->setMovable(false);
    toolBar->setFixedHeight(35);
    toolBar->addAction(newAction);

    QPushButton *test = new QPushButton(tr("Teste"));
    statusBar()->addWidget(test);
}
void QWriteApplication::createActions()
{
    newAction = new QAction(tr("&New"), this);
    connect(newAction, &QAction::triggered, this, &QWriteApplication::newFile);
    newAction->setIconText("New");
    newAction->setIcon(QIcon::fromTheme("document-new"));
}
void QWriteApplication::newFile()
{

}
