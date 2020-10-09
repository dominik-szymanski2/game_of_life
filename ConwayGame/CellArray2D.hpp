//
// Created by dominik on 05.10.2020.
//

#ifndef LIFE_CELLARRAY2D_HPP
#define LIFE_CELLARRAY2D_HPP

#include "CellArray.hpp"

class CellArray2D : public CellArray
{
public:
  CellArray2D(int w, int h);
  CellArrayIterator* create_iterator() const override;
  std::vector<Cell*> get_neighborhood(int radius=1, NeighborhoodType type=NeighborhoodType::MOORE) const override;
  Cell* get_cell(int x, int y) const;
  int get_width() const;
  int get_height() const;

private:
  std::vector<std::vector<Cell*>> _array;
  int _width;
  int _height;
};

class CellArray2DIterator : public CellArrayIterator
{
public:
  CellArray2DIterator(const CellArray2D& array, int x, int y);
  void first() override;
  bool is_valid() override;
  void next() override;
  void operator++() override;
  Cell* operator*() override;

private:
  int _x;
  int _y;
  bool _valid;
  const CellArray2D& _array;
};

#endif //LIFE_CELLARRAY2D_HPP
