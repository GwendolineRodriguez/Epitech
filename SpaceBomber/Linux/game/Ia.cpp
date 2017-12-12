//
// Ia.cpp for indie in /home/tarrou_f/Rendu/boostrap_IndieStudio
//
// Made by Frederic Tarroux
// Login   <tarrou_f@epitech.net>
//
// Started on  Tue May  3 11:20:25 2016 Frederic Tarroux
// Last update Sun Jun  5 17:38:23 2016 Frederic Tarroux
//

#include "Ia.hh"
#include <iostream>

Ia::Ia(int x, int y, int nb, std::string name) : APlayer(x, y, nb, name)
{
  mtszInitArray();
  initTargetTab();
  initDefTab();
  this->_direction = -1;
}

Ia::~Ia()
{
}

Bomb	*Ia::doAction(__attribute__((unused)) e_command action, std::array<std::array <t_case, 8>, 15> *const gameMap, std::map <int, int[2]> *pos)
{
  Bomb	*bomb = NULL;
  int	b;

  int	x;
  int	y;

  x = this->_x / 35;
  y = this->_y / 35;
  b = rand() % 75;
  updatePos(pos);
  if (defensive(x, y, gameMap) == 0)
    {
      moveToSafeZone(gameMap);
      checkFlames(x, y, gameMap);
      updatePos(pos);
    }
  else
    {
      if (IsItSafe(gameMap) == 0)
	moveToPlayer(pos, gameMap);
      checkFlames(x, y, gameMap);
      updatePos(pos);
      if (b == 0)
	bomb = putBomb(gameMap);
    }
  return (bomb);
}

void	Ia::initDefTab()
{
  this->defTab[0] = &Ia::defLeft;
  this->defTab[1] = &Ia::defRight;
  this->defTab[2] = &Ia::defUp;
  this->defTab[3] = &Ia::defDown;
}

int	Ia::defLeft(int x, int y, std::array<std::array <t_case, 8>, 15> *const gameMap)
{
  if (_x/35 != 0 && (*gameMap)[x - 1][y].type == e_case::EMPTY)
    {
      if (_y/35 != 7 && (*gameMap)[x - 1][y + 1].type == e_case::EMPTY)
	{
	  setSafeZone(x - 1, y + 1);
	  return (0);
	}
      else if (_y/35 != 0 && (*gameMap)[x - 1][y - 1].type == e_case::EMPTY)
	{
	  setSafeZone(x - 1, y - 1);
	  return (0);
	}
    }
  return (1);
}

int	Ia::defRight(int x, int y, std::array<std::array <t_case, 8>, 15> *const gameMap)
{
  if (_x/35 != 14 && (*gameMap)[x + 1][y].type == e_case::EMPTY)
    {
      if (_y/35 != 7 && (*gameMap)[x + 1][y + 1].type == e_case::EMPTY)
	{
	  setSafeZone(x + 1, y - 1);
	  return (0);
	}
      else if (_y/35 != 0 && (*gameMap)[x + 1][y - 1].type == e_case::EMPTY)
	{
	  setSafeZone(x + 1, y - 1);
	  return (0);
	}
    }
  return (1);
}

int	Ia::defUp(int x, int y, std::array<std::array <t_case, 8>, 15> *const gameMap)
{
  if (_y/35 != 0 && (*gameMap)[x][y - 1].type == e_case::EMPTY)
    {
      if (_x/35 != 14 && (*gameMap)[x + 1][y - 1].type == e_case::EMPTY)
	{
	  setSafeZone(x + 1, y - 1);
	  return (0);
	}
      else if (_x/35 != 0 && (*gameMap)[x - 1][y - 1].type == e_case::EMPTY)
	{
	  setSafeZone(x - 1, y - 1);
	  return (0);
	}
    }
  return (1);
}

