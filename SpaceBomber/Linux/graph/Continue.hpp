#include "MenuEventReceiver.hpp"

#ifndef CONTINUE_HPP_
#define CONTINUE_HPP_

class Continue {
  MenuEventReceiver*			menuHey;
   irr::IrrlichtDevice*			device;
  irr::video::IVideoDriver*		menuDriver;
  irr::scene::ISceneManager*		menuSmgr;
  irr::gui::IGUIEnvironment*		menuGuienv;

public :
  Continue(irr::IrrlichtDevice* device, MenuEventReceiver* hey);
  ~Continue() {};
  MenuEventReceiver*			getMenuHey() const;
  irr::video::IVideoDriver*             getMenuDriver() const;
  irr::scene::ISceneManager*            getMenuSmgr() const;
  irr::IrrlichtDevice*			getDevice() const;
  irr::gui::IGUIEnvironment*            getMenuGuienv() const;
  void					setMenuHey(MenuEventReceiver *h);
  void					setMenuDriver(irr::video::IVideoDriver *iv);
  void					setMenuSmgr(irr::scene::ISceneManager *is);
  void					setMenuGuienv(irr::gui::IGUIEnvironment *ig);
  void					setDevice(irr::IrrlichtDevice *id);
};

#endif
