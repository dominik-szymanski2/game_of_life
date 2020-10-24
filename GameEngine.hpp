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
  explicit GameEngine(CellArray& cell_array);
  void next_epoch();
  CellArray& get_array() {return _cellArray;}
  virtual ~GameEngine() = default;
private:
  CellArray& _cellArray;
};


#endif //LIFE_GAMEENGINE_HPP
