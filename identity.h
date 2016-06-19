#ifndef IDENTITY_H
#define IDENTITY_H
#include <string>
#include <QGraphicsItem>
using std :: string;
namespace YSFL
{
class identity : public QGraphicsItem
{
public:
    string style;
    identity(qreal x, qreal y, Qt::GlobalColor c = Qt::red);
    identity(qreal x, qreal y, string _style);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    void paint2(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    QPainterPath shape() const;

private:
    Qt::GlobalColor col;
};


}
#endif // IDENTITY_H
