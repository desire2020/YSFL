#ifndef IDENTITY_H
#define IDENTITY_H

#include <QGraphicsItem>
namespace YSFL
{
class identity : public QGraphicsItem
{
public:
    identity(qreal x, qreal y, Qt::GlobalColor c = Qt::red);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);

    QPainterPath shape() const;

private:
    Qt::GlobalColor col;
};


}
#endif // IDENTITY_H
