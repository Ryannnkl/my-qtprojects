#ifndef QWRITEAPPLICATION_H
#define QWRITEAPPLICATION_H

#include <QMainWindow>
#include <QMenu>
#include <QAction>
#include <QMenuBar>
#include <QStatusBar>
#include <QToolBar>

class QWriteApplication : public QMainWindow
{
    Q_OBJECT
public:
    explicit QWriteApplication(QWidget *parent = nullptr);

private slots:
    void newFile();

private:
    void createMenuButtons();
    void createActions();

    QMenu *file;
    QMenu *edit;
    QMenu *bookmarks;
    QMenu *tools;
    QMenu *settings;
    QMenu *help;

    QAction *newAction;
};

#endif // QWRITEAPPLICATION_H
