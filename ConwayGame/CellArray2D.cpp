//
// Created by dominik on 05.10.2020.
//

#include <memory>
#include <iostream>
#include "Canvas.hpp"
#include "CellArray2D.hpp"
#include "Cell.hpp"
#include "Display.hpp"

CellArray2D::CellArray2D(int w, int h, const std::vector<std::vector<Cell*>>& array)
  : _width(w),
    _height(h),
    _array(array)
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

Cell*
CellArray2D::get_cell(int x, int y) const
{
  if (x < _width && y < _height)
  {
    return _array[y][x];
  }
  return nullptr;
}

void
CellArray2D::draw(Canvas& canvas) const
{
  auto iter = std::make_unique<CellArray2DIterator>(*this, 0, 0);
  const int size = 10;
  for (;iter->is_valid(); ++(*iter))
  {
    auto x = (*iter).get_x();
    auto y = (*iter).get_y();
    auto state = (*(*iter))->get_state();
    Pen pen = state == 1 ? Pen(Color(255, 255, 255)) : Pen(Color(0, 0, 0));
    canvas.draw_rect(x*size, y*size, size, size, pen);
  }
}

std::vector<Cell*>
CellArray2D::get_neighborhood(const Coordinates& coordinates, int radius, NeighborhoodType type) const
{
  std::vector<Cell*> neighborhood;
  if (coordinates.size() > 1)
  {
    auto x = coordinates[0];
    auto y = coordinates[1];

    for (auto i = std::max(x - radius, 0); i <= std::min(_width-1, x + radius); ++i)
    {
      for (auto j = std::max(y - radius, 0); j <= std::min(_height-1, y + radius); ++j)
      {
        if (i != x || j != y)
        {
          neighborhood.push_back(_array[j][i]);
        }
      }
    }
  }
  return neighborhood;
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
  _valid = true;
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

int
CellArray2DIterator::get_x() const
{
  return _x;
}

int
CellArray2DIterator::get_y() const
{
  return _y;
}