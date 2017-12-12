#include "MenuEventReceiver.hpp"

MenuEventReceiver::MenuEventReceiver() {
}

MenuEventReceiver& MenuEventReceiver::operator=(const MenuEventReceiver&) {
  return *this;
}

void		MenuEventReceiver::setDevice(irr::IrrlichtDevice* device) {
  this->device = device;
}

void		MenuEventReceiver::setMenu(Menu* menu) {
  this->menu = menu;
}

void		MenuEventReceiver::setNewGame(NewGame* newGame) {
  this->newGame = newGame;
}

irr::IrrlichtDevice*	MenuEventReceiver::getDevice() const {
  return this->device;
}

Menu*		MenuEventReceiver::getMenu() const {
  return this->menu;
}

NewGame*	MenuEventReceiver::getNewGame() const {
  return this->newGame;
}

bool		MenuEventReceiver::OnEvent(const irr::SEvent& event) {
  if (event.EventType == irr::EET_GUI_EVENT)
    {
      irr::s32 id = event.GUIEvent.Caller->getID();
      irr::gui::IGUIEnvironment* env = this->device->getGUIEnvironment();

      switch(event.GUIEvent.EventType) {
      case irr::gui::EGET_BUTTON_CLICKED:
	switch(id) {
	case GUI_ID_NEWGAME:
	  {
	    this->newGame =  new NewGame(this->getDevice(), this);
	    break;
	  }
	case GUI_ID_CONTINUE:
	  {
	    this->getMenu()->setMode(Menu::CONTINUE);
	    this->getDevice()->getSceneManager()->clear();
	    break;
	  }
	case GUI_ID_CONTROLS:
	  {
	    Controls controls(this->getDevice(), this);
	    controls.dispText();
	    break;
	  }
	case GUI_ID_CREDITS:
	  {
	    Credits cred(this->getDevice(), this);
	    cred.dispText();
	    break;
	  }
	case GUI_ID_SCORES:
	  {
	    Score score(this->getDevice(), this);
	    score.affScore(this->menu->getScore());
	    break;
	  }
	case GUI_ID_QUIT:
	  {
	    this->getMenu()->setMode(Menu::QUIT);
	    break;
	  }
	case GUI_ID_STARTGAME :
	  {
	    if (this->getMenu()->getNbPlayers() <= 4 && this->getMenu()->getNbPlayers() >= 2) {
	      this->getMenu()->setNamePlayer1(this->getNewGame()->getNamePlayer1());
	      this->getMenu()->setNamePlayer2(this->getNewGame()->getNamePlayer2());
	      this->getMenu()->setMode(Menu::NEWGAME);
	      this->getDevice()->getSceneManager()->clear();
	    }
	    break;
	  }
	case GUI_ID_BACK:
	  {
	    this->getDevice()->getSceneManager()->clear();
	    this->getDevice()->getGUIEnvironment()->clear();
	    this->getMenu()->putButtons();
	    break;
	  }

	  // choose players
	case GUI_ID_ZEROPLAYER:
	  {
	    this->getMenu()->setNbHuman(0);
	    this->newGame->updateInfo();
	    break;
	  }
	case GUI_ID_ONEPLAYER:
	  {
	    this->getMenu()->setNbHuman(1);
	    this->newGame->updateInfo();
	    break;
	  }
    	case GUI_ID_TWOPLAYER:
	  {
	    this->getMenu()->setNbHuman(2);
	    this->newGame->updateInfo();
	    break;
	  }

	case GUI_ID_ZEROIA:
	  {
	    this->getMenu()->setNbIA(0);
	    this->newGame->updateInfo();
	    break;
	  }
    	case GUI_ID_ONEIA:
	  {
	    this->getMenu()->setNbIA(1);
	    this->newGame->updateInfo();
	    break;
	  }
    	case GUI_ID_TWOIA:
	  {
	    this->getMenu()->setNbIA(2);
	    this->newGame->updateInfo();
	    break;
	  }
    	case GUI_ID_THREEIA:
	  {
	    this->getMenu()->setNbIA(3);
	    this->newGame->updateInfo();
	    break;
	  }
    	case GUI_ID_FOURIA:
	  {
	    this->getMenu()->setNbIA(4);
	    this->newGame->updateInfo();
	    break;
	  }
	}
      }
    }
  return false;
}
