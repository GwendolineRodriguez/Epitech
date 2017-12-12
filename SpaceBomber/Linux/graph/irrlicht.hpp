#ifndef MAIN_H_
#define MAIN_H_

#include "../game/map.hh"
#include "../game/Bomb.hh"
#include "MyEventReceiver.hpp"
#include "irrlicht-1.8.3/include/irrlicht.h"
#include "irrKlang-64bit-1.5.0/include/irrKlang.h"
#include "Splash.hpp"
#include "Menu.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iterator>
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(lib, "irrKlang.lib")
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")

class Splash;
class MyEventReceiver;
class Menu;

class Mesh {

  irr::scene::ISceneManager*		smgr;
  irr::video::IVideoDriver*		driver;
  irr::scene::IMesh*			mesh;
  irr::scene::IMeshSceneNode*		node;
public:
  float				x;
  float                         y;
  float                         z;

public:
  irr::scene::IMeshSceneNode* getNode();
  Mesh(irr::io::path const&, irr::io::path const&, irr::scene::ISceneManager*,
       irr::video::IVideoDriver*, enum irr::video::E_MATERIAL_TYPE);
  ~Mesh() {};

  void  setTexture(irr::io::path const&);
  void	setScale(float, float, float);
  void	setPosition(float, float, float);
  void	setRotation(float, float, float);
};

class Init {
  MyEventReceiver*		hey;
  irr::IrrlichtDevice*		device;
  irr::video::IVideoDriver*			driver;
  irr::scene::ISceneManager*		smgr;
  irr::scene::ISceneManager*		smgr2;
  irr::gui::IGUIEnvironment*		guienv;
  irrklang::ISoundEngine*			engine;
  int				cpt;
  std::vector<irr::io::path>		shipTextures;
  std::array<std::array <Mesh*, 8>, 15> mapy;
  Mesh*			player[4];
  irr::video::ITexture *image;
  irr::core::dimension2d<irr::u32> taille;
  irr::core::position2d<irr::s32> position0;
  irr::core::position2d<irr::s32> position1;
  irr::core::rect<irr::s32> rectangle;
  std::vector<irr::EKEY_CODE> code_tab;
  std::vector<e_case> case_tab;
  int	nbp;
  e_command (Init::*func_key_code[11])();
  void (Init::*func_case[5])(std::array<std::array <t_case, 8> , 15 > *gameMap,
			     int x, int y, float a, float c);
public:
  MyEventReceiver*		getHey() const;
  irr::IrrlichtDevice*		getDevice() const;
  irr::video::IVideoDriver*			getDriver() const;
  irr::scene::ISceneManager*		getSmgr() const;
  irr::scene::ISceneManager*		getSmgr2() const;
  irr::gui::IGUIEnvironment*		getGuienv() const;
  irrklang::ISoundEngine*			getEngine() const;
  std::vector<irr::io::path>		const &getShipTextures() const;
  std::array<std::array <Mesh*, 8>, 15> const &getMapy() const;
  Mesh**			getPlayer();
  irr::video::ITexture* getImage() const;
  irr::core::dimension2d<irr::u32> const &getTaille() const;
  irr::core::position2d<irr::s32> const &getPosition0() const;
  irr::core::position2d<irr::s32> const &getPosition1() const;
  irr::core::rect<irr::s32> const &getRectangle() const;
  std::vector<irr::EKEY_CODE> const &getCodeTab() const;
  std::vector<e_case> const &getCaseTab() const;
  int	getNbp() const;

  void		setHey(MyEventReceiver *he);
  void		setNbp(int);
  void		setDevice(irr::IrrlichtDevice *id);
  void			setDriver(irr::video::IVideoDriver *vd);
  void		setSmgr(irr::scene::ISceneManager *sm1);
  void		setSmgr2(irr::scene::ISceneManager *sm2);
  void		setGuienv(irr::gui::IGUIEnvironment *ge);
  void			setEngine(irrklang::ISoundEngine *se);
  void 		setShipTextures(std::vector<irr::io::path> const st);
  void setMapy(std::array<std::array <Mesh*, 8>, 15> const mpy);
  void setPlayer(Mesh **player);
  void setImage(irr::video::ITexture *img);
  void setTaille(irr::core::dimension2d<irr::u32> const taille);
  void setPosition0(irr::core::position2d<irr::s32> const pos0);
  void setPosition1(irr::core::position2d<irr::s32> const pos1);
  void setRectangle(irr::core::rect<irr::s32> rekt);
  void  setCodeTab(std::vector<irr::EKEY_CODE> codeTab);
  void setCaseTab(std::vector<e_case> caseTab);

  ~Init() {};
  Init(irr::IrrlichtDevice*, MyEventReceiver*, irrklang::ISoundEngine*);
  Init();
  void	initMap(const std::array<std::array <t_case, 8> , 15 > *gameMap,
		std::map<int, int[2]> *pos, int);
  void	checkMap(std::array<std::array <t_case, 8> , 15 > *gameMap, std::vector <int> *);
  void	deleteBlock(int x, int y);
  void		Flam(std::vector <int> *lec, float c, float a, std::array<std::array <t_case, 8> , 15 > *gameMap);
  void  setWallpaper(irr::io::path wallpaper, irr::video::IVideoDriver* driver);
  void	drawWallpaper(irr::video::IVideoDriver* driver);
  void	movePlayer(std::map<int, int[2]> *pos, int);
  void  placePlayers(int, int, int);
  void	Empty(float x, float y, float z, int, int);
  void	Noth(float x, float y, float z, int, int);
  void	Block(float x, float y, float z, int, int);
  void	Draw(irr::video::IVideoDriver* driver);
  void	checkPlayer(std::map<int, int[2]> *pos, int);
  e_command	getKeyPlayer1(std::map<int, int[2]> *pos);
  e_command	getKeyPlayer2(std::map<int, int[2]> *pos);
  void	placeBlock(float x, float y, float z, int, int);
  void	powerUp(float x, float y, float z, int, int, e_PU);
  void	placeBomb(float x, float y, float z, int, int);
  void		checkDown(int i, int f, int x, int y, std::string path, float a, float c, int, std::array<std::array <t_case, 8> , 15 > *gameMap);
  void		checkUp(int i, int f, int x, int y, std::string path, float a, float c, int, std::array<std::array <t_case, 8> , 15 > *gameMap);
  void		checkLeft(int i, int f, int x, int y, std::string path, float a, float c, int, std::array<std::array <t_case, 8> , 15 > *gameMap);
  void		checkRight(int i, int f, int x, int y, std::string path, float a, float c, int, std::array<std::array <t_case, 8> , 15 > *gameMap);
  void  returnEkeyTab();
  void  initFuncKey();
  void	returnCaseTab();
  void	initFuncCase();

  e_command ZKey();
  e_command QKey();
  e_command SKey();
  e_command DKey();
  e_command OKey();
  e_command KKey();
  e_command LKey();
  e_command MKey();
  e_command EscapeKey();
  e_command ReturnKey();
  e_command SpaceKey();

  void	emptyCase(std::array<std::array <t_case, 8> , 15 > *gameMap, int x, int y, float a, float c);
  void	NothCase(std::array<std::array <t_case, 8> , 15 > *gameMap, int x, int y, float a, float c);
  void	bombCase(std::array<std::array <t_case, 8> , 15 > *gameMap, int x, int y, float a, float c);
  void	flamCase(std::array<std::array <t_case, 8> , 15 > *gameMap, int x, int y, float a, float c);
  void	PUCase(std::array<std::array <t_case, 8> , 15 > *gameMap, int x, int y, float a, float c);

};

#endif
