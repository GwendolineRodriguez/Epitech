#ifndef MENUEVENTRECEIVER_HPP
#define MENUEVENTRECEIVER_HPP

#include "irrlicht-1.8.3/include/irrlicht.h"
#include "Credits.hpp"
#include "Menu.hpp"
#include "Controls.hpp"
#include "Score.hpp"
#include "Continue.hpp"
#include "NewGame.hpp"

class Credits;
class Menu;
class Controls;
class Score;
class Continue;
class NewGame;

class MenuEventReceiver : public irr::IEventReceiver {
  //  bool KeyIsDown[irr::KEY_KEY_CODES_COUNT];
  irr::IrrlichtDevice*	device;
  Menu*			menu;
  NewGame*		newGame;

public:
  enum {
    GUI_ID_NEWGAME,
    GUI_ID_CONTINUE,
    GUI_ID_CONTROLS,
    GUI_ID_CREDITS,
    GUI_ID_SCORES,
    GUI_ID_QUIT,

    GUI_ID_STARTGAME,
    GUI_ID_ZEROPLAYER,
    GUI_ID_ONEPLAYER,
    GUI_ID_TWOPLAYER,
    GUI_ID_ZEROIA,
    GUI_ID_ONEIA,
    GUI_ID_TWOIA,
    GUI_ID_THREEIA,
    GUI_ID_FOURIA,
    GUI_ID_BACK
  };

  // This is the one method that we have to implement
  virtual bool OnEvent(const irr::SEvent& event);
  //  virtual bool IsKeyDown(irr::EKEY_CODE keyCode) const;

  MenuEventReceiver();
  MenuEventReceiver& operator=(const MenuEventReceiver&);

  //GETTERS
  irr::IrrlichtDevice*  getDevice() const;
  Menu*			getMenu() const;
  NewGame*		getNewGame() const;

  //SETTERS
  void			setDevice(irr::IrrlichtDevice*);
  void			setMenu(Menu*);
  void			setNewGame(NewGame*);
};


#endif
