//
// Splash.cpp for hey in /home/cailla_o/Work/C++/cpp_indie_studio/graph
// 
// Made by Oihan Caillaud
// Login   <cailla_o@epitech.net>
// 
// Started on  Mon May 30 10:08:54 2016 Oihan Caillaud
// Last update Sun Jun  5 16:04:19 2016 Oihan Caillaud

#include "irrlicht.hpp"

Splash::Splash() {
  this->hey = new MyEventReceiver();
  this->device = createDevice(irr::video::EDT_BURNINGSVIDEO,
				  irr::core::dimension2d<irr::u32>(1920, 1080),
				  32, false, false, false, this->hey);
  if (this->device == NULL)
    {
      std::cout << "Env not found" << std::endl;
      exit(0);
    }
  this->engine = irrklang::createIrrKlangDevice();
  this->driver = this->device->getVideoDriver();
  this->smgr = this->device->getSceneManager();
  this->smgr->addCameraSceneNode(0, irr::core::vector3df(0,70,0), irr::core::vector3df(0,5,0));
  this->guienv = this->device->getGUIEnvironment();
}

void		Splash::setWallpaper(irr::io::path wallpaper, irr::video::IVideoDriver* driver) {
  this->image = driver->getTexture(wallpaper);
  this->taille = this->image->getSize();
  this->position0.X = 0;
  this->position0.Y = 0;
  this->position1.X = this->taille.Width;
  this->position1.Y = this->taille.Height;
  this->rectangle.UpperLeftCorner = this->position0;
  this->rectangle.LowerRightCorner = this->position1;
}

void		Splash::draw_j()
{
  int	i;
  Mesh *hey[7];
  float x;
  float z;

  i = 0;
  x = 30;
  z = 247.5 - 17.5;
  while (i != 3)
    {
      hey[i] = this->Planet(x, z);
      z = z - 17.5;
      i = i + 1;
    }
  x = 30 - 17.5;
  z = 247.5 - 35;
  while (i != 5)
    {
      hey[i] = this->Planet(x, z);
      x = x - 17.5;
      i = i + 1;
    }
  z = 247.5;
  while (i != 7)
    {
      hey[i] = this->Planet(x, z);
      z = z - 17.5;
      i = i + 1;
    }
}

void		Splash::draw_a()
{
  int	i;
  Mesh *hey[10];
  float x;
  float z;

  i = 1;
  x = 30;
  z = 247.5 - (17.5 * 6);
  hey[0] = this->Planet(x, z);
  x = 30 - 17.5;
  z = z + 10.5;
  while (i != 3)
    {
      hey[i] = this->Planet(x, z);
      z = z - 21;
      i = i + 1;
    }
  x = x - 17.5;
  z = z + (10.5 * 5);
  while (i != 8)
    {
      hey[i] = this->Planet(x, z);
      z = z - 10.5;
      i = i + 1;
    }
  x = x - 17.5;
  z = z + (10.5 * 6);
  while (i != 10)
    {
      hey[i] = this->Planet(x, z);
      z = z - (10.5 * 6);
      i = i + 1;
    }
  z = z + (10.5 * 6);
}

void		Splash::draw_a2()
{
  int	i;
  Mesh *hey[10];
  float x;
  float z;

  i = 1;
  x = 30;
  z = 93.5 - (17.5 * 6);
  hey[0] = this->Planet(x, z);
  x = 30 - 17.5;
  z = z + 10.5;
  while (i != 3)
    {
      hey[i] = this->Planet(x, z);
      z = z - 21;
      i = i + 1;
    }
  x = x - 17.5;
  z = z + (10.5 * 5);
  while (i != 8)
    {
      hey[i] = this->Planet(x, z);
      z = z - 10.5;
      i = i + 1;
    }
  x = x - 17.5;
  z = z + (10.5 * 6);
  while (i != 10)
    {
      hey[i] = this->Planet(x, z);
      z = z - (10.5 * 6);
      i = i + 1;
    }
  z = z + (10.5 * 6);
}

void		Splash::draw_f()
{
  int	i;
  Mesh *hey[11];
  float x;
  float z;

  i = 0;
  x = 30;
  z = 111 - 35;
  while (i != 4)
    {
      hey[i] = this->Planet(x, z);
      i = i + 1;
      z = z - 17.5;
    }
  z = 111 - 35;
  x = 30 - 10.5;
  hey[i] = this->Planet(x, z);
  x = x - 10.5;
  i = i + 1;
  while (i != 8)
    {
      hey[i] = this->Planet(x, z);
      z = z - 17.5;
      i = i + 1;
    }
  x = x - 10.5;
  z = 111 - 35;
  hey[i] = this->Planet(x, z);
  while (i != 10)
    {
      x = x - 10.5;
      i = i + 1;
      hey[i] = this->Planet(x, z);
    }
}


