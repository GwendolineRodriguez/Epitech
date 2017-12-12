#include "./Controller.hpp"

Controller::Controller()
{
	this->checkMapInfos.push_back(0);
	this->checkMapInfos.push_back(0);
	this->checkMapInfos.push_back(0);
	this->checkMapInfos.push_back(0);
	this->done = false;
	this->action = e_command::NONE;
}

Game 										*Controller::getGame() const {
	return (this->game);
}
void										Controller::setGame(Game *g) {
	this->game = g;
}

Init										*Controller::getLib() const {
	return (this->lib);
}

void										Controller::setLib(Init *l) {
	this->lib = l;
}

Menu										*Controller::getMenu() const {
	return (this->menu);
}

void										Controller::setMenu(Menu *m) {
	this->menu = m;
}

std::array <std::array <t_case, 8> , 15 >	*Controller::getMap() const {
	return (this->gameMap);
}

void										Controller::setMap(std::array <std::array <t_case, 8> , 15 > &g) {
	this->gameMap = &g;
}

std::map <int, int[2]>						*Controller::getPos() const {
	return (this->pos);
}

void										Controller::setPos(std::map <int, int[2]> *p) {
	this->pos = p;
}

std::vector<APlayer*>						*Controller::getPlayers() {
	return (&this->players);
}

std::vector<Bomb*>							*Controller::getBombs() {
	return (&this->bombs);
}

void										Controller::setPlayers(std::vector<APlayer*> p) {
	this->players = p;
}

int 										Controller::getNbPlayers() const {
	return (this->nbPlayers);
}

void										Controller::setNbPlayers(int nb) {
	this->nbPlayers = nb;
}

e_command									Controller::getAction() const {
	return (this->action);
}

void										Controller::setAction(e_command &ac) {
	this->action = ac;
}

void										Controller::fillCheckMapInfos(int a, int b, int c, int d)
{
	this->checkMapInfos[0] = a;
	this->checkMapInfos[1] = b;
	this->checkMapInfos[2] = c;
	this->checkMapInfos[3] = d;
}

void										Controller::setBombsOnFire(int i)
{
	if (this->bombs[i]->getTimeout() <= 0 && this->exploded[i] == false) {
		this->fire[i] = 1;
		this->bombs[i]->explode(this->gameMap);
		this->exploded[i] = true;
	}
	else if (this->bombs[i]->getTimeout() <= -11 && this->exploded[i] == true) {
		this->fire[i] = 0;
		this->bombs[i]->cleanMap(this->gameMap);
		this->bombs.erase(this->bombs.begin() + i);
		this->exploded.erase(this->exploded.begin() + i);
		this->fire.erase(this->fire.begin() + i);
	}
	this->fillCheckMapInfos(this->bombs[i]->getX(), this->bombs[i]->getY(), this->bombs[i]->getForce(), this->fire[i]);
	this->lib->checkMap(this->gameMap, &this->checkMapInfos);
	this->bombs[i]->setTimeout(this->bombs[i]->getTimeout() - 1);
	this->fire[i] = this->fire[i] + 2;
}

void										Controller::saveMe(int i)
{
	if (this->players.size() != 1) {
		this->save = this->game->saveMap(*this->gameMap);
		this->file = this->game->openPlayerFile(this->save);
		for (i = 0; i < this->bombs.size(); ++i)
		  this->bombs[i]->saveBomb(this->file);
		for (i = 0; i < this->players.size(); ++i)
		  this->players[i]->savePlayer(this->file);
		this->game->closePlayerFile(this->file);	
	}
	else if (this->action != e_command::EXIT && this->players.size() == 1)
	{
	  	Vict 								end(this->getLib()->getDevice(), this->getLib()->getHey());
	  	end.dispWin(this->players[0]->getNb());
		this->players[0]->updateScore();
	}
}

int 										Controller::doAction(int i)
{
	if (this->action == e_command::EXIT || this->players.size() <= 1) {
		this->saveMe(i);
		this->done = true;
		return (this->players.size());
	}
	else if (this->action != e_command::NONE) {
		this->bomb = this->players[i]->doAction(this->action, this->gameMap, this->pos);
	}
	else{
		this->bomb = this->players[i]->doAction(this->action, this->gameMap, this->pos);
	}
	return (i);
}

void 										Controller::placeBomb(int i)
{
	if (this->bomb != NULL && i < this->players.size()) {
		this->bombs.push_back(this->bomb);
		this->exploded.push_back(false);
		this->fire.push_back(0);
		this->bombs.back()->placeBomb(this->gameMap);
		this->bombs.back()->setArray(&this->bombs);
	}
}

void										Controller::getKeyPlayer(int i)
{
	if (this->nbHuman > 1 && this->players[i]->getNb() == 1)
		this->action = this->lib->getKeyPlayer2(this->pos);
	else if (this->nbHuman >= 1 && this->players[i]->getNb() == 0)
		this->action = this->lib->getKeyPlayer1(this->pos);
	else
		this->action = e_command::NONE;
}

int 										Controller::getPlayerStatus(int i)
{
	if (this->players[i]->getStatus() != false)
		i++;
	else
		this->players.erase(this->players.begin() + i);
	return (i);
}

void										Controller::loop()
{
	int 									i = 0;

	this->nbHuman = this->getMenu()->getNbHuman();
	this->lib->setWallpaper("./graph/irrlicht-1.8.3/media/Background1.png", this->lib->getDriver());
	while (!this->done && this->lib->getDevice()->run())
	{
		this->bomb = NULL;
		for (i = 0; i < this->bombs.size(); ++i) {
			this->setBombsOnFire(i);
		}
		if (this->bombs.size() == 0) {
			this->fillCheckMapInfos(-420, -420, -420, -420);
			this->lib->checkMap(this->gameMap, &this->checkMapInfos);
		}
		i = 0;
		while (i < this->players.size())
		{
			this->getKeyPlayer(i);
			i = this->doAction(i);
			if (!this->done)
				this->placeBomb(i);
			else
				break;
			this->lib->checkPlayer(this->pos, this->players.size());
			i = this->getPlayerStatus(i);
		}
		if (this->action != e_command::EXIT && !done) {
			this->lib->movePlayer(this->pos, this->players.size());
			this->lib->Draw(this->lib->getDriver());
		}
	}
}
