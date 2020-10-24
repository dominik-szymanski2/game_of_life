//
// Created by dominik on 12.10.2020.
//

#ifndef LIFE_CANVAS_HPP
#define LIFE_CANVAS_HPP

struct Color
{
  Color(int r, int g, int b, int a = 255)
  : r(r),
    g(g),
    b(b),
    a(a)
  {}

  int r;
  int g;
  int b;
  int a;
};

class Pen
{
public:
  explicit Pen(const Color& color)
  : color(color)
  {}

  void set_color(const Color& color)
  {
    this->color = color;
  }
  Color get_color() const
  {
    return color;
  }

private:
  Color color;
};

class Canvas
{
public:
  virtual void draw_rect(int x, int y, int width, int height, const Pen& pen) = 0;
};

#endif //LIFE_CANVAS_HPP
