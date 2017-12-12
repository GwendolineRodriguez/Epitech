#ifndef CREDITS_HPP__
# define CREDITS_HPP__

#include "MenuEventReceiver.hpp"

class MenuEventReceiver;

class Credits
{
private:
  MenuEventReceiver*				Hey;
  irr::IrrlichtDevice*				device;
  irr::video::IVideoDriver*                     Driver;
  irr::scene::ISceneManager*			Smgr;
  irr::gui::IGUIEnvironment*			Guienv;
  irr::video::ITexture*				button;

public:
  Credits(irr::IrrlichtDevice* device, MenuEventReceiver* hey);
  ~Credits();

  //GETTERS
  MenuEventReceiver*				getHey() const;
  irr::video::IVideoDriver*			getDriver() const;
  irr::scene::ISceneManager*			getSmgr() const;
  irr::IrrlichtDevice*				getDevice() const;
  irr::gui::IGUIEnvironment*			getGuienv() const;

  //SETTERS
  void						setHey(MenuEventReceiver *h);
  void						setDriver(irr::video::IVideoDriver *iv);
  void						setSmgr(irr::scene::ISceneManager *is);
  void						setGuienv(irr::gui::IGUIEnvironment *ig);
  void						setDevice(irr::IrrlichtDevice *id);
  void						dispText();
};

#endif
