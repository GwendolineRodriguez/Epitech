#ifndef MENU_HPP_
#define MENU_HPP_

#include "irrlicht.hpp"
#include "irrKlang-64bit-1.5.0/include/irrKlang.h"

class MenuEventReceiver;

class	Menu {
  //Wallpaper
  irr::video::ITexture*			image;
  irr::video::ITexture*			button;
  irr::core::dimension2d<irr::u32>	taille;
  irr::core::position2d<irr::s32>	position0;
  irr::core::position2d<irr::s32>	position1;
  irr::core::rect<irr::s32>		rectangle;

  MenuEventReceiver*			menuHey;
  irr::IrrlichtDevice*			menuDevice;
  irr::video::IVideoDriver*             menuDriver;
  irr::scene::ISceneManager*            menuSmgr;
  irr::gui::IGUIEnvironment*            menuGuienv;
  irr::gui::IGUISkin*			skin;
  irr::gui::IGUIFont*			font;
  irrklang::ISoundEngine*		menuEngine;
  std::vector <std::wstring>*		score;
  int					nbHuman;
  int					nbIA;
  int					mode;
  std::string				player1;
  std::string				player2;

public:
  Menu(irr::IrrlichtDevice* device);
  ~Menu() {};

  enum Mode {
    DEFAULT,
    NEWGAME,
    CONTINUE,
    CONTROLS,
    CREDITS,
    SCORES,
    QUIT,
    EXIT
  };

  // GETTERS
  MenuEventReceiver*			getMenuHey() const;
  irr::video::IVideoDriver*             getMenuDriver() const;
  irr::scene::ISceneManager*            getMenuSmgr() const;
  irr::gui::IGUIEnvironment*            getMenuGuienv() const;
  irrklang::ISoundEngine*               getMenuEngine() const;
  std::vector <std::wstring>*		getScore() const;
  std::string				getNamePlayer1() const;
  std::string                          getNamePlayer2() const;
  int const				&getNbHuman() const;
  int const				&getNbIA() const;
  int					getMode();

  // SETTERS
  void					setMenuHey(MenuEventReceiver *h);
  void					setMenuDriver(irr::video::IVideoDriver *iv);
  void					setMenuSmgr(irr::scene::ISceneManager *is);
  void					setMenuGuienv(irr::gui::IGUIEnvironment *ig);
  void					setMenuEngine(irrklang::ISoundEngine *sme);
  void					setScore(std::vector <std::wstring>*);
  void					setNamePlayer1(std::string);
  void					setNamePlayer2(std::string);
  void					setNbHuman(int nbH);
  void					setNbIA(int IA);
  void					setMode(Menu::Mode);

  // METHODS
  void					putButtons();
  void					putBackGameButton();
  int                                   getNbPlayers();
  void					exitMenu();
  void					exitGame();
  void					setWallpaper(irr::io::path wallpaper);
  void					drawWallpaper();
  void					drawMenu();
};

#endif
