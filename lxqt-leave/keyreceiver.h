#ifndef KEYENTERRECEIVER_H
#define KEYENTERRECEIVER_H

#include <QObject>
#include <QKeyEvent>
#include <QToolButton>
#include <QPushButton>
#include "keyreceiver.h"
class KeyReceiver : public QObject
{
    Q_OBJECT
public:
    explicit KeyReceiver(QObject *parent = 0,QVector<QToolButton*> *buttons=nullptr);
protected:
    bool eventFilter(QObject* obj, QEvent* event);
    QVector<QToolButton*> buttons;
signals:

public slots:
};

#endif // KEYENTERRECEIVER_H
