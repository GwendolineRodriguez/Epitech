//
// Bomb.cpp for game in /home/turnu_a/CPP/cpp_indie_studio/game
// 
// Made by turnu angelo
// Login   <turnu_a@epitech.net>
// 
// Started on  Wed May  4 16:36:00 2016 turnu angelo
// Last update Sun Jun  5 17:14:32 2016 turnu angelo
//

#include "Bomb.hh"

Bomb::Bomb(APlayer *player)
{
  this->_timeout = 35;
  this->_player = player;
  this->_x = convertX(player->getX());
  this->_y = convertY(player->getY());
  this->_force = player->getForce();
  this->putFlames[0] = &Bomb::putFlamesUp;
  this->putFlames[1] = &Bomb::putFlamesDown;
  this->putFlames[2] = &Bomb::putFlamesLeft;
  this->putFlames[3] = &Bomb::putFlamesRight;
  this->cleanFlames[0] = &Bomb::cleanFlamesUp;
  this->cleanFlames[1] = &Bomb::cleanFlamesDown;
  this->cleanFlames[2] = &Bomb::cleanFlamesLeft;
  this->cleanFlames[3] = &Bomb::cleanFlamesRight;
}

Bomb::~Bomb()
{

}

bool Bomb::isNotPlayer(int const x, int const y)
{
  int	nX;
  int	nY;

  nX = convertX(this->_player->getX());
  nY = convertY(this->_player->getY());
  if (x == nX && y == nY)
    return (false);
  return (true);
}

int Bomb::getX() const
{
  return (this->_x);
}

int Bomb::getY() const
{
  return (this->_y);
}

int Bomb::getForce() const
{
  return (this->_force);
}

int Bomb::convertX(int x) const
{
  return (x / 35);
}

int Bomb::convertY(int y) const
{
  return (y / 35);
}

void Bomb::setArray(std::vector<Bomb *> * const bombs)
{
  this->_bombs = bombs;
}

void Bomb::placeBomb(std::array <std::array <t_case, 8> , 15 > *gameMap) const
{
  (*gameMap)[this->_x][this->_y].type = e_case::BOMB;
}

void Bomb::explodeOtherBomb(int ct, int x, int y)
{
  if ((*this->_bombs)[ct]->getX() == x && (*this->_bombs)[ct]->getY() == y)
    (*this->_bombs)[ct]->_timeout = 0;
}

int Bomb::checkPlayer(int x, int y, std::array <std::array <t_case, 8> , 15 > *gameMap, int ct)
{
  if ((*gameMap)[x][y].type == e_case::PLAYER && isNotPlayer(x, y) == true)
    this->_player->setScore(this->_player->getScore() + 5);
  else if ((*gameMap)[x][y].type == e_case::BOMB)
    {
      for (int ct = 0; ct != (*this->_bombs).size(); ct++)
	explodeOtherBomb(ct, x, y);
      return (this->_force - 1);
    }
  (*gameMap)[x][y].type = e_case::FLAM;
  return (ct);
}

void Bomb::powerUp(int x, int y, std::array <std::array <t_case, 8> , 15 > *gameMap)
{
  if ((*gameMap)[x][y].PU_type == e_PU::EMPTY && rand() % 2 == 0)
    (*gameMap)[x][y].PU_type = static_cast<e_PU>(rand() % 3);
  this->_player->setScore(this->_player->getScore() + 1);
}

void Bomb::placePowerUp(int x, int y, std::array <std::array <t_case, 8> , 15 > *gameMap)
{
  if ((*gameMap)[x][y].PU_type != e_PU::EMPTY)
    (*gameMap)[x][y].type = e_case::PU;
  else
    (*gameMap)[x][y].type = e_case::EMPTY;
}

void Bomb::cleanFlamesUp(std::array <std::array <t_case, 8> , 15 > *gameMap)
{
  int	ct;
  int	y;

  ct = 0;
  y = this->_y - 1;
  while (ct != this->_force && y >= 0)
    {
      if ((*gameMap)[this->_x][y].type == e_case::FLAM)
	placePowerUp(this->_x, y, gameMap);
      else if ((*gameMap)[this->_x][y].type == e_case::IND_BLOC)
	break;
      ct++;
      y--;
    }
}

void Bomb::cleanFlamesDown(std::array <std::array <t_case, 8> , 15 > *gameMap)
{
  int	ct;
  int	y;

  ct = 0;
  y = this->_y + 1;
  while (ct != this->_force && y <= 7)
    {
      if ((*gameMap)[this->_x][y].type == e_case::FLAM)
	placePowerUp(this->_x, y, gameMap);
      else if ((*gameMap)[this->_x][y].type == e_case::IND_BLOC)
	break;
      ct++;
      y++;
    }
}

