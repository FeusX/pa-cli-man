#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include "map.hpp"
#include "player.hpp"
#include "ghost.hpp"

class Game
{
private:
  Map map;
  Pacman pacman;
  std::vector<Ghost> ghosts;
  bool running;
public:
  Game();
  void run();
};

#endif
