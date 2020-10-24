//
// Created by dominik on 09.10.2020.
//

#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QGraphicsView>
#include "DisplayWidget.hpp"

QCanvas::QCanvas()
  : scene(new QGraphicsScene(0, 0, 1000, 1000))
{
}

QGraphicsScene*
QCanvas::get_scene() const
{
  return scene;
}

void
QCanvas::draw_rect(int x, int y, int width, int height, const Pen& pen)
{
  auto color = pen.get_color();
  QPen q_pen(QColor(color.r, color.g, color.b, color.a));
  QBrush q_brush(QColor(color.r, color.g, color.b, color.a));
  scene->addRect(QRect(x, y, width, height), q_pen, q_brush);

}

DisplayWidget::DisplayWidget(QWidget* parent)
  : QWidget(parent)
  , canvas(new QCanvas())
  , view(new QGraphicsView())
{
  view->setScene(canvas->get_scene());
}

Canvas*
DisplayWidget::get_canvas()
{
  return canvas;
}

void
DisplayWidget::show_display()
{
  view->show();
}
