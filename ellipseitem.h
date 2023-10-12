#ifndef ELLIPSEITEM_H
#define ELLIPSEITEM_H

#include <QQuickPaintedItem>

class EllipseItem: public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
public:
    explicit EllipseItem(QQuickItem *parent=nullptr);
    void paint(QPainter *painter) override;
    QColor color() const;
    void setColor(const QColor &newColor);

signals:
    void colorChanged();
private:
    QColor m_color;
};

#endif // ELLIPSEITEM_H
