//
// Created by dominik on 16.10.2020.
//

#ifndef LIFE_GAMEINTERFACE_HPP
#define LIFE_GAMEINTERFACE_HPP


#include <QtWidgets/QWidget>
#include "../Canvas.hpp"

class GameEngine;
class Pen;
class QGraphicsView;
class QGraphicsScene;

class QCanvas : public Canvas
{
public:
  QCanvas();
  void draw_rect(int x, int y, int width, int height, const Pen& pen) override;
  QGraphicsScene* get_scene() const;

private:
  QGraphicsScene* scene;
};

class GameInterface : public QWidget
{
  Q_OBJECT
public:
  GameInterface(GameEngine& engine, QWidget* parent = nullptr);

private:
  void next_epoch();

  GameEngine& engine;
  QGraphicsView* view;
  QCanvas* canvas;
};


#endif //LIFE_GAMEINTERFACE_HPP
