//
// Created by dominik on 05.10.2020.
//

#ifndef LIFE_GAMEENGINE_HPP
#define LIFE_GAMEENGINE_HPP

#include <memory>

class CellArray;

class GameEngine
{
public:
  void next_epoch();
  void set_array(std::unique_ptr<CellArray> cellArray);

  virtual ~GameEngine() = default;
private:
  std::unique_ptr<CellArray> _cellArray;
};


#endif //LIFE_GAMEENGINE_HPP