void Bomb::cleanFlamesLeft(std::array <std::array <t_case, 8> , 15 > *gameMap)
{
  int	ct;
  int	x;

  ct = 0;
  x = this->_x - 1;
  while (ct != this->_force && x >= 0)
    {
      if ((*gameMap)[x][this->_y].type == e_case::FLAM)
	placePowerUp(x, this->_y, gameMap);
      else if ((*gameMap)[x][this->_y].type == e_case::IND_BLOC)
	break;
      ct++;
      x--;
    }
}

void Bomb::cleanFlamesRight(std::array <std::array <t_case, 8> , 15 > *gameMap)
{
  int	ct;
  int	x;

  ct = 0;
  x = this->_x + 1;
  while (ct != this->_force && x % 15 != 0)
    {
      if ((*gameMap)[x][this->_y].type == e_case::FLAM)
	placePowerUp(x, this->_y, gameMap);
      else if ((*gameMap)[x][this->_y].type == e_case::IND_BLOC)
	break;
      ct++;
      x++;
    }
}

void Bomb::putFlamesUp(std::array <std::array <t_case, 8> , 15 > *gameMap)
{
  int	ct;
  int	y;

  ct = 0;
  y = this->_y - 1;
  while (ct != this->_force && y >= 0)
    {
      if ((*gameMap)[this->_x][y].type == e_case::IND_BLOC)
	break;
      else if ((*gameMap)[this->_x][y].type == e_case::D_BLOC)
	{
	  (*gameMap)[this->_x][y].type = e_case::FLAM;
	  powerUp(this->_x, y, gameMap);
	  break;
	}
      else
	ct = checkPlayer(this->_x, y, gameMap, ct);
      ct++;
      y--;
    }
}

void Bomb::putFlamesDown(std::array <std::array <t_case, 8> , 15 > *gameMap)
{
  int	ct;
  int	y;

  ct = 0;
  y = this->_y + 1;
  while (ct != this->_force && y <= 7)
    {
      if ((*gameMap)[this->_x][y].type == e_case::IND_BLOC)
	break;
      else if ((*gameMap)[this->_x][y].type == e_case::D_BLOC)
	{
	  (*gameMap)[this->_x][y].type = e_case::FLAM;
	  powerUp(this->_x, y, gameMap);
	  break;
	}
      else
	ct = checkPlayer(this->_x, y, gameMap, ct);
      ct++;
      y++;
    }
}

void Bomb::putFlamesLeft(std::array <std::array <t_case, 8> , 15 > *gameMap)
{
  int	ct;
  int	x;

  ct = 0;
  x = this->_x - 1;
  while (ct != this->_force && x >= 0)
    {
      if ((*gameMap)[x][this->_y].type == e_case::IND_BLOC)
	break;
      else if ((*gameMap)[x][this->_y].type == e_case::D_BLOC)
	{
	  (*gameMap)[x][this->_y].type = e_case::FLAM;
	  powerUp(x, this->_y, gameMap);
	  break;
	}
      else
	ct = checkPlayer(x, this->_y, gameMap, ct);
      ct++;
      x--;
    }
}

void Bomb::putFlamesRight(std::array <std::array <t_case, 8> , 15 > *gameMap)
{
  int	ct;
  int	x;

  ct = 0;
  x = this->_x + 1;
  while (ct != this->_force && x % 15 != 0)
    {
      if ((*gameMap)[x][this->_y].type == e_case::IND_BLOC)
	break;
      else if ((*gameMap)[x][this->_y].type == e_case::D_BLOC)
	{
	  (*gameMap)[x][this->_y].type = e_case::FLAM;
	  powerUp(x, this->_y, gameMap);
	  break;
	}
      else
	ct = checkPlayer(x, this->_y, gameMap, ct);
      ct++;
      x++;
    }
}

void Bomb::explode(std::array <std::array <t_case, 8> , 15 > *gameMap)
{
  int	ct;

  ct = 0;
  this->_player->notOnBomb();
  (*gameMap)[this->_x][this->_y].type = e_case::FLAM;
  while (ct != 4)
    {
      (this->*putFlames[ct])(gameMap);
      ct++;
    }
}

void Bomb::cleanMap(std::array <std::array <t_case, 8> , 15 > *gameMap)
{
  int	ct;

  ct = 0;
  (*gameMap)[this->_x][this->_y].type = e_case::EMPTY;
  while (ct != 4)
    {
      (this->*cleanFlames[ct])(gameMap);
      ct++;
    }
  this->_player->nBomb();
}

void Bomb::setTimeout(int const timeout)
{
  this->_timeout = timeout;
}

int Bomb::getTimeout() const
{
  return (this->_timeout);
}

int Bomb::getPlayer() const
{
  return (this->_player->getNb());
}

void Bomb::saveBomb(std::ofstream * file)
{
  this->_player->setNbBomb(this->_player->getNbBomb() + 1);
  *file << this->_x << ";" << this->_y << ";" << this->_force << ";" << this->_player->getNb() << ";" << this->_timeout << ";\n" ;
}

void Bomb::setX(int const x)
{
  this->_x = x;
}

void Bomb::setY(int const y)
{
  this->_y = y;
}

void Bomb::setForce(int const force)
{
  this->_force = force;
}
