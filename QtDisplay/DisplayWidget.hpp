//
// Created by dominik on 09.10.2020.
//

#ifndef LIFE_DISPLAYWIDGET_HPP
#define LIFE_DISPLAYWIDGET_HPP

#include <QWidget>
#include <QGraphicsScene>
#include <QtWidgets/QGraphicsView>

#include "Display.hpp"
#include "Canvas.hpp"

class QCanvas : public Canvas
{
public:
  QCanvas();
  void draw_rect(int x, int y, int width, int height, const Pen& pen) override;
  QGraphicsScene* get_scene() const;

private:
  QGraphicsScene* scene;
};

class DisplayWidget : public QWidget, public Display
{
  Q_OBJECT
public:
  explicit DisplayWidget(QWidget* parent = nullptr);
  Canvas* get_canvas() override;
  void show_display() override;

private:
  QGraphicsView* view;
  QCanvas* canvas;
};


#endif //LIFE_DISPLAYWIDGET_HPP
