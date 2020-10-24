//
// Created by dominik on 05.10.2020.
//

#ifndef LIFE_DISPLAY_HPP
#define LIFE_DISPLAY_HPP

class Canvas;

class Display
{
public:
  virtual Canvas* get_canvas() = 0;
  virtual void show_display() = 0;
  virtual ~Display() = default;
};


#endif //LIFE_DISPLAY_HPP
