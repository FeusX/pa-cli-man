#ifndef PLAYER_HPP
#define PLAYER_HPP

class Pacman
{
private:
  int x, y;
public:
  Pacman(int start_x, int start_y);
  void move(int dx, int dy);
  int getX() const;
  int getY() const;  
};

#endif
