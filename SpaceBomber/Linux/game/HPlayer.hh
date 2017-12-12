//
// HPlayer.hpp for game in /home/turnu_a/CPP/cpp_indie_studio/game
// 
// Made by turnu angelo
// Login   <turnu_a@epitech.net>
// 
// Started on  Fri May  6 10:47:23 2016 turnu angelo
// Last update Mon May 30 15:07:58 2016 turnu angelo
//

#ifndef HPlayer_HH__
# define HPlayer_HH__

#include "APlayer.hh"

class HPlayer : public APlayer
{
public:
  HPlayer(int x, int y, int nb, std::string name);
  HPlayer(HPlayer const *hp);
  ~HPlayer();
  virtual Bomb *doAction(e_command action, std::array <std::array <t_case, 8> , 15 > *gameMap, std::map<int, int[2]> *pos);
  int checkLife();
  void updatePos(std::map<int, int[2]> *pos);
  int checkPos(int x, int y);
  void checkFlames(int x, int y, std::array <std::array <t_case, 8> , 15 > *gameMap);
  void checkFlamesEnd(int x, int y, std::array <std::array <t_case, 8> , 15 > *gameMap);
  void updatePU(int x, int y, std::array <std::array <t_case, 8> , 15 > *gameMap);
  void checkBomb(int x, int y, std::array <std::array <t_case, 8> , 15 > *gameMap);
  int diffBlock(int x, int y, std::array <std::array <t_case, 8> , 15 > *gameMap);
  void goLeft(std::array <std::array <t_case, 8> , 15 > *gameMap);
  void goRight(std::array <std::array <t_case, 8> , 15 > *gameMap);
  void goUp(std::array <std::array <t_case, 8> , 15 > *gameMap);
  void goDown(std::array <std::array <t_case, 8> , 15 > *gameMap);
  Bomb *checkUp(std::array <std::array <t_case, 8> , 15 > *gameMap);
  Bomb *checkDown(std::array <std::array <t_case, 8> , 15 > *gameMap);
  Bomb *checkLeft(std::array <std::array <t_case, 8> , 15 > *gameMap);
  Bomb *checkRight(std::array <std::array <t_case, 8> , 15 > *gameMap);
  Bomb *putBomb(std::array <std::array <t_case, 8> , 15 > *gameMap);
  void initArray();
  Bomb *(HPlayer::*cmd_p[5])(std::array <std::array <t_case, 8> , 15 > *gameMap);
};

#endif
