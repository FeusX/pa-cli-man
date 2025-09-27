#include "game.hpp"
#include <ncurses.h>

Game::Game() : pacman(1, 1), running(true){}

void Game::run()
{
  while(running)
  {
    clear();
    map.draw();

    mvaddch(pacman.getY(), pacman.getX(), 'C');

    refresh();

    int ch = getch();
    int dx = 0, dy = 0;

    switch(ch)
    {
      case 'w' : dy = -1; break;
      case 's' : dy = 1; break;
      case 'a' : dx = -1; break;
      case 'd' : dx = 1; break;
      default: continue;
    }
  
    int new_x = pacman.getX() + dx;
    int new_y = pacman.getY() + dy;

    if(new_y >= 0 && new_y < map.getHeight() && new_x >= 0 && new_x < map.getWidth())
    {
      char target_char = mvinch(new_y, new_x) & A_CHARTEXT;

      if(target_char != '#')
      {
        pacman.move(dx, dy);

        if(target_char = '.')
          map.layout[new_y][new_x] = ' ';
          mvaddch(new_y, new_x, ' ');
      }
    }
  }
} 
