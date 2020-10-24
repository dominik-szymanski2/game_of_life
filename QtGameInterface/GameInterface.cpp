//
// Created by dominik on 16.10.2020.
//

#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QGraphicsView>
#include "GameInterface.hpp"
#include "../GameEngine.hpp"
#include "../CellArray.hpp"
#include "../Display.hpp"
#include "../Canvas.hpp"

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

GameInterface::GameInterface(GameEngine& engine, QWidget* parent)
  : QWidget(parent),
    engine(engine),
    view(new QGraphicsView()),
    canvas(new QCanvas())
{
  view->setScene(canvas->get_scene());
  QVBoxLayout* layout = new QVBoxLayout(this);
  QPushButton* next_epoch = new QPushButton("next epoch");
  QObject::connect(next_epoch, &QPushButton::clicked, this, &GameInterface::next_epoch);
  layout->addWidget(next_epoch);
  layout->addWidget(view);
  setLayout(layout);
  show();

  engine.get_array().draw(*canvas);
}

void
GameInterface::next_epoch()
{
  engine.next_epoch();
  engine.get_array().draw(*canvas);
}