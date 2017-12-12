#include "NewGame.hpp"

NewGame::NewGame(irr::IrrlichtDevice* device, MenuEventReceiver* hey)
{
  device->getSceneManager()->clear();
  device->getGUIEnvironment()->clear();
  this->setReceiver(hey);
  this->setDriver(device->getVideoDriver());
  this->setSmgr(device->getSceneManager());
  this->setGuienv(device->getGUIEnvironment());
  this->setDevice(device);
  irr::video::IImage *image = driver->createImageFromFile("./graph/irrlicht-1.8.3/media/button.png");
  irr::u16 membuf[32 * 150];
  irr::u16 bigmembuf[32 * 550];
  irr::video::IImage *image_s = driver->createImageFromData(irr::video::ECF_R5G6B5,
  							    irr::core::dimension2d<irr::u32>(150, 32),
							    (void*)membuf);
  irr::video::IImage *image_z = driver->createImageFromData(irr::video::ECF_R5G6B5,
							    irr::core::dimension2d<irr::u32>(550, 32),
							    (void*)bigmembuf);
  image->copyToScaling(image_s);
  irr::video::ITexture *small = driver->addTexture("test", image_s);
  image->copyToScaling(image_z);
  irr::video::ITexture *longb = driver->addTexture("test", image_z);




  // TITLE
  this->guienv->addStaticText(L"Choose 2 to 4 players maximum",
			      irr::core::rect<irr::s32>(1550, 640, 1800, 640 + 32), false);
  this->info = guienv->addStaticText(L"There two human players",
			      irr::core::rect<irr::s32>(1550, 660, 1800, 660 + 32), false);

  // nbHumans
  this->guienv->addButton(irr::core::rect<irr::s32>(1500, 700, 1600, 700 + 32), 0,
			  MenuEventReceiver::GUI_ID_ZEROPLAYER, L"No human player", L"0 player")
    ->setImage(small);
  this->guienv->addButton(irr::core::rect<irr::s32>(1500, 740, 1600, 740 + 32), 0,
			  MenuEventReceiver::GUI_ID_ONEPLAYER, L"1 player", L"1 player")
    ->setImage(small);
  this->guienv->addButton(irr::core::rect<irr::s32>(1500, 780, 1600, 780 + 32), 0,
			  MenuEventReceiver::GUI_ID_TWOPLAYER, L"2 players", L"2 players")
    ->setImage(small);
  this->player1 = guienv->addEditBox(L"Player 1",
				     irr::core::rect<irr::s32>(1485, 820, 1615, 820 + 32), 1, 0, -1);
  this->player2 = guienv->addEditBox(L"Player 2",
				     irr::core::rect<irr::s32>(1485, 860, 1615, 860 + 32), 1, 0, -1);

  // nbIA
  this->guienv->addButton(irr::core::rect<irr::s32>(1700, 700, 1800, 700 + 32), 0,
			  MenuEventReceiver::GUI_ID_ZEROIA, L"No robot", L"choose 0 IA")
    ->setImage(small);
  this->guienv->addButton(irr::core::rect<irr::s32>(1700, 740, 1800, 740 + 32), 0,
			  MenuEventReceiver::GUI_ID_ONEIA, L"1 robot", L"choose 1 IA")
    ->setImage(small);
  this->guienv->addButton(irr::core::rect<irr::s32>(1700, 780, 1800, 780 + 32), 0,
			  MenuEventReceiver::GUI_ID_TWOIA, L"2 robots", L"choose 2 IA")
    ->setImage(small);
  this->guienv->addButton(irr::core::rect<irr::s32>(1700, 820, 1800, 820 + 32), 0,
			  MenuEventReceiver::GUI_ID_THREEIA, L"3 robots", L"choose 3 IA")
    ->setImage(small);
  this->guienv->addButton(irr::core::rect<irr::s32>(1700, 860, 1800, 860 + 32), 0,
			  MenuEventReceiver::GUI_ID_FOURIA, L"4 robots", L"choose 4 IA")
    ->setImage(small);


  // Menu interact
  this->guienv->addButton(irr::core::rect<irr::s32>(1450, 900, 1850, 900 + 32), 0,
			  MenuEventReceiver::GUI_ID_BACK, L"Back", L"Back to ")
    ->setImage(longb);
  this->guienv->addButton(irr::core::rect<irr::s32>(1450, 940, 1850, 940 + 32), 0,
			  MenuEventReceiver::GUI_ID_STARTGAME, L"Start Game")
    ->setImage(longb);
}

std::string	NewGame::getNamePlayer1() {
  std::wstring ws(this->player1->getText());
  std::string str(ws.begin(), ws.end());
  return str;
}

std::string   NewGame::getNamePlayer2() {
  std::wstring ws(this->player2->getText());
  std::string str(ws.begin(), ws.end());
  return str;
}

void		NewGame::updateInfo() {
  wchar_t tmp[320];
  swprintf(tmp, 320, L"There is %i human players and %i robots.",
	   this->receiver->getMenu()->getNbHuman(), this->receiver->getMenu()->getNbIA());
  this->info->setText(tmp);
}

void NewGame::setDevice(irr::IrrlichtDevice *id)
{
  this->device = id;
}

irr::IrrlichtDevice* NewGame::getDevice() const
{
  return (this->device);
}

MenuEventReceiver* NewGame::getReceiver() const
{
  return (this->receiver);
}

irr::video::IVideoDriver* NewGame::getDriver() const
{
  return (this->driver);
}

irr::scene::ISceneManager* NewGame::getSmgr() const
{
  return (this->smgr);
}

irr::gui::IGUIEnvironment* NewGame::getGuienv() const
{
  return (this->guienv);
}

void NewGame::setReceiver(MenuEventReceiver *h)
{
  this->receiver = h;
}

void NewGame::setDriver(irr::video::IVideoDriver *iv)
{
  this->driver = iv;
}

void NewGame::setSmgr(irr::scene::ISceneManager *is)
{
  this->smgr = is;
}

void NewGame::setGuienv(irr::gui::IGUIEnvironment *ig)
{
  this->guienv = ig;
}
