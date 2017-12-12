//
// HPlayer.cpp for game in /home/turnu_a/CPP/cpp_indie_studio/game
// 
// Made by turnu angelo
// Login   <turnu_a@epitech.net>
// 
// Started on  Fri May  6 10:50:42 2016 turnu angelo
// Last update Mon May 30 15:01:32 2016 turnu angelo
//

#include "HPlayer.hh"

HPlayer::HPlayer(int x, int y, int nb, std::string name) : APlayer(x, y, nb, name)
{
  initArray();
  if (nb == 0)
    this->_direction = 3;
  else
    this->_direction = 2;
}

HPlayer::HPlayer(HPlayer const *hp) : APlayer(hp)
{
  initArray();
  if (this->_nb == 0)
    this->_direction = 3;
  else
    this->_direction = 2;
}

HPlayer::~HPlayer()
{

}

void HPlayer::initArray()
{
  this->cmd_p[0] = &HPlayer::checkUp;
  this->cmd_p[1] = &HPlayer::checkDown;
  this->cmd_p[2] = &HPlayer::checkLeft;
  this->cmd_p[3] = &HPlayer::checkRight;
  this->cmd_p[4] = &HPlayer::putBomb;
}

int HPlayer::checkLife()
{
  if (this->_isAlive == false)
    return (-400);
  return (this->_x - 265);
}

void HPlayer::updatePos(std::map<int, int[2]> *pos)
{
  (*pos)[this->_nb][0] = checkLife();
  (*pos)[this->_nb][1] = this->_y - 140;
}

int HPlayer::checkPos(int x, int y)
{
  if (x == (this->_x / 35) && y == (this->_y / 35))
    return (0);
  return (1);
}

void HPlayer::checkFlamesEnd(int x, int y, std::array <std::array <t_case, 8> , 15 > *gameMap)
{
  if (this->_isOnBomb == true && checkPos(x, y) == 0)
    (*gameMap)[this->_x / 35][this->_y / 35].type = e_case::BOMB;
  else if ((*gameMap)[this->_x / 35][this->_y / 35].type != e_case::BOMB)
    {
      (*gameMap)[this->_x / 35][this->_y / 35].type = e_case::EMPTY;
      (*gameMap)[x][y].type = e_case::PLAYER;
    }
}

void HPlayer::checkFlames(int x, int y, std::array <std::array <t_case, 8> , 15 > *gameMap)
{
  if ((*gameMap)[x][y].type == e_case::FLAM)
    this->_isAlive = false;
  else if (this->_isOnBomb == true && checkPos(x, y) == 1 && (*gameMap)[x][y].type != e_case::IND_BLOC && (*gameMap)[x][y].type != e_case::D_BLOC && (*gameMap)[x][y].type != e_case::BOMB)
    {
      (*gameMap)[this->_x / 35][this->_y / 35].type = e_case::BOMB;
      (*gameMap)[x][y].type = e_case::PLAYER;
    }
  checkFlamesEnd(x, y, gameMap);
}

Bomb *HPlayer::doAction(e_command action, std::array <std::array <t_case, 8> , 15 > *gameMap, std::map<int, int[2]> *pos)
{
  Bomb *bomb = NULL;

  if (action != e_command::NONE)
    bomb = (this->*cmd_p[static_cast<int>(action)])(gameMap);
  else
    checkFlames(this->_x / 35, this->_y / 35, gameMap);
  updatePos(pos);
  return (bomb);
}

void HPlayer::updatePU(int x, int y, std::array <std::array <t_case, 8> , 15 > *gameMap)
{
  if ((*gameMap)[x][y].PU_type == e_PU::BOMB_1)
    nBomb();
  else if ((*gameMap)[x][y].PU_type == e_PU::POWER_1)
    fBomb();
  else
    speed();
  (*gameMap)[x][y].type = e_case::PLAYER;
  (*gameMap)[x][y].PU_type = e_PU::EMPTY;
}

void HPlayer::checkBomb(int x, int y, std::array <std::array <t_case, 8> , 15 > *gameMap)
{
  if ((*gameMap)[x][y].type == e_case::BOMB)
    this->_isOnBomb = false;
}

int HPlayer::diffBlock(int x, int y, std::array <std::array <t_case, 8> , 15 > *gameMap)
{
  if ((*gameMap)[x][y].type == e_case::D_BLOC || (*gameMap)[x][y].type == e_case::IND_BLOC || (*gameMap)[x][y].type == e_case::BOMB)
    {
      checkFlames(this->_x / 35, this->_y / 35, gameMap);
      return (1);
    }
  else if ((*gameMap)[x][y].type == e_case::PU)
    {
      checkBomb(this->_x / 35, this->_y / 35, gameMap);
      updatePU(x, y, gameMap);
    }
  else
    {
      checkFlames(x, y, gameMap);
      checkBomb(this->_x / 35, this->_y / 35, gameMap);
    }
  return (0);
}

void HPlayer::goLeft(std::array <std::array <t_case, 8> , 15 > *gameMap)
{
  int	x;
  int	y;

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

void HPlayer::goRight(std::array <std::array <t_case, 8> , 15 > *gameMap)
{
  int	x;
  int	y;

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

void HPlayer::goUp(std::array <std::array <t_case, 8> , 15 > *gameMap)
{
  int	x;
  int	y;

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

void HPlayer::goDown(std::array <std::array <t_case, 8> , 15 > *gameMap)
{
  int	x;
  int	y;

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

Bomb *HPlayer::checkUp(std::array <std::array <t_case, 8> , 15 > *gameMap)
{
  if (this->_y - 5 >= 17 && this->_direction == 0)
    goUp(gameMap);
  else //if (this->_direction != 0)
  {
    checkFlames(this->_x / 35, this->_y / 35, gameMap);
    this->_direction = 0;
  }
  return (NULL);
}

Bomb *HPlayer::checkDown(std::array <std::array <t_case, 8> , 15 > *gameMap)
{
  if (this->_y + 5 <= (280 - 17) && this->_direction == 1)
    goDown(gameMap);
  else //if (this->_direction != 1)
  {
    checkFlames(this->_x / 35, this->_y / 35, gameMap);
    this->_direction = 1;
  }
  return (NULL);
}

Bomb *HPlayer::checkLeft(std::array <std::array <t_case, 8> , 15 > *gameMap)
{
  if (this->_x - 5 >= 17 && this->_direction == 2)
    goLeft(gameMap);
  else //if (this->_direction != 2)
  {
    checkFlames(this->_x / 35, this->_y / 35, gameMap);
    this->_direction = 2;
  }
  return (NULL);
}

Bomb *HPlayer::checkRight(std::array <std::array <t_case, 8> , 15 > *gameMap)
{
  if (this->_x + 5 <= (525 - 17) && this->_direction == 3)
    goRight(gameMap);
  else //if (this->_direction != 3)
  {
    checkFlames(this->_x / 35, this->_y / 35, gameMap);
    this->_direction = 3;
  }
  return (NULL);
}

Bomb *HPlayer::putBomb(std::array <std::array <t_case, 8> , 15 > *gameMap)
{
  if ((*gameMap)[this->_x / 35][this->_y / 35].type != e_case::BOMB && this->_nbBomb > 0)
    {
      this->_isOnBomb = true;
      this->_nbBomb--;
      return (new Bomb(this));
    }
  return (NULL);
}
