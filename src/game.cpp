#include <ncurses.h>
#include <cstdlib>
#include "game.hpp"

Game::Game() : pacman(1, 1), running(true)
{
  ghosts.reserve(5);

  ghosts.emplace_back(10, 10);
  ghosts.emplace_back(20, 5);
  ghosts.emplace_back(30, 15);
  ghosts.emplace_back(35, 7);
  ghosts.emplace_back(25, 12);
}

void Game::run()
{
  int dx = 0, dy = 0;
  int last_ch = ERR;

  while(running)
  {
    clear();
    map.draw();

    mvaddch(pacman.getY(), pacman.getX(), 'C');

    for(Ghost& ghost : ghosts)
    {
      int dir = rand() % 4;
      int ghost_dx = 0, ghost_dy = 0;

      switch(dir)
      {
        case 0: ghost_dy = -1; break;
        case 1: ghost_dy = 1; break;
        case 2: ghost_dx = -1; break;
        case 3: ghost_dx = 1; break; 
      }

      ghost.tryMove(ghost_dx, ghost_dy, map.layout, ghosts);
      mvaddch(ghost.getY(), ghost.getX(), 'G');
    }
    
    refresh();

    int ch = getch();

    if(ch != ERR)
    {
      if(ch != last_ch)
      {
        switch(ch)
        {
          case 'w' : dy = -1; dx = 0; break;
          case 's' : dy = 1; dx = 0; break;
          case 'a' : dx = -1; dy = 0; break;
          case 'd' : dx = 1; dy = 0; break;
          default: dx = dy = 0; break;
        }

        last_ch = ch;

        int new_x = pacman.getX() + dx;
        int new_y = pacman.getY() + dy;

        if(new_y >= 0 && new_y < map.getHeight() && new_x >= 0 && new_x < map.getWidth())
        {
          char target_char = mvinch(new_y, new_x) & A_CHARTEXT;
          if(target_char != '#')
          {
            pacman.move(dx, dy);

            if(target_char == '.')
            {
              map.layout[new_y][new_x] = ' ';
              mvaddch(new_y, new_x, ' ');
            }
          }
        }   
      }
    }		
		else
		{
		  last_ch = ERR;
		}
		for(const Ghost& ghost : ghosts)
		{
		  if(pacman.getX() == ghost.getX() && pacman.getY() == ghost.getY())
  		{
	  	  running = false;
	  	  break;
		  }
		}
  }
} 
