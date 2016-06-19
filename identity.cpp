#include <QPainter>

#include "identity.h"
namespace YSFL{
static const qreal IDENTITY_RADIUS = 3;

identity::identity(qreal x, qreal y, Qt::GlobalColor c)
{
    setPos(x, y);
    style = ":/light.png";
    col = c;
}
identity::identity(qreal x, qreal y, string _style) : style(_style)
{
    setPos(x, y);
    col = Qt::red;
}
QRectF identity::boundingRect() const
{
    return QRectF(0, 0, 9, 9);
}

void identity::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QPixmap pix;
    pix.load(style.c_str());
    painter->save();
    painter->drawPixmap(0,0,32,32,pix);

   // painter->setRenderHint(QPainter::Antialiasing);
  //  painter->fillPath(shape(), col);

    painter->restore();
}

QPainterPath identity::shape() const
{
    QPainterPath p;
    p.addEllipse(QPointF(9 / 2, 9 / 2), IDENTITY_RADIUS, IDENTITY_RADIUS);
    p.addRect(QRectF(0,0,9,9));
    return p;
}
}
