#include "particula.h"

particula::particula()
{
    angle = (qrand() % 360);
    setRotation(angle);
    speed = 5;

    int StartX = 0;
    int StartY = 0;

    if ((qrand() % 1))
    {
        StartX = (qrand() % 200);
        StartY = (qrand() % 200);
    }
    else
    {
        StartX = (qrand() % -100);
        StartX = (qrand() % -100);
    }

    setPos(mapToParent(StartX,StartY));
}

QRectF particula::boundingRect() const
{
    return QRect(0,0,30,30);
}

void particula::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundingRect();
    QBrush Brush(Qt::blue);

    if(scene()->collidingItems(this).isEmpty())
    {
        Brush.setColor(Qt::darkGreen);
    }

    else
    {
        Brush.setColor(Qt::red);
        Collision();
    }

    painter->fillRect(rec,Brush);
    painter->drawRect(rec);
}

void particula::advance(int phase)
{
    if(!phase) return;
    QPointF location = this->pos();
    setPos(mapToParent(0,-(speed)));
}

void particula::Collision()
{


    if ((qrand() %1))
    {
       setRotation(rotation() + (qrand() %10));
    }
    else
    {
        setRotation(rotation() + (qrand() %-10));
    }

    QPointF newpoint = mapToParent(-(boundingRect().width()), -(boundingRect().width() + 2));

    if (!scene()->sceneRect().contains((newpoint)))
    {
        newpoint = mapToParent(0,0);
    }
    else
    {
       setPos(newpoint);
    }
}
