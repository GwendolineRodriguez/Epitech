//
// Splash.hpp for hey in /home/cailla_o/Work/C++/cpp_indie_studio/graph
// 
// Made by Oihan Caillaud
// Login   <cailla_o@epitech.net>
// 
// Started on  Mon May 30 10:11:42 2016 Oihan Caillaud
// Last update Thu Jun  2 00:14:21 2016 
// Last update Tue May 31 11:42:52 2016
//

#ifndef SPLASH_HPP_
#define SPLASH_HPP_

#define TEMP 20000

#include "irrlicht-1.8.3/include/irrlicht.h"
#include "irrlicht.hpp"
#include "MyEventReceiver.hpp"

class Mesh;
class MyEventReceiver;

class Splash {
private:
  MyEventReceiver*		hey;
  irr::IrrlichtDevice*		device;
  irr::video::IVideoDriver*			driver;
  irr::scene::ISceneManager*		smgr;
  irr::gui::IGUIEnvironment*		guienv;
  irr::video::ITexture *image;
  irrklang::ISoundEngine*			engine;
  irr::core::dimension2d<irr::u32> taille;
  irr::core::position2d<irr::s32> position0;
  irr::core::position2d<irr::s32> position1;
  irr::core::rect<irr::s32> rectangle;
public:
  Splash();
  ~Splash() {};
  void  setWallpaper(irr::io::path wallpaper, irr::video::IVideoDriver* driver);
  void	drawWallpaper(irr::video::IVideoDriver* driver);
  void	Draw(irr::video::IVideoDriver* driver);
  void	draw_j();
  void	draw_f();
  Mesh  *Planet(float, float);
  void	draw_a();
  void	draw_a2();
  void	draw_g();
  void	draw_o();

  MyEventReceiver *getHey() const;
  irr::IrrlichtDevice* getDevice()const;
  irr::video::IVideoDriver* getDriver()const;
  irr::scene::ISceneManager* getSmgr()const;
  irr::gui::IGUIEnvironment* getGuienv()const;
  irr::video::ITexture * getImage()const;
  irr::core::dimension2d<irr::u32> getTaille()const;
  irr::core::position2d<irr::s32> getPosition0()const;
  irr::core::position2d<irr::s32> getPosition1()const;
  irr::core::rect<irr::s32> getRectangle()const;
  irrklang::ISoundEngine* getEngine() const;
  void setHey(MyEventReceiver *const _hey);
  void setDevice(irr::IrrlichtDevice*);
  void setDriver(irr::video::IVideoDriver* const);
  void setSmgr(irr::scene::ISceneManager* const);
  void setGuienv(irr::gui::IGUIEnvironment* const);
  void setImage(irr::video::ITexture *const );
  void setTaille(irr::core::dimension2d<irr::u32> const &);
  void setPosition0(irr::core::position2d<irr::s32> const &);
  void setPosition1(irr::core::position2d<irr::s32> const &);
  void setRectangle(irr::core::rect<irr::s32> const &);
  void setEngine(irrklang::ISoundEngine* const);
};

void do_splash(Splash *thi);

#endif
