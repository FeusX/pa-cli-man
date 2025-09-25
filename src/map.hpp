#ifndef MAP_HPP
#define MAP_HPP

#include <vector>
#include <string>

class Map
{
private:
  std::vector<std::string> layout;

public:
  Map();
  void draw() const;
  int getHeight() const;
  int getWidth() const;
};

#endif
