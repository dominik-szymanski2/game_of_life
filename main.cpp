#include <ConwayGame/CellArray2D.hpp>
#include <thread>
#include <QtGameInterface/GameInterface.hpp>
#include <ConwayGame/ConwayLoader.hpp>
#include "QApplication"

#include "QtDisplay/DisplayWidget.hpp"
#include "GameEngine.hpp"

int main(int argc, char** argv)
{
  QApplication app(argc, argv);
  ConwayLoader loader;
  std::unique_ptr<CellArray> array(loader.Load(""));
  GameEngine engine(*array);
  DisplayWidget* display = new DisplayWidget();

  GameInterface game_interface(*display, engine);

  return app.exec();
}
