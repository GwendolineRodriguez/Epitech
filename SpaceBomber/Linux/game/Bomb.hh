//
// Bomb.hpp for game in /home/turnu_a/CPP/cpp_indie_studio/game
// 
// Made by turnu angelo
// Login   <turnu_a@epitech.net>
// 
// Started on  Wed May  4 16:35:54 2016 turnu angelo
// Last update Sun Jun  5 17:14:50 2016 turnu angelo
//

#ifndef BOMB_HH__
# define BOMB_HH__

#include "APlayer.hh"
#include <vector>

class APlayer;

class Bomb
{
private:
  int _x;
  int _y;
  int _force;
  APlayer *_player;
  std::vector<Bomb *> *_bombs;
  int _timeout;

public:
  Bomb(APlayer *player);
  ~Bomb();
  void saveBomb(std::ofstream * file);
  void placeBomb(std::array <std::array <t_case, 8> , 15 > *gameMap) const;
  void cleanMap(std::array <std::array <t_case, 8> , 15 > *gameMap);
  void setArray(std::vector<Bomb *> * const bombs);
  void explode(std::array <std::array <t_case, 8> , 15 > *gameMap);
  void putFlamesUp(std::array <std::array <t_case, 8> , 15 > *gameMap);
  void putFlamesDown(std::array <std::array <t_case, 8> , 15 > *gameMap);
  void putFlamesLeft(std::array <std::array <t_case, 8> , 15 > *gameMap);
  void putFlamesRight(std::array <std::array <t_case, 8> , 15 > *gameMap);
  void cleanFlamesUp(std::array <std::array <t_case, 8> , 15 > *gameMap);
  void cleanFlamesDown(std::array <std::array <t_case, 8> , 15 > *gameMap);
  void cleanFlamesLeft(std::array <std::array <t_case, 8> , 15 > *gameMap);
  void cleanFlamesRight(std::array <std::array <t_case, 8> , 15 > *gameMap);
  int convertX(int x) const;
  int convertY(int y) const;
  int getX() const;
  void setX(int const x);
  int getY() const;
  void setY(int const y);
  int getForce() const;
  void setForce(int const force);
  int getPlayer() const;
  void explodeOtherBomb(int ct, int x, int y);
  int checkPlayer(int x, int y, std::array <std::array <t_case, 8> , 15 > *gameMap, int ct);
  void powerUp(int x, int y, std::array <std::array <t_case, 8> , 15 > *gameMap);
  void placePowerUp(int x, int y, std::array <std::array <t_case, 8> , 15 > *gameMap);
  bool isNotPlayer(int const x, int const y);
  void setTimeout(int const timeout);
  int getTimeout() const;
  void (Bomb::*putFlames[4])(std::array <std::array <t_case, 8> , 15 > *gameMap);
  void (Bomb::*cleanFlames[4])(std::array <std::array <t_case, 8> , 15 > *gameMap);
};

#endif
