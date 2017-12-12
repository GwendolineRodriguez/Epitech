#include "Score.hpp"

Score::Score(irr::IrrlichtDevice* device, MenuEventReceiver* hey)
{
  device->getSceneManager()->clear();
  device->getGUIEnvironment()->clear();
  this->setMenuHey(hey);
  this->setMenuDriver(device->getVideoDriver());
  this->setMenuSmgr(device->getSceneManager());
  this->setMenuGuienv(device->getGUIEnvironment());
  this->setDevice(device);
  this->button  = device->getVideoDriver()->getTexture("./graph/irrlicht-1.8.3/media/button.png");
  this->menuGuienv->addButton(irr::core::rect<irr::s32>(1550, 900, 1750, 900 + 50), 0,
                          MenuEventReceiver::GUI_ID_BACK, L"Back", L"Back to menu")
    ->setImage(this->button);
}

void	Score::affScore(std::vector <std::wstring>* score)
{
  int	i;
  const wchar_t *name;

  i = 0;
  int pos = 600;
  while (i != 5)
    {
      name = (*score)[i].c_str();
      this->getMenuGuienv()->addStaticText(name,
					   irr::core::rect<irr::s32>(1550, pos, 1750, pos + 50), false);
      pos = pos + 60;
      i++;
    }
}

void Score::setDevice(irr::IrrlichtDevice *id)
{
  this->device = id;
}

irr::IrrlichtDevice* Score::getDevice() const
{
  return (this->device);
}

MenuEventReceiver* Score::getMenuHey() const
{
  return (this->menuHey);
}

irr::video::IVideoDriver* Score::getMenuDriver() const
{
  return (this->menuDriver);
}

irr::scene::ISceneManager* Score::getMenuSmgr() const
{
  return (this->menuSmgr);
}

irr::gui::IGUIEnvironment* Score::getMenuGuienv() const
{
  return (this->menuGuienv);
}

void Score::setMenuHey(MenuEventReceiver *h)
{
  this->menuHey = h;
}

void Score::setMenuDriver(irr::video::IVideoDriver *iv)
{
  this->menuDriver = iv;
}

void Score::setMenuSmgr(irr::scene::ISceneManager *is)
{
  this->menuSmgr = is;
}

void Score::setMenuGuienv(irr::gui::IGUIEnvironment *ig)
{
  this->menuGuienv = ig;
}
