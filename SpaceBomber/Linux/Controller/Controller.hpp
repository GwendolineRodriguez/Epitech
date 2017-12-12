#ifndef CONTROLLER_HPP_
#define CONTROLLER_HPP_

#include <string>
#include <vector>
#include <list>
#include <map>
#include <array>
#include <pthread.h>
#include <ostream>
#include <iostream>
#include <thread>
#include "../game/game.hh"
#include "../graph/irrlicht.hpp"
#include "../graph/Menu.hpp"
#include "../graph/Victory.hpp"

class Controller
{
public:
	Controller();
	~Controller() {};
	void										loop();
	Game 										*getGame() const;
	void										setGame(Game *game);
	Init										*getLib() const;
	void										setLib(Init *lib);
	Menu										*getMenu() const;
	void 										setMenu(Menu *menu);
	std::array <std::array <t_case, 8> , 15 >	*getMap() const;
	void										setMap(std::array <std::array <t_case, 8> , 15 > &gameMap);
	std::map <int, int[2]>						*getPos() const;
	void										setPos(std::map <int, int[2]> *pos);
	std::vector<APlayer*>						*getPlayers();
	std::vector<Bomb*>							*getBombs();
	void										setPlayers(std::vector<APlayer*> players);
	int 										getNbPlayers() const;
	void										setNbPlayers(int nbPlayers);
	e_command									getAction() const;
	void										setAction(e_command &action);
	void										fillCheckMapInfos(int, int, int, int);
	void										setBombsOnFire(int);
	void										saveMe(int);
	int 										doAction(int);
	void 										placeBomb(int);
	int 										getPlayerStatus(int);
	void										getKeyPlayer(int);
private:
	Game 										*game;
	Init										*lib;
	Menu										*menu;
	std::array <std::array <t_case, 8> , 15 > 	*gameMap;
	std::map <int, int[2]> 						*pos;
	std::vector<APlayer*> 						players;
	int											nbPlayers;
	int 										nbHuman;
	e_command									action;
	std::vector<Bomb*>							bombs;
	std::vector<bool> 							exploded;
	std::vector<int> 							fire;
	std::vector<int> 							checkMapInfos;
	std::string 								save;
	std::ofstream								*file;
	Bomb 										*bomb;
	bool 										done;
};

#endif
