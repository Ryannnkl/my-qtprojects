#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include "mydialog.h"
#include <QMainWindow>
#include <QMenu>
#include <QAction>
#include <QActionGroup>
#include <QLineEdit>
#include <QToolButton>
#include <QLabel>

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);

private slots:
    void newFile();
    void open();
    void save();
    void print();
    void undo();
    void redo();
    void cut();
    void copy();
    void paste();
    void bold();
    void italic();
    void leftAlign();
    void rightAlign();
    void center();
    void justify();
    void setLineSpacing();
    void setParagraphSpacing();
    void about();
    void aboutQt();

private:
    MyDialog dialogo;
    void createMenus();
    void createActions();
    void createLineEdits();

    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *formatMenu;
    QMenu *helpMenu;

    QActionGroup *alignmentGroup;
    QAction *newAct;
    QAction *openAct;
    QAction *saveAct;
    QAction *printAct;
    QAction *exitAct;
    QAction *undoAct;
    QAction *redoAct;
    QAction *cutAct;
    QAction *copyAct;
    QAction *pasteAct;
    QAction *boldAct;
    QAction *italiAct;
    QAction *leftAlignAct;
    QAction *rightAlignAct;
    QAction *centerAct;
    QAction *justifyAct;
    QAction *setLineSpacingAct;
    QAction *setParagraphSpacingAct;
    QAction *aboutAct;
    QAction *aboutQtAct;

    QLabel *infoLabel;

    QLineEdit *email;
    QLineEdit *password;
    QToolButton *loginButton;
};

#endif // PRINCIPAL_H
