//
// Created by dominik on 05.10.2020.
//

#include "CellArray2D.hpp"

CellArray2D::CellArray2D(int w, int h)
  : _width(w),
    _height(h)
{

}

CellArrayIterator*
CellArray2D::create_iterator() const
{
  return new CellArray2DIterator(*this, 0, 0);
}


int
CellArray2D::get_width() const
{
  return _width;
}

int
CellArray2D::get_height() const
{
  return _height;
}

std::vector<Cell*>
CellArray2D::get_neighborhood(int radius, NeighborhoodType type) const
{

}

CellArray2DIterator::CellArray2DIterator(const CellArray2D& array, int x, int y)
  : _array(array),
    _x(x),
    _y(y),
    _valid(true)
{

}

void
CellArray2DIterator::next()
{
  if (_x < _array.get_width()-1)
  {
    _x++;
  }
  else if (_y < _array.get_height()-1)
  {
    _x = 0;
    _y++;
  }
  else
  {
    _valid = false;
  }
}

void
CellArray2DIterator::first()
{
  _x = 0;
  _y = 0;
}

bool
CellArray2DIterator::is_valid()
{
  return _valid;
}

void
CellArray2DIterator::operator++()
{
  next();
}

Cell*
CellArray2DIterator::operator*()
{
  return _array.get_cell(_x, _y);
}