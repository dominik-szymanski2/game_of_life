//
// Created by dominik on 05.10.2020.
//

#ifndef LIFE_CELLARRAY_HPP
#define LIFE_CELLARRAY_HPP

#include <vector>

class Cell;

enum class NeighborhoodType
{
  MOORE,
  NEUMANN
};

class CellArrayIterator
{
public:
  virtual void next() = 0;
  virtual void first() = 0;
  virtual bool is_valid() = 0;
  virtual void operator++() = 0;
  virtual Cell* operator*() = 0;

  virtual ~CellArrayIterator() = default;
};

class CellArray
{
public:
  virtual CellArrayIterator* create_iterator() const = 0;
  virtual std::vector<Cell*> get_neighborhood(int radius=1, NeighborhoodType type=NeighborhoodType::MOORE) const = 0;

  virtual ~CellArray() = default;
};


#endif //LIFE_CELLARRAY_HPP