int	Ia::defDown(int x, int y, std::array<std::array <t_case, 8>, 15> *const gameMap)
{
  if ( _y/35 != 7 && (*gameMap)[x][y + 1].type == e_case::EMPTY)
    {
      if (_x/35 != 14 && (*gameMap)[x + 1][y + 1].type == e_case::EMPTY)
	{
	  setSafeZone(x + 1, y + 1);
	  return (0);
	}
      else if (_x/35 != 0 && (*gameMap)[x - 1][y + 1].type == e_case::EMPTY)
	{
	  setSafeZone(x - 1, y + 1);
	  return (0);
	}
    }
  return (1);
}

int	Ia::defensive(int x, int y, std::array<std::array <t_case, 8>, 15> *const gameMap)
{
  int	r;

  if (sentinel(gameMap, x, y) == 1)
    {
      for (int ct = 0; ct < 4; ct++)
	{
	  r = (this->*defTab[ct])(x, y, gameMap);
	  if (r == 0)
	    return (0);
	}
      return (0);
    }
  return (1);
}

void	Ia::setSafeZone(int x, int y)
{
  if (x < 15 && y < 8 && x > -1 && y > -1)
    {
      _xg = x;
      _yg = y;
    }
}

int	Ia::moveToSafeZone(std::array<std::array <t_case, 8>, 15> *const gameMap)
{
  if (IsItSafe(gameMap) == 0)
    {
      for (int ct = 0; ct < 4; ct++)
	(this->*mtszTab[ct])(gameMap);
      return (1);
    }
  _xg = -1;
  _yg = -1;
  return (0);
}

void	Ia::mtszInitArray()
{
  this->mtszTab[0] = &Ia::mtszRight;
  this->mtszTab[1] = &Ia::mtszLeft;
  this->mtszTab[2] = &Ia::mtszDown;
  this->mtszTab[3] = &Ia::mtszUp;
}

void	Ia::mtszRight(std::array<std::array <t_case, 8>, 15> *const gameMap)
{
  if (_x / 35 < _xg)
    checkRight(gameMap);
}

void	Ia::mtszLeft(std::array<std::array <t_case, 8>, 15> *const gameMap)
{
  if (_x / 35 > _xg)
    checkLeft(gameMap);
}

void	Ia::mtszDown(std::array<std::array <t_case, 8>, 15> *const gameMap)
{
  if (_y / 35 < _yg)
    checkDown(gameMap);
}

void	Ia::mtszUp(std::array<std::array <t_case, 8>, 15> *const gameMap)
{
  if (_y / 35 > _yg)
    checkUp(gameMap);
}

int	Ia::sentinel(std::array<std::array <t_case, 8>, 15> *const gameMap, int xs, int ys)
{
  int	tmp;
  int	x;
  int	y;

  x = xs;
  y = ys;
  tmp = x;
  x = 14;
  while (x >= 0)
    {
      if ((*gameMap)[x][y].type == e_case::BOMB)
	return (1);
      x--;
    }
  x = tmp;
  y = 7;
  while (y >= 0)
    {
      if ((*gameMap)[x][y].type == e_case::BOMB)
	return (1);
      y--;
    }
  return (0);
}

