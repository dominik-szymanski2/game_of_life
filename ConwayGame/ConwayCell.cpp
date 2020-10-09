//
// Created by dominik on 05.10.2020.
//

#include <numeric>
#include "CellArray.hpp"
#include "ConwayCell.hpp"

ConwayCell::ConwayCell(int state)
  : _stay_alive{2, 3},
    _born{3},
    _state(state),
    _next_state(state)
{

}

ConwayCell::ConwayCell(const std::set<int>& stay_alive, const std::set<int>& born, int state)
: _stay_alive(stay_alive),
  _born(born),
  _state(state),
  _next_state(state)
{

}

void
ConwayCell::calculate_next_state(const CellArray& world)
{
  auto cells = world.get_neighborhood();
  int live_cells_number = std::accumulate(cells.begin(), cells.end(), 0,
                                          [](int no, Cell* cell){return cell->get_state() == 1 ? ++no : no;});

  if (_state == 0 && _born.contains(live_cells_number))
  {
    _next_state = 1;
  }
  else if (_state == 1 && !_stay_alive.contains(live_cells_number))
  {
    _next_state = 0;
  }
}

void
ConwayCell::move_to_next_state()
{
  _state = _next_state;
}

int
ConwayCell::get_state() const
{
  return _state;
}