//
// game.cpp for  in /home/denesys/rendu/Semestre_4/C++/cpp_indie_studio/j_game
//
// Made by Simon Julie
// Login   <denesys@epitech.net>
//
// Started on  Fri May  6 14:00:31 2016 Simon Julie
// Last update Sun Jun  5 18:56:53 2016 turnu angelo
//

#include "game.hh"
#include <sstream>
#include <string>
#include <stdlib.h>


std::array <std::array <t_case, 8> , 15 > Game::mapCreation(const std::string &map_name)
{
  std::string line;
  std::ifstream myfile(map_name);
  std::array <std::array <t_case, 8> , 15 > gameMap;
  if (myfile.is_open())
    {
      int y = 0;
      while (getline(myfile, line))
	{
	  int x = 0;
	  while (line[x])
	    {
	      if (line[x] == '0')
		{
		  gameMap[x][y].type = e_case::EMPTY;
		  gameMap[x][y].PU_type = e_PU::EMPTY;
		}
	      else if (line[x] == '1')
		{
		  gameMap[x][y].type = e_case::D_BLOC;
		  gameMap[x][y].PU_type = e_PU::EMPTY;
		}
	      else
		{
		  gameMap[x][y].type = e_case::IND_BLOC;
		  gameMap[x][y].PU_type = e_PU::EMPTY;
		}
	      x++;
	    }
	  y++;
	}
      myfile.close();
      remove(map_name.c_str());
      return (gameMap);
    }
  else
    throw GameErrors("fail in open map");
}

void Game::initTabPos()
{
  this->tabPlayer[0][0] = 17 - 265;
  this->tabPlayer[0][1] = 17 - 140;
  this->tabPlayer[1][0] = (SIZE_X * 35) - (265 + 17);
  this->tabPlayer[1][1] = 1 - 140 + 17;
  this->tabPlayer[2][0] = 17 - 265;
  this->tabPlayer[2][1] = (SIZE_Y * 35) - (140 + 17);
  this->tabPlayer[3][0] = (SIZE_X * 35) - (265 + 17);
  this->tabPlayer[3][1] = (SIZE_Y * 35) - (140 + 17);
}

std::map<int, int[2]> Game::getPos()
{
  int	ct;
  std::map<int, int[2]> pos;

  this->initTabPos();
  ct = 0;
  while (ct != this->nbPlayers)
    {
      pos[ct][0] = this->tabPlayer[ct][0];
      pos[ct][1] = this->tabPlayer[ct][1];
      ct++;
    }
  while (ct != (this->nbIa + this->nbPlayers))
    {
      pos[ct][0] = this->tabPlayer[ct][0];
      pos[ct][1] = this->tabPlayer[ct][1];
      ct++;
    }
  return (pos);
}

std::vector<APlayer *> Game::playerCreation(int _nbIa, int _nbPlayers, std::vector<std::string> const &names)
{
  std::vector<APlayer *> players;
  int	ct;

  this->initTabPlayer();
  ct = 0;
  this->nbIa = _nbIa;
  this->nbPlayers = _nbPlayers;
  while (ct < _nbPlayers)
    {
      players.push_back(new HPlayer(this->tabPlayer[ct][1], this->tabPlayer[ct][2], this->tabPlayer[ct][0], names[ct]));
      ct++;
    }
  while (ct < (_nbPlayers + _nbIa))
    {
      players.push_back(new Ia(this->tabPlayer[ct][1], this->tabPlayer[ct][2], this->tabPlayer[ct][0], "IA"));
      ct++;
    }
  return (players);
}

std::array <std::array <t_case, 8> , 15 > Game::creation(const std::string &map_name)
{
  return (this->mapCreation(map_name));
}

std::vector <std::vector <int > > initZeroTab()
{
  std::vector <std::vector <int > > z;

  std::vector <int> nv;
  nv.push_back(0);
  nv.push_back(0);
  z.push_back(nv);
  nv.clear();
  nv.push_back(SIZE_X - 1);
  nv.push_back(0);
  z.push_back(nv);
  nv.clear();
  
  nv.push_back(0);
  nv.push_back(SIZE_Y - 1);
  z.push_back(nv);
  nv.clear();
  nv.push_back(SIZE_X - 1);
  nv.push_back(SIZE_Y - 1);
  z.push_back(nv);
  nv.clear();

  nv.push_back(1);
  nv.push_back(0);
  z.push_back(nv);
  nv.clear();
  nv.push_back(0);
  nv.push_back(1);
  z.push_back(nv);
  nv.clear();

  nv.push_back(0);
  nv.push_back(SIZE_Y - 1 - 1);
  z.push_back(nv);
  nv.clear();
  nv.push_back(1);
  nv.push_back(SIZE_Y- 1);
  z.push_back(nv);
  nv.clear();

  nv.push_back(SIZE_X - 1 - 1);
  nv.push_back(0);
  z.push_back(nv);
  nv.clear();
  nv.push_back(SIZE_X - 1);
  nv.push_back(1);
  z.push_back(nv);
  nv.clear();

  nv.push_back(SIZE_X - 1 - 1);
  nv.push_back(SIZE_Y - 1);
  z.push_back(nv);
  nv.clear();
  nv.push_back(SIZE_X - 1);
  nv.push_back(SIZE_Y - 1 - 1);
  z.push_back(nv);
  nv.clear();
  return z;
}

