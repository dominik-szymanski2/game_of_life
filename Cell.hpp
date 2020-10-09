//
// Created by dominik on 05.10.2020.
//

#ifndef LIFE_CELL_HPP
#define LIFE_CELL_HPP

class CellArray;

class Cell
{
public:
  virtual void calculate_next_state(const CellArray& world) = 0;
  virtual void move_to_next_state() = 0;
  virtual int get_state() const = 0;

  virtual ~Cell() = default;
};


#endif //LIFE_CELL_HPP
