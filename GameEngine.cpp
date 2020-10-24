//
// Created by dominik on 05.10.2020.
//

#include <iostream>
#include "GameEngine.hpp"
#include "CellArray.hpp"
#include "Cell.hpp"

GameEngine::GameEngine(CellArray& cell_array)
  : _cellArray(cell_array)
{

}

void
GameEngine::next_epoch()
{
  std::unique_ptr<CellArrayIterator> iter(_cellArray.create_iterator());

  for(iter->first(); iter->is_valid(); ++(*iter))
  {
    (*(*iter))->calculate_next_state(_cellArray);
  }
  for(iter->first(); iter->is_valid(); ++(*iter))
  {
    (*(*iter))->move_to_next_state();
  }
}