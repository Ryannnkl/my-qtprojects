#include "principal.h"

#include <QVBoxLayout>
#include <QStatusBar>
#include <QMenuBar>
#include <QLabel>

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *widgetCentral = new QWidget;
    setCentralWidget(widgetCentral);

    QLabel *label = new QLabel(tr("Login"));
    label->setStyleSheet("color: #333; font-size:23px; font-weight: bold; margin: 0 auto;");
    infoLabel = new QLabel;
    createLineEdits();
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(label, 0, Qt::AlignCenter);
    layout->addWidget(email, 1, Qt::AlignCenter);
    layout->addWidget(password, 2, Qt::AlignCenter);
    layout->addWidget(loginButton, 3, Qt::AlignCenter);

    createActions();
    createMenus();
    statusBar()->showMessage("testando aq fio");

    widgetCentral->setLayout(layout);
    setWindowTitle("login");
    // resize(400, 300);
}

void Principal::save()
{
     infoLabel->setText(tr("Invoked <br>File|Save</br>"));
}

void Principal::newFile()
{
    infoLabel->setText("Invoked File|New");
    dialogo.show();
}

void Principal::open()
{
     infoLabel->setText(tr("Invoked <br></br>"));
}

void Principal::print()
{
     infoLabel->setText(tr("Invoked <br></br>"));
}

void Principal::undo()
{
     infoLabel->setText(tr("Invoked <br></br>"));
}

void Principal::redo()
{
     infoLabel->setText(tr("Invoked <br></br>"));
}

void Principal::cut()
{
     infoLabel->setText(tr("Invoked <br></br>"));
}

void Principal::copy()
{
     infoLabel->setText(tr("Invoked <br></br>"));
}

void Principal::paste()
{
     infoLabel->setText(tr("Invoked <br></br>"));
}

void Principal::bold()
{
     infoLabel->setText(tr("Invoked <br></br>"));
}

void Principal::italic()
{
     infoLabel->setText(tr("Invoked <br></br>"));
}

void Principal::leftAlign()
{
     infoLabel->setText(tr("Invoked <br></br>"));
}

void Principal::rightAlign()
{
     infoLabel->setText(tr("Invoked <br></br>"));
}

void Principal::center()
{
     infoLabel->setText(tr("Invoked <br></br>"));
}

void Principal::justify()
{
     infoLabel->setText(tr("Invoked <br></br>"));
}

void Principal::setLineSpacing()
{
     infoLabel->setText(tr("Invoked <br></br>"));
}

void Principal::setParagraphSpacing()
{
     infoLabel->setText(tr("Invoked <br></br>"));
}

void Principal::about()
{
     infoLabel->setText(tr("Invoked <br></br>"));
}

void Principal::aboutQt()
{
     infoLabel->setText(tr("Invoked <br></br>"));
}

void Principal::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
    fileMenu->addSeparator();
    fileMenu->addAction(printAct);
    fileMenu->addAction(exitAct);

    editMenu = menuBar()->addMenu(tr("&Edit"));
    editMenu->addAction(undoAct);
    editMenu->addAction(redoAct);
    editMenu->addSeparator();
    editMenu->addAction(cutAct);
    editMenu->addAction(pasteAct);
    editMenu->addSeparator();

    formatMenu = menuBar()->addMenu(tr("&Format"));
    formatMenu->addAction(boldAct);
    formatMenu->addAction(italiAct);
    formatMenu->addSection(tr("Alinhamento"));
    formatMenu->addAction(leftAlignAct);
    formatMenu->addAction(rightAlignAct);
    formatMenu->addAction(centerAct);
    formatMenu->addAction(justifyAct);
    formatMenu->addSeparator();
    formatMenu->addAction(setLineSpacingAct);
    formatMenu->addAction(setParagraphSpacingAct);

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(aboutQtAct);
}

