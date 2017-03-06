#include "keyreceiver.h"
#include <QDebug>
KeyReceiver::KeyReceiver(QObject *parent,QVector<QToolButton*> *toolButtons) : QObject(parent)
{
this->buttons = QVector<QToolButton*>(6);
this->buttons = *toolButtons;

}
bool KeyReceiver::eventFilter(QObject* obj, QEvent* event)
{
    if (event->type()==QEvent::KeyPress) {
        QKeyEvent* key = static_cast<QKeyEvent*>(event);
        if ( (key->key()==Qt::Key_Enter) || (key->key()==Qt::Key_Return) ) {
            QToolButton *button = static_cast<QToolButton*>(obj);
            emit button->clicked(button);
        }
        else if ( (key->key()==Qt::Key_Up) || (key->key()==Qt::Key_Down ) || (key->key()==Qt::Key_Left) || (key->key()==Qt::Key_Right )) {
            QToolButton *button = static_cast<QToolButton*>(obj);
            int i = this->buttons.indexOf(button);
            switch(key->key()) {
                case Qt::Key_Up:{
                    if(i>2)  {
                        i-=3;
                    }
                    else if(i<3 && i >0)  {
                        i+=2;
                    }
                break;
                }
            case Qt::Key_Down:{
                    if(i<3)  {
                       i+=3;
                    }
                    else if(i<5 && i >2)  {
                        i-=2;
                    }


            break;
             }
            case Qt::Key_Right:{
                    i+=1;
                    if(i==6) {
                        i=0;
                    }
                 break;
                }

            case Qt::Key_Left:{
                    i-=1;
                    if(i==-1) {
                        i=5;
                    }
                 break;
                }
            }
            this->buttons.at(i)->setFocus();




        } else {
            return QObject::eventFilter(obj, event);
        }
        return true;
    } else {
        return QObject::eventFilter(obj, event);
    }
    return false;
}
