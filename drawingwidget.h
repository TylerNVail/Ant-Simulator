#ifndef DRAWINGWIDGET_H
#define DRAWINGWIDGET_H

#include "world.h"

#include <QWidget>
#include <QPoint>
#include <QPainter>
#include <QPen>

class DrawingWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DrawingWidget(World& world, QWidget *parent = nullptr);

    void draw_ants();

signals:

protected:
    World& world;
    void paintEvent(QPaintEvent *event) override;

    int penThickness{5};

    int xShift{500};
    int yShift{300};
};

#endif // DRAWINGWIDGET_H
