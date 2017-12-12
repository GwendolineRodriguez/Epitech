//
// APlayer.hpp for game in /home/turnu_a/CPP/cpp_indie_studio/game
// 
// Made by turnu angelo
// Login   <turnu_a@epitech.net>
// 
// Started on  Wed May  4 14:02:41 2016 turnu angelo
// Last update Sun Jun  5 18:58:13 2016 turnu angelo
//

#ifndef APLAYER_HH__
# define APLAYER_HH__

#include "map.hh"
#include "Bomb.hh"
#include "Errors/Errors.hh"
#include "Errors/game_errors.hh"
#include "Errors/file_errors.hh"
#include <ctime>
#include <algorithm>
#include <iostream>
#include <fstream>

class Bomb;

class APlayer
{
protected:
  std::string _name;
  int _x;
  int _y;
  int _nb;
  int _nbBomb;
  int _fBomb;
  int _speed;
  int _score;
  int  _direction;
  bool _isOnBomb;
  bool _isAlive;

public:
  APlayer(int x, int y, int nb, std::string name);
  ~APlayer();
  APlayer(APlayer const *ap);
  void speed();
  void fBomb();
  void nBomb();
  int getX() const;
  void setX(int const x);
  int getY() const;
  void setY(int const y);
  int getNb() const;
  void setNb(int const nb);
  int getForce() const;
  void setForce(int const force);
  int getScore() const;
  void setScore(int const score);
  int getSpeed() const;
  void setSpeed(int const speed);
  int getDirection() const;
  void setDirection(int const direction);
  bool getOnBomb() const;
  void setOnBomb(bool isOnBomb);
  std::string getName() const;
  void setName(std::string const name);
  int getNbBomb() const;
  void setNbBomb(int const nbBomb);
  void notOnBomb();
  bool getStatus() const;
  void updateScore() const;
  void updateScoreEnd(std::vector<int> &scores, std::vector<std::string> &names) const;
  void savePlayer(std::ofstream * file_name);
  virtual Bomb *doAction(e_command action, std::array <std::array <t_case, 8> , 15 > *gameMap, std::map<int, int[2]> *pos) = 0;
};

#endif