bool Game::itsZeroBecause(int x, int y)
{
  std::vector <std::vector <int > > z;
  int cp = 0;

  z = initZeroTab();
  while (cp < 12)
    {
      if (x == z[cp][0] && y == z[cp][1])
	return true;
      cp++;
    }
  return false;
}

int Game::updateCas(int x, int cp2, int cp)
{
  if (cp2 % 2 == 0 && cp % 2 == 1)
    return (2);
  else if (x >= 28 && x < 79)
    return (1);
  else
    return (0);
}

std::string Game::generateRandomMap()
{
  std::string mapName;
  time_t t = time(0);
  struct tm * now = localtime(&t);
  std::stringstream ss;
  int cas;

  ss << now->tm_mday << "_" << now->tm_mon << "_" << now->tm_year + 1900 << "_" << now->tm_hour <<"_" << now->tm_min << "_" << now->tm_sec << ".map";
  mapName = ss.str();

  std::ofstream file (mapName, std::ios::out | std::ios::trunc);
  if (!file)
    throw FileErrors("Error in generation of map");
  int cp = 0;
  while (cp < SIZE_Y)
    {
      int cp2 = 0;
      while (cp2 < SIZE_X)
	{
	  if (!itsZeroBecause(cp2, cp))
	    {
	      int x = rand() % (SIZE_X * SIZE_Y);
	      cas = updateCas(x, cp2, cp);
	    }
	  else
	    {
	      cas = 0;
	    }
	  file << cas;
	  cp2++;
	}
      file << "\n";
      cp++;
    }
  file.close();
  return mapName;
}

void	Game::saveBomb(std::ofstream &file)
{
  file << 0;
}

void	Game::saveFlam(std::ofstream &file)
{
  file << 1;
}

void	Game::saveIndBloc(std::ofstream &file)
{
  file << 2;
}

void	Game::saveEmpty(std::ofstream &file)
{
  file << 3;
}

void	Game::saveDBloc(std::ofstream &file)
{
  file << 4;
}

void	Game::savePU(std::ofstream &file)
{
  file << 5;
}

void	Game::savePlayer(std::ofstream &file)
{
  file << 6;
}

void	Game::initTabSave()
{
  this->tab_save[0] = &Game::saveBomb;
  this->tab_save[1] = &Game::saveFlam;
  this->tab_save[2] = &Game::saveIndBloc;
  this->tab_save[3] = &Game::saveEmpty;
  this->tab_save[4] = &Game::saveDBloc;
  this->tab_save[5] = &Game::savePU;
  this->tab_save[6] = &Game::savePlayer;
}

std::string Game::saveMap(std::array <std::array <t_case, 8> , 15 > mapy)
{
  std::string mapName;
  std::string returnName;

  this->initTabSave();
  returnName = "./game/.SaveMe/.saveMe";
  mapName = returnName + ".savemap";

  std::ofstream file (mapName, std::ios::out | std::ios::trunc);
  if (!file)
    throw FileErrors("Error in save map cant open map file");
  int cp = 0;
  while (cp < SIZE_Y)
    {
      int cp2 = 0;
      while (cp2 < SIZE_X)
	{
	  if (static_cast<int>(mapy[cp2][cp].type) == 0 || static_cast<int>(mapy[cp2][cp].type) == 1 || static_cast<int>(mapy[cp2][cp].type) == 5)
	    (this->*tab_save[3])(file);
	  else
	    (this->*tab_save[static_cast<int>(mapy[cp2][cp].type)])(file);
	  cp2++;
	}
      file << "\n";
      cp++;
    }
  return (returnName);
}

std::ofstream *Game::openPlayerFile(std::string & file_name)
{
  file_name += ".saveplayer";

  std::ofstream *file = new std::ofstream(file_name, std::ios::out | std::ios::trunc);
  if (!file)
    throw FileErrors("Error in save map cant openPlayerFile");
  return (file);
}

void Game::closePlayerFile(std::ofstream *file)
{
  file->close();
}

