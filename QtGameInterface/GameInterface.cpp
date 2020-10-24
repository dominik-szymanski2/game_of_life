//
// Created by dominik on 16.10.2020.
//

#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QPushButton>
#include "GameInterface.hpp"
#include "../GameEngine.hpp"
#include "../CellArray.hpp"
#include "../Display.hpp"

GameInterface::GameInterface(Display& display, GameEngine& engine, QWidget* parent)
  : QWidget(parent),
    display(display),
    engine(engine)
{
  QVBoxLayout* layout = new QVBoxLayout(this);
  QPushButton* next_epoch = new QPushButton("next epoch");
  QObject::connect(next_epoch, &QPushButton::clicked, this, &GameInterface::next_epoch);
  layout->addWidget(next_epoch);
  setLayout(layout);
  show();

  engine.get_array().draw(display);
  display.show_display();
}

void
GameInterface::next_epoch()
{
  engine.next_epoch();
  engine.get_array().draw(display);
  display.show_display();
}