//
// Ia.hh for indie in /home/tarrou_f/Rendu/bootstrap_indieStudio
//
// Made by Frederic Tarroux
// Login   <tarrou_f@epitech.net>
//
// Started on  Fri May  6 10:51:30 2016 Frederic Tarroux
// Last update Sun Jun  5 17:36:41 2016 Frederic Tarroux
//

#ifndef IA_HH_
#define IA_HH_

#include "APlayer.hh"

class	Ia : public APlayer
{
  int	_xg;
  int	_yg;

public:
  Ia(int x, int y, int nb, std::string name);
  ~Ia();

  void	moveToPlayer(std::map<int, int[2]> *pos, std::array <std::array <t_case, 8>, 15> *const gameMap);
  int	IsItSafe(std::array <std::array <t_case, 8>, 15> *const gameMap);
  int	sentinel(std::array <std::array <t_case, 8>, 15> *const gameMap, int xs, int ys);
  void	setSafeZone(int x, int y);
  int	moveToSafeZone(std::array <std::array <t_case, 8>, 15> *const gameMap);
  int	defensive(int x, int y, std::array <std::array <t_case, 8>, 15> *const gameMap);
  int	setTarget(std::map <int, int[2]> *pos);
  void	mtszRight(std::array <std::array <t_case, 8>, 15> *const gameMap);
  void	mtszLeft(std::array <std::array <t_case, 8>, 15> *const gameMap);
  void	mtszDown(std::array <std::array <t_case, 8>, 15> *const gameMap);
  void	mtszUp(std::array <std::array <t_case, 8>, 15> *const gameMap);
  void	mtszInitArray();
  int	stIA0(std::map <int, int[2]> *pos);
  int	stIA1(std::map <int, int[2]> *pos);
  int	stIA2(std::map <int, int[2]> *pos);
  int	stIA3(std::map <int, int[2]> *pos);
  void	initTargetTab();
  int	defLeft(int x, int y, std::array <std::array <t_case, 8>, 15> *const gameMap);
  int	defRight(int x, int y, std::array <std::array <t_case, 8>, 15> *const gameMap);
  int	defUp(int x, int y, std::array <std::array <t_case, 8>, 15> *const gameMap);
  int	defDown(int x, int y, std::array <std::array <t_case, 8>, 15> *const gameMap);
  void	initDefTab();
  int	(Ia::*defTab[4])(int x, int y, std::array <std::array <t_case, 8>, 15> *const gameMap);
  int	(Ia::*targetTab[4])(std::map<int, int[2]> *pos);
  void	(Ia::*mtszTab[4])(std::array <std::array <t_case, 8> , 15 > *const gameMap);

  virtual Bomb* doAction(e_command action, std::array <std::array <t_case, 8>, 15> *const gameMap, std::map <int, int[2]> *pos);
  int checkLife();
  void updatePos(std::map<int, int[2]> *pos);
  int checkPos(int x, int y);
  void checkFlames(int x, int y, std::array <std::array <t_case, 8> , 15 > *const gameMap);
  void updatePU(int x, int y, std::array <std::array <t_case, 8> , 15 > *const gameMap);
  void checkBomb(int x, int y, std::array <std::array <t_case, 8> , 15 > *const gameMap);
  int diffBlock(int x, int y, std::array <std::array <t_case, 8> , 15 > *const gameMap);
  void goLeft(std::array <std::array <t_case, 8> , 15 > *const gameMap);
  void goRight(std::array <std::array <t_case, 8> , 15 > *const gameMap);
  void goUp(std::array <std::array <t_case, 8> , 15 > *const gameMap);
  void goDown(std::array <std::array <t_case, 8> , 15 > *const gameMap);
  Bomb *checkUp(std::array <std::array <t_case, 8> , 15 > *const gameMap);
  Bomb *checkDown(std::array <std::array <t_case, 8> , 15 > *const gameMap);
  Bomb *checkLeft(std::array <std::array <t_case, 8> , 15 > *const gameMap);
  Bomb *checkRight(std::array <std::array <t_case, 8> , 15 > *const gameMap);
  Bomb *putBomb(std::array <std::array <t_case, 8> , 15 > *const gameMap);
};

#endif
