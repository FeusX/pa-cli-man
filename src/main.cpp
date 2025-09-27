#include <ncurses.h>
#include "game.hpp"

int main()
{
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
