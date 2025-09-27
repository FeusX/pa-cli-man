#ifndef MAP_HPP
#define MAP_HPP

#include <vector>
#include <string>

class Map
{
public:
  Map();
  void draw() const;
  int getHeight() const;
  int getWidth() const;
  std::vector<std::string> layout;
};

#endif
