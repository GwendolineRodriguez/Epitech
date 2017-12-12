#include "Controls.hpp"

Controls::Controls(irr::IrrlichtDevice* device, MenuEventReceiver* hey)
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

Controls::~Controls() {}

void Controls::dispText() {
  this->Guienv->addStaticText(L"Player One : ZQSD\n\nPose Bomb : Space\n\nPlayer Two : OKLM\n\nPose Bomb : Enter\n\nQuit/Pause : Esc", irr::core::rect<irr::s32>(1550, 600, 1750, 600 + 200), false);
}

void Controls::setDevice(irr::IrrlichtDevice *id)
{
  this->device = id;
}

irr::IrrlichtDevice* Controls::getDevice() const
{
  return (this->device);
}

MenuEventReceiver* Controls::getHey() const
{
  return (this->Hey);
}

irr::video::IVideoDriver* Controls::getDriver() const
{
  return (this->Driver);
}

irr::scene::ISceneManager* Controls::getSmgr() const
{
  return (this->Smgr);
}

irr::gui::IGUIEnvironment* Controls::getGuienv() const
{
  return (this->Guienv);
}

void Controls::setHey(MenuEventReceiver *h)
{
  this->Hey = h;
}

void Controls::setDriver(irr::video::IVideoDriver *iv)
{
  this->Driver = iv;
}

void Controls::setSmgr(irr::scene::ISceneManager *is)
{
  this->Smgr = is;
}

void Controls::setGuienv(irr::gui::IGUIEnvironment *ig)
{
  this->Guienv = ig;
}
