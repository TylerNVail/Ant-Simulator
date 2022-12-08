#include "drawingwidget.h"
#include <QTimerEvent>

#include "ant.h"
#include "world.h"

DrawingWidget::DrawingWidget(World& world, QWidget *parent)
    : world{world}, QWidget{parent}
{}

void DrawingWidget::paintEvent(QPaintEvent *event)
{
    draw_ants();
}

void DrawingWidget::draw_ants()
{
    QPen circlePen;
    circlePen.setWidth(penThickness);
    circlePen.setColor(Qt::red);

    QPainter painter(this);
    painter.setPen(circlePen);

    for(const Ant& a: world.get_ants())
    {
        const Vector3D& postion=a.get_postion();
        painter.drawText(postion[0]+xShift,postion[1]+yShift,"o");
    }
}