int	Ia::IsItSafe(std::array<std::array <t_case, 8>, 15> *const gameMap)
{
  if (
      (this->_x/35 == 0 && this->_y/35 == 0) &&
      ((*gameMap)[this->_x / 35 + 1][this->_y / 35].type == e_case::FLAM ||
       (*gameMap)[this->_x / 35][this->_y / 35 + 1].type == e_case::FLAM) ||
      (this->_x/35 == 0 && this->_y/35 == 7) &&
      ((*gameMap)[this->_x / 35 + 1][this->_y / 35].type == e_case::FLAM ||
       (*gameMap)[this->_x / 35][this->_y / 35 - 1].type == e_case::FLAM) ||
      (this->_x/35 == 14 && this->_y/35 == 0) &&
      ((*gameMap)[this->_x / 35 - 1][this->_y / 35].type == e_case::FLAM ||
       (*gameMap)[this->_x / 35][this->_y / 35 + 1].type == e_case::FLAM) ||
      (this->_x/35 == 14 && this->_y/35 == 7) &&
      ((*gameMap)[this->_x / 35 - 1][this->_y / 35].type == e_case::FLAM ||
       (*gameMap)[this->_x / 35][this->_y / 35 - 1].type == e_case::FLAM) ||
      (this->_x/35 == 0) &&
      ((*gameMap)[this->_x / 35 + 1][this->_y / 35].type == e_case::FLAM ||
       (*gameMap)[this->_x / 35][this->_y / 35 - 1].type == e_case::FLAM ||
       (*gameMap)[this->_x / 35][this->_y / 35 + 1].type == e_case::FLAM) ||
      (this->_x/35 == 14) &&
      ((*gameMap)[this->_x / 35 - 1][this->_y / 35].type == e_case::FLAM ||
       (*gameMap)[this->_x / 35][this->_y / 35 - 1].type == e_case::FLAM ||
       (*gameMap)[this->_x / 35][this->_y / 35 + 1].type == e_case::FLAM) ||
      (this->_y/35 == 0) &&
      ((*gameMap)[this->_x / 35 + 1][this->_y / 35].type == e_case::FLAM ||
       (*gameMap)[this->_x / 35 - 1][this->_y / 35].type == e_case::FLAM ||
       (*gameMap)[this->_x / 35][this->_y / 35 + 1].type == e_case::FLAM) ||
      (this->_y/35 == 7) &&
      ((*gameMap)[this->_x / 35 + 1][this->_y / 35].type == e_case::FLAM ||
       (*gameMap)[this->_x / 35 - 1][this->_y / 35].type == e_case::FLAM ||
       (*gameMap)[this->_x / 35][this->_y / 35 - 1].type == e_case::FLAM) ||
      (_x/35 != 0 && _x/35 != 14 && _y/35 != 0 && _y/35 != 7) &&
      ((*gameMap)[this->_x / 35][this->_y / 35 - 1].type == e_case::FLAM ||
       (*gameMap)[this->_x / 35 - 1][this->_y / 35].type == e_case::FLAM ||
       (*gameMap)[this->_x / 35][this->_y / 35 + 1].type == e_case::FLAM ||
       (*gameMap)[this->_x / 35 + 1][this->_y / 35].type == e_case::FLAM)
      )
    return (1);
  return (0);
}

int	Ia::setTarget(std::map<int, int[2]> *pos)
{
  return ((this->*targetTab[_nb])(pos));
}

void	Ia::initTargetTab()
{
  this->targetTab[0] = &Ia::stIA0;
  this->targetTab[1] = &Ia::stIA1;
  this->targetTab[2] = &Ia::stIA2;
  this->targetTab[3] = &Ia::stIA3;
}

int	Ia::stIA0(std::map<int, int[2]> *pos)
{
  if ((*pos)[1][0] != -400)
    return (1);
  else if ((*pos)[2][0] != -400)
    return (2);
  return (3);
}

int	Ia::stIA1(std::map<int, int[2]> *pos)
{
  if ((*pos)[0][0] != -400)
    return (0);
  else if ((*pos)[2][0] != -400)
    return (2);
  return (3);
}

int	Ia::stIA2(std::map<int, int[2]> *pos)
{
  if ((*pos)[0][0] != -400)
    return (0);
  else if ((*pos)[1][0] != -400)
    return (1);
  return (3);
}

int	Ia::stIA3(std::map<int, int[2]> *pos)
{
  if ((*pos)[0][0] != -400)
    return (0);
  else if ((*pos)[1][0] != -400)
    return (1);
  return (2);
}


