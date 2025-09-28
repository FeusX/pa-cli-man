#include <ncurses.h>
#include "game.hpp"
#include <ctime>

int main()
{
  srand(time(nullptr));
  
  initscr();
  noecho();
  curs_set(0);
  keypad(stdscr, TRUE);
  timeout(100);

  Game g;
  g.run();
  
  endwin();

  return 0;
}
