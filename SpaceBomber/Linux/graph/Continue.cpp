#include "Continue.hpp"

Continue::Continue(irr::IrrlichtDevice* device, MenuEventReceiver* hey)
{
  device->getSceneManager()->clear();
  device->getGUIEnvironment()->clear();
  this->setMenuHey(hey);
  this->setMenuDriver(device->getVideoDriver());
  this->setMenuSmgr(device->getSceneManager());
  this->setMenuGuienv(device->getGUIEnvironment());
  this->setDevice(device);
  this->menuGuienv->addButton(irr::core::rect<irr::s32>(800, 580, 1100, 580 + 32), 0,
                          MenuEventReceiver::GUI_ID_BACK, L"Back", L"Back to menu");
}

void Continue::setDevice(irr::IrrlichtDevice *id)
{
  this->device = id;
}

irr::IrrlichtDevice* Continue::getDevice() const
{
  return (this->device);
}

MenuEventReceiver* Continue::getMenuHey() const
{
  return (this->menuHey);
}

irr::video::IVideoDriver* Continue::getMenuDriver() const
{
  return (this->menuDriver);
}

irr::scene::ISceneManager* Continue::getMenuSmgr() const
{
  return (this->menuSmgr);
}

irr::gui::IGUIEnvironment* Continue::getMenuGuienv() const
{
  return (this->menuGuienv);
}

void Continue::setMenuHey(MenuEventReceiver *h)
{
  this->menuHey = h;
}

void Continue::setMenuDriver(irr::video::IVideoDriver *iv)
{
  this->menuDriver = iv;
}

void Continue::setMenuSmgr(irr::scene::ISceneManager *is)
{
  this->menuSmgr = is;
}

void Continue::setMenuGuienv(irr::gui::IGUIEnvironment *ig)
{
  this->menuGuienv = ig;
}
