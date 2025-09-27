#ifndef GAME_HPP
#define GAME_HPP

#include "map.hpp"
#include "player.hpp"

class Game
{
private:
  Map map;
  Pacman pacman;
  bool running;
public:
  Game();
  void run();
};

#endif
