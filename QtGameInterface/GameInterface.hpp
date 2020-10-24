//
// Created by dominik on 16.10.2020.
//

#ifndef LIFE_GAMEINTERFACE_HPP
#define LIFE_GAMEINTERFACE_HPP


#include <QtWidgets/QWidget>

class Display;
class GameEngine;

class GameInterface : public QWidget
{
  Q_OBJECT
public:
  GameInterface(Display& display, GameEngine& engine, QWidget* parent = nullptr);

private:
  void next_epoch();

  GameEngine& engine;
  Display& display;
};


#endif //LIFE_GAMEINTERFACE_HPP
