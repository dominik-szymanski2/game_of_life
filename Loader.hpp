//
// Created by dominik on 23.10.2020.
//

#ifndef LIFE_LOADER_HPP
#define LIFE_LOADER_HPP

#include "string"

class CellArray;

class Loader
{
public:
  virtual CellArray* Load(const std::string& path) = 0;
};

#endif //LIFE_LOADER_HPP
