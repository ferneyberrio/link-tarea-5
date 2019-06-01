#ifndef PARTICULA_H
#define PARTICULA_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>


class particula : public QGraphicsItem
{
public:
    particula();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    void advance(int phase);

private:
    qreal angle;
    qreal speed;
    void Collision();


};

#endif // PARTICULA_H
