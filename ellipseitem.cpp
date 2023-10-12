#include "ellipseitem.h"
#include <QPainter>

EllipseItem::EllipseItem(QQuickItem *parent)
    : QQuickPaintedItem(parent)
{
}

void EllipseItem::paint(QPainter *painter)
{
    painter->save();
    QPen pen = painter->pen();
    pen.setBrush(m_color);
    pen.setWidth(3);
    painter->setPen(pen);
    const QRectF paintRect = QRectF({}, QSizeF{width(), height()}).adjusted(1, 1, -1, -1);
    painter->drawEllipse(paintRect);
    painter->restore();
}

QColor EllipseItem::color() const
{
    return m_color;
}

void EllipseItem::setColor(const QColor &newColor)
{
    if(m_color != newColor) {
        m_color = newColor;
        update();
        emit colorChanged();
    }
}
