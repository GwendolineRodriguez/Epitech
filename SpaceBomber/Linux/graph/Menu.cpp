#include "irrKlang-64bit-1.5.0/include/irrKlang.h"
#include "irrlicht.hpp"
#include "Menu.hpp"
#include "MenuEventReceiver.hpp"

Menu::Menu(irr::IrrlichtDevice* device) {
  this->nbHuman = 2;
  this->nbIA = 0;
  this->mode = DEFAULT;
  this->menuDevice = device;
  this->button  = device->getVideoDriver()->getTexture("./graph/irrlicht-1.8.3/media/button.png");
  this->menuHey = new MenuEventReceiver;
  this->drawMenu();
}

void		Menu::drawMenu() {
  this->menuDevice->getSceneManager()->clear();
  this->menuDevice->getGUIEnvironment()->clear();

  this->menuDevice->setEventReceiver(this->menuHey);
  this->menuHey->setDevice(this->menuDevice);
  this->menuHey->setMenu(this);
  this->menuDriver = this->menuDevice->getVideoDriver();
  this->setWallpaper("./graph/irrlicht-1.8.3/media/Menu.png");
  this->menuSmgr = menuDevice->getSceneManager();
  this->menuSmgr->addCameraSceneNode(0, irr::core::vector3df(0,70,0), irr::core::vector3df(0,5,0));
  this->menuGuienv = menuDevice->getGUIEnvironment();
  this->skin = this->menuGuienv->getSkin();
  this->font = this->menuGuienv
    ->getFont("./graph/irrlicht-1.8.3/media/fonthaettenschweiler.bmp");
  if (this->font)
    this->skin->setFont(this->font);
  this->putButtons();
}

void		Menu::putButtons()
{
  this->menuGuienv->addButton(irr::core::rect<irr::s32>(1550, 600, 1750, 600 + 50),
                              0, MenuEventReceiver::GUI_ID_NEWGAME, L"New Game", L"New Game")
    ->setImage(this->button);
  this->menuGuienv->addButton(irr::core::rect<irr::s32>(1550, 660, 1750, 660 + 50),
                              0, MenuEventReceiver::GUI_ID_CONTINUE, L"Continue", L"Continue")
    ->setImage(this->button);
  this->menuGuienv->addButton(irr::core::rect<irr::s32>(1550, 720, 1750, 720 + 50),
                              0, MenuEventReceiver::GUI_ID_CONTROLS, L"Controls", L"Controls")
    ->setImage(this->button);
  this->menuGuienv->addButton(irr::core::rect<irr::s32>(1550, 780, 1750, 780 + 50),
                              0, MenuEventReceiver::GUI_ID_CREDITS, L"Credits", L"Credits")
    ->setImage(this->button);
  this->menuGuienv->addButton(irr::core::rect<irr::s32>(1550, 840, 1750, 840 + 50),
                              0, MenuEventReceiver::GUI_ID_SCORES, L"Scores", L"Scores")
    ->setImage(this->button);
  this->menuGuienv->addButton(irr::core::rect<irr::s32>(1550, 900, 1750, 900 + 50),
                              0, MenuEventReceiver::GUI_ID_QUIT, L"QUIT", L"Quit")
    ->setImage(this->button);
}

void		Menu::exitGame() {
  this->menuDevice->drop();
}

void		Menu::exitMenu() {
  this->menuSmgr->clear();
  this->menuSmgr->addCameraSceneNode(0, irr::core::vector3df(0,70,0), irr::core::vector3df(0,5,0));
}

void		Menu::setMode(Menu::Mode mode) {
  this->mode = mode;
}

void		Menu::setScore(std::vector <std::wstring>* score) {
  this->score = score;
}

std::vector <std::wstring>*	Menu::getScore() const {
  return this->score;
}

int			Menu::getMode() {
  while (this->mode == DEFAULT) {
    if (!(this->menuDevice->run()))
      exit(0);
    this->menuDriver->beginScene(true, true, irr::video::SColor(0.8, 128, 128, 128));
    this->drawWallpaper();
    this->menuSmgr->drawAll();
    this->menuGuienv->drawAll();
    this->menuDriver->endScene();
  }
  if (this->mode == QUIT)
    this->exitGame();
  else
    this->exitMenu();
  return this->mode;
}

void            Menu::setWallpaper(irr::io::path wallpaper)  {
  this->image = this->menuDriver->getTexture(wallpaper);
  this->taille = this->image->getSize();
  this->position0.X = 0;
  this->position0.Y = 0;
  this->position1.X = this->taille.Width;
  this->position1.Y = this->taille.Height;
  this->rectangle.UpperLeftCorner = this->position0;
  this->rectangle.LowerRightCorner = this->position1;
}

void            Menu::drawWallpaper() {
  this->menuDriver->draw2DImage(this->image, this->position0, this->rectangle,
		      0, irr::video::SColor(255, 255,255,255), true);
}

MenuEventReceiver* Menu::getMenuHey() const
{
  return (this->menuHey);
}

irr::video::IVideoDriver* Menu::getMenuDriver() const
{
  return (this->menuDriver);
}

irr::scene::ISceneManager* Menu::getMenuSmgr() const
{
  return (this->menuSmgr);
}

irr::gui::IGUIEnvironment* Menu::getMenuGuienv() const
{
  return (this->menuGuienv);
}

irrklang::ISoundEngine* Menu::getMenuEngine() const
{
  return (this->menuEngine);
}

int				Menu::getNbPlayers()
{
  return (this->nbIA + this->nbHuman);
}

int const&		Menu::getNbHuman() const
{
  return (this->nbHuman);
}

int const&			Menu::getNbIA() const
{
  return (this->nbIA);
}

std::string			Menu::getNamePlayer1() const {
  return this->player1;
}

std::string			Menu::getNamePlayer2() const {
  return this->player2;
}

void Menu::setMenuHey(MenuEventReceiver *h)
{
  this->menuHey = h;
}

void Menu::setMenuDriver(irr::video::IVideoDriver *iv)
{
  this->menuDriver = iv;
}

void Menu::setMenuSmgr(irr::scene::ISceneManager *is)
{
  this->menuSmgr = is;
}

void Menu::setMenuGuienv(irr::gui::IGUIEnvironment *ig)
{
  this->menuGuienv = ig;
}

void Menu::setMenuEngine(irrklang::ISoundEngine *sme)
{
  this->menuEngine = sme;
}

void Menu::setNbHuman(int nbH)
{
  this->nbHuman = nbH;
}

void Menu::setNbIA(int IA)
{
  this->nbIA = IA;
}

void Menu::setNamePlayer1(std::string str) {
  this->player1 = str;
}

void Menu::setNamePlayer2(std::string str) {
  this->player2 = str;
}
