//
// Created by dominik on 05.10.2020.
//

#ifndef LIFE_DISPLAY_HPP
#define LIFE_DISPLAY_HPP

class CellArray;

class Display
{
public:
  virtual void draw_array(const CellArray& array) = 0;
  virtual ~Display() = default;
};


#endif //LIFE_DISPLAY_HPP
