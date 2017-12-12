#ifndef NEWGAME_HPP
#define NEWGAME_HPP

#include "irrlicht.hpp"
#include "MenuEventReceiver.hpp"

class	NewGame {
  MenuEventReceiver*                      receiver;
  irr::IrrlichtDevice*			device;
  irr::video::IVideoDriver*             driver;
  irr::scene::ISceneManager*            smgr;
  irr::gui::IGUIEnvironment*            guienv;
  irrklang::ISoundEngine*		engine;
  irr::gui::IGUIStaticText*		info;
  std::string*				nbPlayers;
  irr::gui::IGUIEditBox*		player1;
  irr::gui::IGUIEditBox*                player2;
  irr::video::ITexture*                 button;
  irr::video::ITexture*                 littlebutton;

public:
  NewGame(irr::IrrlichtDevice*, MenuEventReceiver*);
  ~NewGame() {};

  //GETTERS
  MenuEventReceiver*			getReceiver() const;
  irr::IrrlichtDevice*			getDevice() const;
  irr::video::IVideoDriver*             getDriver() const;
  irr::scene::ISceneManager*            getSmgr() const;
  irr::gui::IGUIEnvironment*            getGuienv() const;
  irrklang::ISoundEngine*		getEngine() const;

  //SETTERS
  void          setReceiver(MenuEventReceiver *receiver);
  void          setDevice(irr::IrrlichtDevice *device);
  void		setDriver(irr::video::IVideoDriver *driver);
  void          setSmgr(irr::scene::ISceneManager *smgr);
  void          setGuienv(irr::gui::IGUIEnvironment *guienv);
  void		setEngine(irrklang::ISoundEngine *engine);

  // Methods
  void		updateInfo();
  std::string	getNamePlayer1();
  std::string	getNamePlayer2();
};

#endif