void Game::initTabPlayer()
{
  std::vector <int> t;

  t.push_back(0);
  t.push_back(0);
  t.push_back(0);
  this->tabPlayer.push_back(t);
  t.clear();
  t.push_back(1);
  t.push_back(SIZE_X - 1);
  t.push_back(0);
  this->tabPlayer.push_back(t);
  t.clear();
  t.push_back(2);
  t.push_back(0);
  t.push_back(SIZE_Y - 1);
  this->tabPlayer.push_back(t);
  t.clear();
  t.push_back(3);
  t.push_back(SIZE_X - 1);
  t.push_back(SIZE_Y - 1);
  this->tabPlayer.push_back(t);
}

std::array <std::array <t_case, 8> , 15> Game::reloadMap()
{
  std::string line;
  std::string new_name = "./game/.SaveMe/.saveMe.savemap";
  std::ifstream myfile(new_name);
  std::array <std::array <t_case, 8> , 15> gameMap;
  if (myfile.is_open())
    {
      int y = 0;
      while (getline(myfile, line))
	{
	  int x = 0;
	  while (line[x])
	    {
	      if (line[x] != 5 && line[x] != 0)
		{
		  gameMap[x][y].type = static_cast<e_case>(line[x] - 48);
		  gameMap[x][y].PU_type = e_PU::EMPTY;
		}
	      else
		{
		  gameMap[x][y].type = e_case::EMPTY;
		  gameMap[x][y].PU_type = e_PU::EMPTY;
		}
	      x++;
	    }
	  y++;
	}
    }
  else
    throw GameErrors("fail in reload map");
  return (gameMap);
}

std::string Game::atThereIs(std::string s, int nb)
{
  int cp = 0;
  int nb_coma = 0;
  std::string la = "";
  while (s[cp])
    {
      if (s[cp] == ';')
	{
	  nb_coma++;
	  if (nb_coma == nb)
	    {
	      break;
	    }
	  la = "";
	}
      else
	la += s[cp];
      cp++;
    }
  return (la);
}

APlayer *Game::reloadPlayer(std::string line)
{
  APlayer *nv;
  if (std::stoi(this->atThereIs(line, 10)) == -1)
    {
      nv = new Ia(std::stoi(this->atThereIs(line, 2)), std::stoi(this->atThereIs(line, 3)), std::stoi(this->atThereIs(line, 4)), this->atThereIs(line,1));
      this->nbIa++;
    }
  else
    {
      nv = new HPlayer(std::stoi(this->atThereIs(line, 2)), std::stoi(this->atThereIs(line, 3)), std::stoi(this->atThereIs(line, 4)), this->atThereIs(line,1));
      this->nbPlayers++;
    }
  nv->setNbBomb(std::stoi(this->atThereIs(line, 5)));
  nv->setForce(std::stoi(this->atThereIs(line, 6)));
  nv->setScore(std::stoi(this->atThereIs(line, 7)));
  nv->setSpeed(std::stoi(this->atThereIs(line, 8)));
  nv->setDirection(std::stoi(this->atThereIs(line , 10)));
  nv->setOnBomb(static_cast <bool>(std::stoi(this->atThereIs(line, 9))));
  return (nv);
}

Bomb *Game::reloadBomb(std::string line, std::vector <APlayer *> *players)
{
  int cp = 0;
  Bomb *nv;
  while (cp < players->size())
    {
      if ((*players)[cp]->getNb() == std::stoi(this->atThereIs(line, 4)))
	{
	  nv = new Bomb((*players)[cp]);
	  return (nv);
	}
      cp++;
    }
  return (NULL);
}

bool isaNumber(std::string s)
{
  int cp = 0;
  while (s[cp])
    {
      if (s[cp] < '0' || s[cp] > '9')
	return false;
      cp++;
    }
  return true;
}


void Game::reloadPandB(std::vector <APlayer *> *players, std::vector <Bomb *> *bombs)
{
  this->nbIa = 0;
  this->nbPlayers = 0;
  std::string line;
  std::string new_name = "./game/.SaveMe/.saveMe.saveplayer";
  std::ifstream myfile(new_name);
  if (myfile.is_open())
    {
      while (getline(myfile, line))
	{
	  if (!isaNumber(this->atThereIs(line, 1)))
	    players->push_back(this->reloadPlayer(line));
	}
    }
  else
    throw GameErrors("fail in reload player");
}

std::vector<std::wstring> *Game::sendScore() const
{
  std::vector<std::wstring> *scores = new std::vector<std::wstring>;
  std::ifstream score("./game/.score/.score.txt");
  std::string line;

  if (score && score.is_open())
    {
      while (getline(score, line))
	{
	  std::wstring ws(line.begin(), line.end());
	  scores->push_back(ws);
	}
      score.close();
    }
  else
    throw GameErrors("score file not found");
  return (scores);
}


Game::Game()
{
}
