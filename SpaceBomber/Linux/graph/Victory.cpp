#include "Victory.hpp"

Vict::Vict(irr::IrrlichtDevice* device, MyEventReceiver* hey)
{
  device->getSceneManager()->clear();
  device->getGUIEnvironment()->clear();
  this->setDevice(device);
  this->setHey(hey);
  this->setDriver(device->getVideoDriver());
  this->setSmgr(device->getSceneManager());
  this->setGuienv(device->getGUIEnvironment());
  this->shipTextures = {"./graph/irrlicht-1.8.3/media/Player1.jpg",
			"./graph/irrlicht-1.8.3/media/Player2.jpg",
			"./graph/irrlicht-1.8.3/media/Player3.jpg",
			"./graph/irrlicht-1.8.3/media/Player4.jpg"};
  this->getSmgr()->addCameraSceneNode(0, irr::core::vector3df(0,0,130), irr::core::vector3df(0,-10,-100));
  this->setWallpaper("./graph/irrlicht-1.8.3/media/GameOver.png", this->getDriver());
  this->Guienv->addButton(irr::core::rect<irr::s32>(900, 580, 1100, 580 + 32), 0,
			      MenuEventReceiver::GUI_ID_BACK, L"Back", L"Back to menu");
}

Vict::~Vict() {}

void		Vict::setWallpaper(irr::io::path wallpaper, irr::video::IVideoDriver* driver) {
  this->image = driver->getTexture(wallpaper);
  this->taille = this->image->getSize();
  this->position0.X = 0;
  this->position0.Y = 0;
  this->position1.X = this->taille.Width;
  this->position1.Y = this->taille.Height;
  this->rectangle.UpperLeftCorner = this->position0;
  this->rectangle.LowerRightCorner = this->position1;
}

void		Vict::drawWallpaper(irr::video::IVideoDriver* driver) {
  driver->draw2DImage(this->image, this->position0, this->rectangle,
			    0, irr::video::SColor(255, 255,255,255), true);
}

void Vict::dispWin(int i)
{
  float a;

  a = 0;
  this->ship = new Mesh("./graph/irrlicht-1.8.3/media/idle.obj", this->shipTextures[i], this->getSmgr(), this->getDriver(), irr::video::EMT_SOLID);
  this->ship->setScale(20, 20, 20);
  this->ship->setPosition(0, -20, 40);
  while (a != 360)
    {
      this->ship->setRotation(0, a, 0);
      this->Draw();
      a = a + 2;
    }
}

void		Vict::Draw()
{
    this->getDriver()->beginScene(true, true, irr::video::SColor(0.8, 128, 128, 128));
    this->drawWallpaper(this->getDriver());
    this->getSmgr()->drawAll();
    this->getDriver()->endScene();
}

void Vict::setDevice(irr::IrrlichtDevice *id)
{
  this->device = id;
}

irr::IrrlichtDevice* Vict::getDevice() const
{
  return (this->device);
}

MyEventReceiver* Vict::getHey() const
{
  return (this->Hey);
}

irr::video::IVideoDriver* Vict::getDriver() const
{
  return (this->Driver);
}

irr::scene::ISceneManager* Vict::getSmgr() const
{
  return (this->Smgr);
}

irr::gui::IGUIEnvironment* Vict::getGuienv() const
{
  return (this->Guienv);
}

void Vict::setHey(MyEventReceiver *h)
{
  this->Hey = h;
}

void Vict::setDriver(irr::video::IVideoDriver *iv)
{
  this->Driver = iv;
}

void Vict::setSmgr(irr::scene::ISceneManager *is)
{
  this->Smgr = is;
}

void Vict::setGuienv(irr::gui::IGUIEnvironment *ig)
{
  this->Guienv = ig;
}