void	Splash::draw_g()
{
  int	i;
  Mesh *hey[9];
  float x;
  float z;

  i = 0;
  x = 30;
  z = -43 - (17.5 * 3);
  while (i != 2)
    {
      hey[i] = this->Planet(x, z);
      i = i + 1;
      z = z - 17.5;
    }
  z = z + (17.5 * 3);
  x = 30 - 17.5;
  hey[i] = this->Planet(x, z);
  i = i + 1;
  x = x - 17.5;
  hey[i] = this->Planet(x, z);
  z = z - 35;
  i = i + 1;
  while (i != 6)
    {
      hey[i] = this->Planet(x, z);
      z = z - 17.5;
      i = i + 1;
    }
  z = z + (17.5 * 3);
  x = x - 17.5;
  while (i != 8)
    {
      hey[i] = this->Planet(x, z);
      z = z - 17.5;
      i = i + 1;
    }
}

void		Splash::draw_o()
{
  int	i;
  Mesh *hey[8];
  float x;
  float z;

  i = 0;
  x = 30;
  z = -130.5 - 35 - 17.5;
  while (i != 2)
    {
      hey[i] = this->Planet(x, z);
      i = i + 1;
      z = z - 17.5;
    }
  z = -130.5 - 35;
  x = 30 - 17.5;
  while (i != 4)
    {
      hey[i] = this->Planet(x, z);
      i = i + 1;
      x = x - 17.5;
    }
  z = z - 17.5;
  while (i != 6)
    {
      hey[i] = this->Planet(x, z);
      i = i + 1;
      z = z - 17.5;
    }
  x = x + 17.5;
  while (i != 8)
    {
      hey[i] = this->Planet(x, z);
      i = i + 1;
      x = x + 17.5;
    }
}

Mesh	*Splash::Planet(float x, float z)
{

  Mesh *test = new Mesh ("./graph/irrlicht-1.8.3/media/Wall.obj", "./graph/irrlicht-1.8.3/media/Wall.jpg", this->smgr, this->driver, irr::video::EMT_SOLID);
  test->setScale(5, 5, 5);
  test->setPosition(x, -150, z);
  this->Draw(this->driver);
  usleep(TEMP);
  return (test);
}

void		do_splash(Splash *thi)
{
  thi->setWallpaper("./graph/irrlicht-1.8.3/media/pure-black-wallpaper-159.jpg", thi->getDriver());
  thi->draw_j();
  thi->draw_a();
  thi->draw_f();
  thi->draw_a2();
  thi->draw_g();
  thi->draw_o();
  sleep(1);
  if (!(thi->getDevice()->run()))
      exit(0);
  thi->getSmgr()->clear();
  /*this->device->closeDevice();
  this->device->run();
  this->device->drop();*/
  return ;
}

void		Splash::Draw(irr::video::IVideoDriver* driver)
{
  this->driver->beginScene(true, true, irr::video::SColor(0.8, 128, 128, 128));
  this->drawWallpaper(driver);
  this->smgr->drawAll();
  this->driver->endScene();
}

void		Splash::drawWallpaper(irr::video::IVideoDriver* driver) {
  driver->draw2DImage(this->image, this->position0, this->rectangle,
			    0, irr::video::SColor(255, 255,255,255), true);
}

MyEventReceiver * Splash::getHey()const
{
  return(this->hey);
}

irr::IrrlichtDevice* Splash::getDevice() const
{
  return(this->device);
}
irr::video::IVideoDriver* Splash::getDriver()const
{
  return(this->driver);
}

irr::scene::ISceneManager* Splash::getSmgr()const
{
  return (this->smgr);
}

irr::gui::IGUIEnvironment* Splash::getGuienv()const
{
  return (this->guienv);
}

irr::video::ITexture * Splash::getImage()const
{
  return(this->image);
}

irr::core::dimension2d<irr::u32> Splash::getTaille()const
{
  return (this->taille);
}

irr::core::position2d<irr::s32> Splash::getPosition0()const
{
  return (this->position0);
}

irr::core::position2d<irr::s32> Splash::getPosition1()const
{
  return (this->position1);
}

irr::core::rect<irr::s32> Splash::getRectangle()const
{
  return (this->rectangle);
}

irrklang::ISoundEngine* Splash::getEngine() const
{
  return (this->engine);
}

void Splash::setHey(MyEventReceiver *const _hey)
{
  this->hey = _hey;
}

void Splash::setDevice(irr::IrrlichtDevice* const d)
{
  this->device = d;
}

void  Splash::setDriver(irr::video::IVideoDriver*const d)
{
  this->driver = d;
}

void Splash::setSmgr(irr::scene::ISceneManager*const s)
{
  this->smgr = s;
}

void Splash::setGuienv(irr::gui::IGUIEnvironment*const g)
{
  this->guienv = g;
}

void Splash::setImage(irr::video::ITexture *const i)
{
  this->image = i;
}

void Splash::setTaille(irr::core::dimension2d<irr::u32>const & t)
{
  this->taille = t;
}
void Splash::setPosition0(irr::core::position2d<irr::s32>const & p)
{
  this->position0 = p;
}
void Splash::setPosition1(irr::core::position2d<irr::s32>const & p)
{
  this->position1 = p;
}
void Splash::setRectangle(irr::core::rect<irr::s32>const & r)
{
  this->rectangle = r;
}

void Splash::setEngine(irrklang::ISoundEngine*const e)
{
  this->engine = e;
}

