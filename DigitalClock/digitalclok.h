#ifndef DIGITALCLOK_H
#define DIGITALCLOK_H

#include <QLCDNumber>

class DigitalClok : public QLCDNumber
{
    Q_OBJECT

public:
    DigitalClok(QWidget *parent = nullptr);

private slots:
    void showTime();
};
#endif // DIGITALCLOK_H