void	Ia::moveToPlayer(std::map<int, int[2]> *pos, std::array<std::array <t_case, 8>, 15> *const gameMap)
{
  int	nbt;

  nbt = setTarget(pos);
  if (
      _x/35 == 0 && _y/35 == 7 &&
      sentinel(gameMap, _x/35+1, _y/35) == 0 &&
      sentinel(gameMap, _x/35, _y/35-1) == 0 ||
      _x/35 == 0 && _y/35 == 0 &&
      sentinel(gameMap, _x/35+1, _y/35) == 0 &&
      sentinel(gameMap, _x/35, _y/35+1) == 0 ||
      _x/35 == 14 && _y/35 == 0 &&
      sentinel(gameMap, _x/35-1, _y/35) == 0 &&
      sentinel(gameMap, _x/35, _y/35+1) == 0 ||
      _x/35 == 14 && _y/35 == 7 &&
      sentinel(gameMap, _x/35-1, _y/35) == 0 &&
      sentinel(gameMap, _x/35, _y/35-1) == 0 ||
      _x/35 == 0 &&
      sentinel(gameMap, _x/35+1, _y/35) == 0 &&
      sentinel(gameMap, _x/35, _y/35+1) == 0 &&
      sentinel(gameMap, _x/35, _y/35-1) == 0 ||
      _x/35 == 14 &&
      sentinel(gameMap, _x/35-1, _y/35) == 0 &&
      sentinel(gameMap, _x/35, _y/35+1) == 0 &&
      sentinel(gameMap, _x/35, _y/35-1) == 0 ||
      _y/35 == 0 &&
      sentinel(gameMap, _x/35-1, _y/35) == 0 &&
      sentinel(gameMap, _x/35, _y/35+1) == 0 &&
      sentinel(gameMap, _x/35, _y/35-1) == 0 ||
      _y/35 == 7 &&
      sentinel(gameMap, _x/35+1, _y/35) == 0 &&
      sentinel(gameMap, _x/35-1, _y/35) == 0 &&
      sentinel(gameMap, _x/35, _y/35-1) == 0 ||
      _x/35 != 0 && _x/35 != 14 && _y/35 != 0 && _y/35 != 7 &&
      sentinel(gameMap, _x/35+1, _y/35) == 0 &&
      sentinel(gameMap, _x/35-1, _y/35) == 0 &&
      sentinel(gameMap, _x/35, _y/35+1) == 0 &&
      sentinel(gameMap, _x/35, _y/35-1) == 0
      )
    {
      (*pos)[this->_nb][0] < (*pos)[nbt][0] ? checkRight(gameMap) : checkLeft(gameMap);
      (*pos)[this->_nb][1] < (*pos)[nbt][1] ? checkDown(gameMap) : checkUp(gameMap);
    }
}

void	Ia::updatePos(std::map<int, int[2]> *pos)
{
  (*pos)[this->_nb][0] = checkLife();
  (*pos)[this->_nb][1] = this->_y - 140;
}

int	Ia::checkLife()
{
  if (this->_isAlive == false)
    return (-400);
  return (this->_x - 265);
}

int	Ia::checkPos(int x, int y)
{
  if (x == (this->_x / 35) && y == (this->_y / 35))
    return (0);
  return (1);
}

Bomb	 *Ia::putBomb(std::array <std::array <t_case, 8> , 15 > *const gameMap)
{
  if ((*gameMap)[this->_x / 35][this->_y / 35].type != e_case::BOMB && this->_nbBomb > 0)
    {
      this->_isOnBomb = true;
      this->_nbBomb--;
      return (new Bomb(this));
    }
  return (NULL);
}

int	Ia::diffBlock(int x, int y, std::array <std::array <t_case, 8> , 15 > *const gameMap)
{
  if ((*gameMap)[x][y].type == e_case::D_BLOC || (*gameMap)[x][y].type == e_case::IND_BLOC || (*gameMap)[x][y].type == e_case::BOMB)
    return (1);
  else if ((*gameMap)[x][y].type == e_case::PU)
    {
      checkBomb(this->_x / 35, this->_y / 35, gameMap);
      updatePU(x, y, gameMap);
    }
  else    {
    checkFlames(x, y, gameMap);
    checkBomb(this->_x / 35, this->_y / 35, gameMap);
  }
  return (0);
}

