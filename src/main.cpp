#include <ncurses.h>
#include "map.hpp"

int main()
{
  initscr();
  noecho();
  curs_set(0);
  keypad(stdscr, TRUE);

  Map m;
  m.draw();

  refresh();
  getch();

  endwin();

  return 0;
}
