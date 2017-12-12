//
// game.hh for  in /home/denesys/rendu/Semestre_4/C++/cpp_indie_studio/games_j
// 
// Made by Simon Julie
// Login   <denesys@epitech.net>
// 
// Started on  Fri May  6 13:45:15 2016 Simon Julie
// Last update Fri Jun  3 21:07:40 2016 turnu angelo
//

#ifndef _GAME_HH_
# define _GAME_HH_

#include <iostream>
#include <fstream>

#include <string>
#include <vector>
#include <array>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctime>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <cstdio>
#include "map.hh"
#include "HPlayer.hh"
#include "Errors/Errors.hh"
#include "Errors/game_errors.hh"
#include "Errors/file_errors.hh"
#include "Ia.hh"

class Game
{
private:
  int	nbIa;
  int	nbPlayers;
  std::vector <APlayer*> player;
  std::vector<std::vector <int> > tabPlayer;

  std::array <std::array <t_case, 8> , 15 > mapCreation(const std::string &map_name);
  bool itsZeroBecause(int x, int y);
  void initTabSave();
  void (Game::*tab_save[7])(std::ofstream &file);

  void    saveBomb(std::ofstream &file);
  void    saveFlam(std::ofstream &file);
  void    saveIndBloc(std::ofstream &file);
  void    saveEmpty(std::ofstream &file);
  void    saveDBloc(std::ofstream &file);
  void    savePU(std::ofstream &file);
  void    savePlayer(std::ofstream &file);
  void initTabPlayer();
  void initTabPos();
  Bomb *reloadBomb(std::string file, std::vector <APlayer *> *players);
  APlayer *reloadPlayer(std::string file);
  std::string atThereIs(std::string s, int nb);

public:
  std::array <std::array <t_case, 8> , 15 > creation(const std::string &map_name);
  std::vector<APlayer *> playerCreation(int nbIa, int nbPlayers, std::vector<std::string> const &names);
  std::map<int, int[2]> getPos();
  std::string generateRandomMap();
  int updateCas(int x, int cp2, int cp);
  std::string saveMap(std::array <std::array <t_case, 8> , 15 > mapy);
  std::ofstream * openPlayerFile(std::string & file_name);
  void closePlayerFile(std::ofstream *file);
  std::array <std::array <t_case, 8> , 15> reloadMap();
  void reloadPandB(std::vector <APlayer *> *players, std::vector <Bomb *> *bombs);
  std::vector<std::wstring> *sendScore() const;
  Game();
  ~Game(){}
};

#endif
