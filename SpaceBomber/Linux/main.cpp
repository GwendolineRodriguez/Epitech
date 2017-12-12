#include "../Controller/Controller.hpp"

void											deleteThings(Controller *controller, Menu *menu, Init *lib, Game *game)
{
	delete(lib);
	delete(menu);
	delete(game);
	delete(controller);
}

int												main(int argc, char const *argv[])
{
	Splash										*screen = new Splash();
	std::thread 								splashScreen(&do_splash, screen);
	bool 										done = false;
	std::array <std::array <t_case, 8> , 15 > 	gameMap;
	std::map <int, int[2]> 						pos;
	srand(time(NULL));
	splashScreen.join();

	while (!done)
	{
		Controller									*controller = new Controller();
		Game										*game = new Game();
		controller->setGame(game);
		Menu										*menu = new Menu(screen->getDevice());
		
		menu->setMode(Menu::DEFAULT);
		screen->getHey()->restart();
		controller->setMenu(menu);
		controller->getMenu()->drawMenu();
		try {
			controller->getMenu()->setScore(game->sendScore());			
		}
		catch ( std::exception message) {
			std::cerr << "Erreur de Fichier de Scores." << message.what() << std::endl;
			return (-1);
		}
		controller->setNbPlayers(controller->getMenu()->getNbIA() + controller->getMenu()->getNbHuman());
		if (controller->getMenu()->getMode() == Menu::QUIT || screen->getDevice() == NULL || controller->getNbPlayers() == -1)
		  return 1;
	    
	    Init 										*lib = new Init(screen->getDevice(), screen->getHey(), screen->getEngine());
		int 										nbIa = 0;
		int 										nbHuman = 0;
		std::vector<std::string> 					names(0);
		
		controller->setLib(lib);
		if (controller->getMenu()->getMode() != Menu::CONTINUE)
		{
			gameMap = game->creation(game->generateRandomMap());
			for (int i = 0; i < controller->getMenu()->getNbHuman(); ++i) {
				names.push_back((i == 0 ? menu->getNamePlayer1() : menu->getNamePlayer2()));
			}
		}
		else if (controller->getMenu()->getMode() != Menu::NEWGAME)
		{
			std::vector<APlayer*>	*plyrs = controller->getPlayers();
			gameMap = game->reloadMap();
			game->reloadPandB(plyrs, controller->getBombs());
			controller->setNbPlayers(plyrs->size());
			for (int i = 0; i < plyrs->size(); ++i) {
				if ((*plyrs)[i]->getDirection() == -1)
					nbIa++;
				else
				{
					names.push_back((nbHuman == 0 ? menu->getNamePlayer1() : menu->getNamePlayer2()));
					nbHuman++;
				}
			}
			game->playerCreation(nbIa, nbHuman, names);
		}
		else
			return (0);
		controller->setMap(gameMap);
		if (controller->getNbPlayers() <= 4 && controller->getNbPlayers() > 1 && controller->getMenu()->getMode() != Menu::CONTINUE)
			controller->setPlayers(game->playerCreation(controller->getMenu()->getNbIA(), controller->getMenu()->getNbHuman(), names));
		else if (controller->getMenu()->getMode() != Menu::CONTINUE) {
			std::cerr << "Erreur de création des joueurs." << std::endl;
			return (-1);
		}
		
		try {
			pos = game->getPos();
			controller->setPos(&(pos));
		}
		catch ( std::exception message ) {
			std::cerr << "Erreur de création des pos." << message.what() << std::endl;
			return (-1);
		}
		try {
			if (controller->getMenu()->getMode() == Menu::CONTINUE)
				lib->initMap(controller->getMap(), controller->getPos(), nbIa + nbHuman);
			else
				lib->initMap(controller->getMap(), controller->getPos(), controller->getMenu()->getNbIA() + controller->getMenu()->getNbHuman());
		}
		catch ( std::exception message ) {
			std::cerr << "Erreur d'initialisation de la lib." << message.what() << std::endl;
			return (-1);
		}
		try {
			controller->loop();
		}
		catch ( std::exception message ) {
			std::cerr << "Erreur dans le Jeu." << message.what() << std::endl;
		}
		deleteThings(controller, menu, lib, game);
	}
	delete(screen);
	return (0);
}
