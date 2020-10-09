//
// Created by dominik on 05.10.2020.
//

#ifndef LIFE_CONWAYCELL_HPP
#define LIFE_CONWAYCELL_HPP

#include <set>
#include "Cell.hpp"

class ConwayCell : public Cell
{
public:
  explicit ConwayCell(int state=0);
  ConwayCell(const std::set<int>& stay_alive, const std::set<int>& born, int state=0);
  void calculate_next_state(const CellArray& world) override;
  void move_to_next_state() override;
  int get_state() const override;

private:
  std::set<int> _stay_alive;
  std::set<int> _born;
  int _state;
  int _next_state;
};


#endif //LIFE_CONWAYCELL_HPP
