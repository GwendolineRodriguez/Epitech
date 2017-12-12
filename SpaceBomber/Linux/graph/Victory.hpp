#ifndef VIC_HPP__
# define VIC_HPP__

#include "irrlicht.hpp"
#include "MenuEventReceiver.hpp"

class MenuEventReceiver;

class Vict
{
private:
  MyEventReceiver*				Hey;
  irr::IrrlichtDevice*				device;
  irr::video::IVideoDriver*                     Driver;
  irr::scene::ISceneManager*			Smgr;
  irr::gui::IGUIEnvironment*			Guienv;
  std::vector<irr::io::path>		shipTextures;
  irr::video::ITexture *image;
  irr::core::dimension2d<irr::u32> taille;
  irr::core::position2d<irr::s32> position0;
  irr::core::position2d<irr::s32> position1;
  irr::core::rect<irr::s32> rectangle;
  Mesh	*ship;

public:
  Vict(irr::IrrlichtDevice* device, MyEventReceiver* hey);
  ~Vict();

  //GETTERS
  MyEventReceiver*				getHey() const;
  irr::video::IVideoDriver*			getDriver() const;
  irr::scene::ISceneManager*			getSmgr() const;
  irr::IrrlichtDevice*				getDevice() const;
  irr::gui::IGUIEnvironment*			getGuienv() const;
  void		Draw();

  //SETTERS
  void		drawWallpaper(irr::video::IVideoDriver* driver);
  void		setWallpaper(irr::io::path wallpaper, irr::video::IVideoDriver* driver);
  void						setHey(MyEventReceiver *h);
  void						setDriver(irr::video::IVideoDriver *iv);
  void						setSmgr(irr::scene::ISceneManager *is);
  void						setGuienv(irr::gui::IGUIEnvironment *ig);
  void						setDevice(irr::IrrlichtDevice *id);
  void						dispWin(int);
};

#endif
