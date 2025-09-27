#include "ghost.hpp"
#include <cstdlib>

Ghost::Ghost(int ghost_start_x, int ghost_start_y) : x(ghost_start_x), y(ghost_start_y) {}

void Ghost::move(int ghost_dx, int ghost_dy)
{
  x += ghost_dx;
  y += ghost_dy;
}

int Ghost::getX() const
{
  return x;
}

int Ghost::getY() const
{
  return y;
}

bool Ghost::tryMove(int dx, int dy, const std::vector<std::string>& layout, const std::vector<Ghost>& ghosts)
{
  int new_x = x + dx;
  int new_y = y + dy;

  /*if(new_y < 0 || new_y >= static_cast<int>(layout.size()) || new_x < 0 || new_x >= static_cast<int>(layout[0].size()))
    return false;*/

  if(layout[new_y][new_x] == '#')
    return false;

  for(const Ghost& g : ghosts)
  {
    if(&g != this && g.getX() == new_x && g.getY() == new_y)
      return false;
  }

  x = new_x;
  y = new_y;
  return true;
}
