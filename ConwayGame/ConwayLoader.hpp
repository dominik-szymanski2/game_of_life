//
// Created by dominik on 23.10.2020.
//

#ifndef LIFE_CONWAYLOADER_HPP
#define LIFE_CONWAYLOADER_HPP

#include "Loader.hpp"

class CellArray;

class ConwayLoader : public Loader
{
public:
  CellArray* Load(const std::string& path) override;
};


#endif //LIFE_CONWAYLOADER_HPP
