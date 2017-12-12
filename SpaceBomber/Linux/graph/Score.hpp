#include "MenuEventReceiver.hpp"

#ifndef SCORE_HPP_
#define SCORE_HPP_

class Score
{
  MenuEventReceiver*		menuHey;
   irr::IrrlichtDevice*		device;
  irr::video::IVideoDriver*			menuDriver;
  irr::scene::ISceneManager*		menuSmgr;
  irr::gui::IGUIEnvironment*		menuGuienv;
  irr::video::ITexture*                         button;


public :
  void	affScore(std::vector <std::wstring>* score);
  Score(irr::IrrlichtDevice* device, MenuEventReceiver* hey);
  ~Score() {};
  MenuEventReceiver*			getMenuHey() const;
  irr::video::IVideoDriver*             getMenuDriver() const;
  irr::scene::ISceneManager*             getMenuSmgr() const;
  irr::IrrlichtDevice*		getDevice() const;
  irr::gui::IGUIEnvironment*             getMenuGuienv() const;
  void			setMenuHey(MenuEventReceiver *h);
  void             setMenuDriver(irr::video::IVideoDriver *iv);
  void             setMenuSmgr(irr::scene::ISceneManager *is);
  void             setMenuGuienv(irr::gui::IGUIEnvironment *ig);
  void		setDevice(irr::IrrlichtDevice *id);
};

#endif
