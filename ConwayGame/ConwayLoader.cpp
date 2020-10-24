//
// Created by dominik on 23.10.2020.
//

#include <fstream>

#include "ConwayLoader.hpp"
#include "CellArray.hpp"
#include "ConwayCell.hpp"
#include "CellArray2D.hpp"

CellArray*
ConwayLoader::Load(const std::string& path)
{
  std::vector<std::vector<Cell*>> array;
  std::ifstream myfile ("/home/dominik/Desktop/board1.txt");
  if (myfile.is_open())
  {
    std::string line;
    getline(myfile, line);
    int h = std::stoi(line);
    getline(myfile, line);
    int w = std::stoi(line);
    int i = 0;
    int j = 0;

    while ( getline (myfile, line) )
    {
      array.push_back({});
      j = 0;
      for (char c : line)
      {
        if (c == '-')
        {
          array[i].push_back(new ConwayCell(j, i, 0));
        }
        else
        {
          array[i].push_back(new ConwayCell(j, i, 1));
        }
        ++j;
      }
      ++i;
    }
    myfile.close();
    auto cell_array = new CellArray2D(w, h, array);
    return cell_array;
  }
  return nullptr;
}