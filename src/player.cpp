#include "player.hpp"

Pacman::Pacman(int start_x, int start_y) : x(start_x), y(start_y){}

void Pacman::move(int dx, int dy)
{
  x += dx;
  y += dy;
}

int Pacman::getX() const
{
  return x;
}

int Pacman::getY() const
{
  return y;
}