void Principal::createActions()
{
    newAct = new QAction(tr("&New"), this);
    newAct->setStatusTip(tr("Criar arquivo novo"));
    newAct->setShortcut(QKeySequence::New);
    connect(newAct, &QAction::triggered, this, &Principal::newFile);

    openAct = new QAction(tr("&Open..."), this);
    openAct->setShortcut(QKeySequence::Open);
    openAct->setStatusTip(tr("Abrir arquivo existente"));
    connect(openAct, &QAction::triggered, this, &Principal::open);

    saveAct = new QAction(tr("&Save"), this);
    saveAct->setShortcut(QKeySequence::Save);
    saveAct->setStatusTip(tr("Salvar o documento"));
    connect(saveAct, &QAction::triggered, this, &Principal::save);

    printAct = new QAction(tr("&Print..."), this);
    printAct->setShortcut(QKeySequence::Print);
    printAct->setStatusTip(tr("Printar o documento"));
    connect(printAct, &QAction::triggered, this, &Principal::print);

    exitAct = new QAction(tr("&Exit"), this);
    exitAct->setShortcut(QKeySequence::Quit);
    exitAct->setStatusTip("Sait");
    connect(exitAct, &QAction::trigger, this, &Principal::close);

    undoAct = new QAction(tr("&Undo"), this);
    undoAct->setShortcut(QKeySequence::Undo);
    undoAct->setStatusTip("Voltar ultima operação");
    connect(undoAct, &QAction::trigger, this, &Principal::undo);

    redoAct = new QAction(tr("&Redo"), this);
    redoAct->setShortcut(QKeySequence::Redo);
    redoAct->setStatusTip("Refazer ultima operação");
    connect(redoAct, &QAction::triggered, this, &Principal::redo);

    cutAct = new QAction(tr("&Cut"), this);
    cutAct->setShortcut(QKeySequence::Cut);
    cutAct->setStatusTip("Recortar");
    connect(cutAct, &QAction::triggered, this, &Principal::cut);

    copyAct = new QAction(tr("&Copy"), this);
    copyAct->setShortcut(QKeySequence::Copy);
    copyAct->setStatusTip("Copiar para area de transferencia");
    connect(copyAct, &QAction::trigger, this, &Principal::copy);

    pasteAct = new QAction(tr("&Paste"), this);
    pasteAct->setShortcut(QKeySequence::Paste);
    connect(pasteAct, &QAction::triggered, this, &Principal::paste);

    boldAct = new QAction(tr("&Bold"), this);
    boldAct->setCheckable(true);
    boldAct->setShortcut(QKeySequence::Bold);
    connect(boldAct, &QAction::triggered, this, &Principal::bold);

    QFont boldFont = boldAct->font();
    boldFont.setBold(true);
    boldAct->setFont(boldFont);

    italiAct = new QAction(tr("&Italic"), this);
    italiAct->setCheckable(true);
    italiAct->setShortcut(QKeySequence::Italic);
    connect(italiAct, &QAction::triggered, this, &Principal::italic);

    QFont italicFont = italiAct->font();
    italicFont.setItalic(true);
    italiAct->setFont(italicFont);

    setLineSpacingAct = new QAction(tr("Set &Line Spacing..."), this);
    setLineSpacingAct->setStatusTip(tr("Change gap between the lines of a paragrath"));
    connect(setLineSpacingAct, &QAction::triggered, this, &Principal::setLineSpacing);

    setParagraphSpacingAct = new QAction(tr("Set &Paragraph Spacing..."), this);
    setLineSpacingAct->setStatusTip(tr("Change gap between paragrapths"));
    connect(setParagraphSpacingAct, &QAction::triggered, this, &Principal::setLineSpacing);

    aboutAct = new QAction(tr("&About"), this);
    aboutAct->setStatusTip(tr("Sobre"));
    connect(aboutAct, &QAction::triggered, this, &Principal::about);

    aboutQtAct = new QAction(tr("About &Qt"), this);
    aboutQtAct->setStatusTip(tr("Sobre o Qt"));
    connect(aboutQtAct, &QAction::triggered, this, &Principal::aboutQt);

    leftAlignAct = new QAction(tr("&Left Align"), this);
    leftAlignAct->setCheckable(true);
    leftAlignAct->setShortcut(tr("Ctrl+L"));
    connect(leftAlignAct, &QAction::triggered, this, &Principal::leftAlign);

    rightAlignAct = new QAction(tr("&Right Align"), this);
    rightAlignAct->setCheckable(true);
    rightAlignAct->setShortcut(tr("Ctrl+R"));
    connect(rightAlignAct, &QAction::triggered, this, &Principal::rightAlign);

    centerAct = new QAction(tr("&Center"), this);
    centerAct->setCheckable(true);
    centerAct->setShortcut(tr("Ctrl+E"));
    connect(centerAct, &QAction::trigger, this, &Principal::center);

    justifyAct = new QAction(tr("Align &Justify"));
    justifyAct->setCheckable(true);
    connect(justifyAct, &QAction::triggered, this, &Principal::justify);

    alignmentGroup = new QActionGroup(this);
    alignmentGroup->addAction(leftAlignAct);
    alignmentGroup->addAction(rightAlignAct);
    alignmentGroup->addAction(centerAct);
    alignmentGroup->addAction(justifyAct);
    leftAlignAct->setChecked(true);

}

void Principal::createLineEdits()
{
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

    loginButton = new QToolButton;
    loginButton->setText("Login");
    loginButton->setMinimumWidth(100);
    loginButton->setMaximumWidth(150);
    loginButton->setFixedHeight(32);
    loginButton->setStyleSheet("border: none; background-color: #345476; color: #FEFEFE; font-size: 16px; border-radius: 4px;");
}
