#include "mainwindow.h"

#include <QSlider>
#include <QProgressBar>
#include <QVBoxLayout>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QSlider *slider = new QSlider;
    slider->setOrientation(Qt::Horizontal);
    slider->setMaximum(100);
    slider->setMinimum(0);

    QProgressBar *progress1 = new QProgressBar;
    progress1->setValue(0);
    QProgressBar *progress2= new QProgressBar;
    progress2->setValue(0);

    connect(slider, SIGNAL(valueChanged(int)),
            progress1, SLOT(setValue(int)));

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(slider, 2);
    layout->addWidget(progress1, 1, Qt::AlignLeft);
    layout->addWidget(progress2, 1, Qt::AlignRight);

    setCentralWidget(new QWidget);
    centralWidget()->setLayout(layout);
}

MainWindow::~MainWindow()
{
}