void	Ia::updatePU(int x, int y, std::array <std::array <t_case, 8> , 15 > *const gameMap)
{
  if ((*gameMap)[x][y].PU_type == e_PU::BOMB_1)
    nBomb();
  else if ((*gameMap)[x][y].PU_type == e_PU::POWER_1)
    fBomb();
  else    speed();
  (*gameMap)[x][y].type = e_case::PLAYER;
  (*gameMap)[x][y].PU_type = e_PU::EMPTY;
}

void	Ia::checkFlames(int x, int y, std::array <std::array <t_case, 8> , 15 > *const gameMap)
{
  if ((*gameMap)[x][y].type == e_case::FLAM)
    this->_isAlive = false;
  else if (this->_isOnBomb == true && checkPos(x, y) == 1)
    {
      (*gameMap)[this->_x / 35][this->_y / 35].type = e_case::BOMB;
      (*gameMap)[x][y].type = e_case::PLAYER;
    }
}

void	Ia::checkBomb(int x, int y, std::array <std::array <t_case, 8> , 15 > *const gameMap)
{
  if ((*gameMap)[x][y].type == e_case::BOMB)
    this->_isOnBomb = false;
}

Bomb	*Ia::checkUp(std::array <std::array <t_case, 8> , 15 > *const gameMap)
{
  if (this->_y - 5 >= 17)
    goUp(gameMap);
  return (NULL);
}

  Bomb	*Ia::checkDown(std::array <std::array <t_case, 8> , 15 > *const gameMap)
  {
    if (this->_y + 5 <= (280 - 17))
      goDown(gameMap);
    return (NULL);
  }

Bomb	*Ia::checkLeft(std::array <std::array <t_case, 8> , 15 > *const gameMap)
{
  if (this->_x - 5 >= 17)
    goLeft(gameMap);
  return (NULL);
}

Bomb	 *Ia::checkRight(std::array <std::array <t_case, 8> , 15 > *const gameMap)
{
  if (this->_x + 5 <= (525 - 17))
    goRight(gameMap);
  return (NULL);
}

void	 Ia::goLeft(std::array <std::array <t_case, 8> , 15 > *const gameMap)
{
  int   x;
  int   y;

  x = (this->_x - 5 - 8) / 35;
  y = this->_y / 35;
  if (checkPos(x, y) == 0)
    {
      checkFlames(x, y, gameMap);
      this->_x = this->_x - (5 + this->_speed);
    }
  else if (checkPos(x, y) == 1 && diffBlock(x, y, gameMap) == 0)
    this->_x = this->_x - (5 + this->_speed);
}

void	Ia::goRight(std::array <std::array <t_case, 8> , 15 > *const gameMap)
{
  int   x;
  int   y;

  x = (this->_x + 5 + 8) / 35;
  y = this->_y / 35;
  if (checkPos(x, y) == 0)
    {
      checkFlames(x, y, gameMap);
      this->_x = this->_x + (5 + this->_speed);
    }
  else if (checkPos(x, y) == 1 && diffBlock(x, y, gameMap) == 0)
    this->_x = this->_x + (5 + this->_speed);
}

void	Ia::goUp(std::array <std::array <t_case, 8> , 15 > *const gameMap)
{
  int   x;
  int   y;

  x = this->_x / 35;
  y = (this->_y - 5 - 8) / 35;
  if (checkPos(x, y) == 0)
    {
      checkFlames(x, y, gameMap);
      this->_y = this->_y - (5 + this->_speed);
    }
  else if (checkPos(x, y) == 1 && diffBlock(x, y, gameMap) == 0)
    this->_y = this->_y - (5 + this->_speed);
}

void	Ia::goDown(std::array <std::array <t_case, 8> , 15 > *const gameMap)
{
  int   x;
  int   y;

  x = this->_x / 35;
  y = (this->_y + 5 + 8) / 35;
  if (checkPos(x, y) == 0)
    {
      checkFlames(x, y, gameMap);
      this->_y = this->_y + (5 + this->_speed);
    }
  else if (checkPos(x, y) == 1 && diffBlock(x, y, gameMap) == 0)
    this->_y = this->_y + (5 + this->_speed);
}
