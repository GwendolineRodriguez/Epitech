#include "Credits.hpp"

Credits::Credits(irr::IrrlichtDevice* device, MenuEventReceiver* hey)
{
  device->getSceneManager()->clear();
  device->getGUIEnvironment()->clear();
  this->setDevice(device);
  this->setHey(hey);
  this->setDriver(device->getVideoDriver());
  this->setSmgr(device->getSceneManager());
  this->setGuienv(device->getGUIEnvironment());
  this->button  = device->getVideoDriver()->getTexture("./graph/irrlicht-1.8.3/media/button.png");
  this->Guienv->addButton(irr::core::rect<irr::s32>(1550, 900, 1750, 900 + 50), 0,
			  MenuEventReceiver::GUI_ID_BACK, L"Back", L"Back to menu")
    ->setImage(this->button);
}

Credits::~Credits() {}

void Credits::dispText()
{
  this->Guienv->addStaticText(L"Angelo: Human players", irr::core::rect<irr::s32>(1550, 600, 1750, 600 + 32), false);
  this->Guienv->addStaticText(L"Oihan: graphical library in game", irr::core::rect<irr::s32>(1550, 640, 1750, 640 + 32), false);
  this->Guienv->addStaticText(L"Julie: Save/Load/Map/Windows", irr::core::rect<irr::s32>(1550, 680, 1750, 680 + 32), false);
  this->Guienv->addStaticText(L"Fred: IA", irr::core::rect<irr::s32>(1550, 720, 1750, 720 + 32), false);
  this->Guienv->addStaticText(L"Gwendoline: graphical library menu", irr::core::rect<irr::s32>(1550, 760, 1750, 760 + 32), false);
  this->Guienv->addStaticText(L"Antoine: Controller/3D Models/Lib", irr::core::rect<irr::s32>(1550, 800, 1750, 800 + 32), false);
}

void Credits::setDevice(irr::IrrlichtDevice *id)
{
  this->device = id;
}

irr::IrrlichtDevice* Credits::getDevice() const
{
  return (this->device);
}

MenuEventReceiver* Credits::getHey() const
{
  return (this->Hey);
}

irr::video::IVideoDriver* Credits::getDriver() const
{
  return (this->Driver);
}

irr::scene::ISceneManager* Credits::getSmgr() const
{
  return (this->Smgr);
}

irr::gui::IGUIEnvironment* Credits::getGuienv() const
{
  return (this->Guienv);
}

void Credits::setHey(MenuEventReceiver *h)
{
  this->Hey = h;
}

void Credits::setDriver(irr::video::IVideoDriver *iv)
{
  this->Driver = iv;
}

void Credits::setSmgr(irr::scene::ISceneManager *is)
{
  this->Smgr = is;
}

void Credits::setGuienv(irr::gui::IGUIEnvironment *ig)
{
  this->Guienv = ig;
}
