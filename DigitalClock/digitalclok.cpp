#include "digitalclok.h"

#include "QTime"
#include "QTimer"

DigitalClok::DigitalClok(QWidget *parent)
    : QLCDNumber(parent)
{
    setSegmentStyle(Filled);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &DigitalClok::showTime);
    timer->start(1000);

    showTime();

    setWindowTitle("Relogio digital");
    resize(150,60);
}


void DigitalClok::showTime()
{
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm");

    if((time.second() % 2) == 0){
        text[2] = ' ';
    }
    display(text);
}
