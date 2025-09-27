#ifndef GHOST_HPP
#define GHOST_HPP

#include <vector>
#include <string>

class Ghost
{
private:
  int x, y;
public:
  Ghost(int ghost_start_x, int ghost_start_y);
  void move(int ghost_dx, int ghost_dy);
  int getY() const;
  int getX() const;
  bool tryMove(int dx, int dy, const std::vector<std::string>& layout, const std::vector<Ghost>& ghosts);  
};

#endif
