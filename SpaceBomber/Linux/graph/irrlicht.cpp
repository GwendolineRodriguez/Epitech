#include "irrlicht.hpp"

void	Init::initMap(const std::array<std::array <t_case, 8> , 15 > *gameMap,
		      std::map<int, int[2]> *pos, int n) {
  int	x;
  int	y;
  int	i;
  float	a;
  float	b;
  float c;

  this->guienv = this->device->getGUIEnvironment();
  void (Init::*aff[5])(float, float, float, int, int) =
    {&Init::placeBomb, &Init::placeBomb, &Init::placeBlock, &Init::Empty, &Init::Block};
  c = 247.5;
  a = 122.5;
  y = 0;
  while (y != 8)
    {
      x = 0;
      while (x != 15)
	{
	  if (static_cast<int>((*gameMap)[x][y].type) <= 4)
	    (this->*aff[(static_cast<int>((*gameMap)[x][y].type))])(a, -150, c, x, y);
	  else
	    this->Empty(a, -150, c, x, y);
	  x = x + 1;
	  c = c - 35;
	}
      a = a - 35;
      c = 247.5;
      y = y + 1;
    }
  i = 0;
  this->cpt = 0;
  while (i != n)
     {
       if ((*pos)[i][0] != -400)
	 this->placePlayers((*pos)[i][0], (*pos)[i][1], i);
       i = i + 1;
     }
  this->setNbp(n);
  this->engine->play2D("./graph/irrKlang-64bit-1.5.0/media/Fond.wav", true);
}

void	Init::setNbp(int n)
{
  this->nbp = n;
}

int	Init::getNbp() const
{
  return (this->nbp);
}

void	Init::checkPlayer(std::map<int, int[2]> *pos, int n)
{
  int	cpt;

  cpt = 0;
  while (cpt != this->getNbp())
    {
      if ((*pos)[cpt][0] == -400)
	{
	  if (this->player[cpt] != NULL)
	    {
	      this->player[cpt]->getNode()->remove();
	      delete (this->player[cpt]);
	      this->player[cpt] = NULL;
	    }
	}
      cpt = cpt + 1;
    }
}

void	Init::emptyCase(std::array<std::array <t_case, 8> , 15 > *gameMap,
			int x, int y, float a, float c) {
  if (this->mapy[x][y] == NULL)
    return;
  this->deleteBlock(x, y);
}

void	Init::NothCase(std::array<std::array <t_case, 8> , 15 > *gameMap,
			int x, int y, float a, float c) {
    return;
}

void	Init::bombCase(std::array<std::array <t_case, 8> , 15 > *gameMap,
		       int x, int y, float a, float c) {
  if (this->mapy[x][y] != NULL)
    return;
  this->placeBomb(a, -150, c, x, y);
}

void	Init::flamCase(std::array<std::array <t_case, 8> , 15 > *gameMap,
		       int x, int y, float a, float c) {
  return ;
}

void	Init::PUCase(std::array<std::array <t_case, 8> , 15 > *gameMap,
		     int x, int y, float a, float c) {
  this->powerUp(a, -150, c, x, y, (*gameMap)[x][y].PU_type);
}

void	Init::returnCaseTab()
{
  this->case_tab.push_back(e_case::EMPTY);
  this->case_tab.push_back(e_case::PLAYER);
  this->case_tab.push_back(e_case::BOMB);
  this->case_tab.push_back(e_case::FLAM);
  this->case_tab.push_back(e_case::PU);

}

void	Init::initFuncCase()
{
  this->func_case[0] = &Init::emptyCase;
  this->func_case[1] = &Init::emptyCase;
  this->func_case[2] = &Init::bombCase;
  this->func_case[3] = &Init::NothCase;
  this->func_case[4] = &Init::PUCase;
}

void	Init::checkMap(std::array<std::array <t_case, 8> , 15 > *gameMap, std::vector <int> *lec)
{
  int	x;
  int	y;
  int	i;
  float	a;
  float	b;
  float	c;

  c = 247.5;
  a = 122.5;
  y = 0;
  while (y != 8)
    {
      x = 0;
      while (x != 15)
	{
	  if (static_cast<int>((*gameMap)[x][y].type) <= 6)
	    {
	      int cp = 0;
	      while (cp < 5)
		{
		  if (x == (*lec)[0] && y == (*lec)[1] && (*gameMap)[x][y].type == e_case::FLAM)
		    this->Flam(lec, c, a, gameMap);
		  else if ((*gameMap)[x][y].type == this->case_tab[cp])
		    (this->*func_case[cp])(gameMap,x ,y, a, c);
		  cp++;
		}
	    }
	  x = x + 1;
	  c = c - 35;
	}
      a = a - 35;
      c = 247.5;
      y = y + 1;
    }
}

void	Init::deleteBlock(int x, int y)
{
  this->mapy[x][y]->getNode()->remove();
  delete (this->mapy[x][y]);
  this->mapy[x][y] = NULL;
}

Mesh::Mesh(irr::io::path const& mesh, irr::io::path const& texture,
	   irr::scene::ISceneManager* smgr, irr::video::IVideoDriver* driver, enum irr::video::E_MATERIAL_TYPE hey) : smgr(smgr), driver(driver) {
  this->mesh = this->smgr->getMesh(mesh);
  this->node = this->smgr->addMeshSceneNode(this->mesh);
  this->node->setMaterialTexture(0, this->driver->getTexture(texture));
  this->node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  this->node->setMaterialType(hey);
  this->node->getMaterial(0).getTextureMatrix(0).setTextureScale(2, 2);
  this->x = 0;
  this->y = 0;
  this->z = 0;
}

irr::scene::IMeshSceneNode* Mesh::getNode()
{
  return (this->node);
}

void            Mesh::setTexture(irr::io::path const& texture) {
  this->node->setMaterialTexture(0, this->driver->getTexture(texture));
}

void		Mesh::setPosition(float x, float y, float z) {
  this->node->setPosition(irr::core::vector3df(x, y, z));
}

void		Mesh::setScale(float x, float y, float z) {
  irr::core::vector3d<irr::f32> factorEscalate(x, y, z);
  this->node->setScale(factorEscalate);
}

void		Mesh::setRotation(float x, float y, float z) {
  this->node->setRotation(irr::core::vector3df(x, y, z));
}

Init::Init(irr::IrrlichtDevice* device, MyEventReceiver *hey, irrklang::ISoundEngine* engine){
  this->hey = hey;
  this->returnEkeyTab();
  this->initFuncKey();
  this->returnCaseTab();
  this->initFuncCase();
  this->device = device;
  if (this->device == NULL)
    {
      std::cout << "Env not found" << std::endl;
      exit(0);
    }
  this->device->setEventReceiver(this->hey);
  this->driver = device->getVideoDriver();
  device->getSceneManager()->clear();
  this->smgr = device->getSceneManager();
  this->engine = engine;
  this->smgr->addCameraSceneNode(0, irr::core::vector3df(0,70,0), irr::core::vector3df(0,5,0));
  this->guienv = device->getGUIEnvironment();
  this->cpt = 0;
  this->shipTextures = {"./graph/irrlicht-1.8.3/media/Player1.jpg",
			"./graph/irrlicht-1.8.3/media/Player2.jpg",
			"./graph/irrlicht-1.8.3/media/Player3.jpg",
			"./graph/irrlicht-1.8.3/media/Player4.jpg"};
}

Init::Init() {
}

void		Init::setWallpaper(irr::io::path wallpaper, irr::video::IVideoDriver* driver) {
  this->image = driver->getTexture(wallpaper);
  this->taille = this->image->getSize();
  this->position0.X = 0;
  this->position0.Y = 0;
  this->position1.X = this->taille.Width;
  this->position1.Y = this->taille.Height;
  this->rectangle.UpperLeftCorner = this->position0;
  this->rectangle.LowerRightCorner = this->position1;
}

void		Init::drawWallpaper(irr::video::IVideoDriver* driver) {
  driver->draw2DImage(this->image, this->position0, this->rectangle,
			    0, irr::video::SColor(255, 255,255,255), true);
}

e_command Init::ZKey()
{
  this->player[0]->setRotation(0, 270, 0);
  return (e_command::GO_UP);
}

e_command Init::QKey()
{
  this->player[0]->setRotation(0, 180, 0);
  return (e_command::GO_LEFT);
}

e_command Init::SKey()
{
  this->player[0]->setRotation(0, 90, 0);
  return (e_command::GO_DOWN);
}

e_command Init::DKey()
{
  this->player[0]->setRotation(0, 0, 0);
  return (e_command::GO_RIGHT);
}
e_command Init::EscapeKey()
{
  this->driver->beginScene(true, true, irr::video::SColor(0.8, 128, 128, 128));
  this->drawWallpaper(driver);
  this->smgr->drawAll();
  this->driver->endScene();
  this->getDevice()->getSceneManager()->clear();
  this->getDevice()->getGUIEnvironment()->clear();
  return (e_command::EXIT);
}
e_command Init::SpaceKey()
{
  return (e_command::PUT_BOMB);
}
e_command Init::OKey()
{
  this->player[1]->setRotation(0, 270, 0);
  return (e_command::GO_UP);
}
e_command Init::KKey()
{
  this->player[1]->setRotation(0, 180, 0);
  return (e_command::GO_LEFT);
}
e_command Init::LKey()
{
  this->player[1]->setRotation(0, 90, 0);
  return (e_command::GO_DOWN);
}
e_command Init::MKey()
{
  this->player[1]->setRotation(0, 0, 0);
  return (e_command::GO_RIGHT);
}
e_command Init::ReturnKey()
{
  return (e_command::PUT_BOMB);
}

void Init::returnEkeyTab()
{
  this->code_tab.push_back(irr::KEY_KEY_Z);
  this->code_tab.push_back(irr::KEY_KEY_Q);
  this->code_tab.push_back(irr::KEY_KEY_S);
  this->code_tab.push_back(irr::KEY_KEY_D);
  this->code_tab.push_back(irr::KEY_SPACE);
  this->code_tab.push_back(irr::KEY_ESCAPE);
  this->code_tab.push_back(irr::KEY_KEY_O);
  this->code_tab.push_back(irr::KEY_KEY_K);
  this->code_tab.push_back(irr::KEY_KEY_L);
  this->code_tab.push_back(irr::KEY_KEY_M);
  this->code_tab.push_back(irr::KEY_RETURN);
}

void Init::initFuncKey()
{
  this->func_key_code[0] = &Init::ZKey;
  this->func_key_code[1] = &Init::QKey;
  this->func_key_code[2] = &Init::SKey;
  this->func_key_code[3] = &Init::DKey;
  this->func_key_code[4] = &Init::SpaceKey;
  this->func_key_code[5] = &Init::EscapeKey;
  this->func_key_code[6] = &Init::OKey;
  this->func_key_code[7] = &Init::KKey;
  this->func_key_code[8] = &Init::LKey;
  this->func_key_code[9] = &Init::MKey;
  this->func_key_code[10] = &Init::ReturnKey;
}

e_command		Init::getKeyPlayer1(std::map<int, int[2]> *pos) {
  if ((*pos)[0][0] == -400)
    return (e_command::NONE);
  int cp = 0;

  while (cp < 6)
    {
      if (this->hey->IsKeyDown(this->code_tab[cp]))
	{
	  return((this->*func_key_code[cp])());
	}
      cp++;
    }
  return (e_command::NONE);
}

e_command		Init::getKeyPlayer2(std::map<int, int[2]> *pos)
{
  if ((*pos)[1][0] == -400)
    return (e_command::NONE);

  int cp = 5;
  while (cp < 12)
    {
      if (this->hey->IsKeyDown(this->code_tab[cp]))
	{
	  return((this->*func_key_code[cp])());
	}
      cp++;
    }
  return (e_command::NONE);
}

void		Init::placeBlock(float x, float y, float z, int a, int b) {
  this->mapy[a][b] = new Mesh ("./graph/irrlicht-1.8.3/media/Wall.obj", "./graph/irrlicht-1.8.3/media/Wall.jpg", this->smgr, this->driver, irr::video::EMT_SOLID);
  this->mapy[a][b]->setScale(15, 15, 15);
  this->mapy[a][b]->setPosition(x, y, z);
  this->mapy[a][b]->setRotation(rand() % 360, rand() % 360, rand() % 360);
}

void		Init::Block(float x, float y, float z, int a, int b) {
  this->mapy[a][b] = new Mesh ("./graph/irrlicht-1.8.3/media/Block.obj", "./graph/irrlicht-1.8.3/media/block.jpg", this->smgr, this->driver, irr::video::EMT_SOLID);
  this->mapy[a][b]->setScale(8, 8, 8);
  this->mapy[a][b]->setPosition(x, y, z);
  this->mapy[a][b]->setRotation(rand() % 360, rand() % 360, rand() % 360);
}

void		Init::placeBomb(float x, float y, float z, int a, int b) {
  this->mapy[a][b] = new Mesh ("./graph/irrlicht-1.8.3/media/Bomb.obj", "./graph/irrlicht-1.8.3/media/Bomb.jpg", this->smgr, this->driver, irr::video::EMT_SOLID);
  this->mapy[a][b]->setScale(5, 5, 5);
  this->mapy[a][b]->setPosition(x, y, z);
  this->engine->play2D("./graph/irrKlang-64bit-1.5.0/media/Exp2.wav");
}

void		Init::powerUp(float x, float y, float z, int a, int b, e_PU type) {
  if (this->mapy[a][b] != NULL)
    {
      this->deleteBlock(a, b);
    }
  if (type == e_PU::BOMB_1)
    this->mapy[a][b] = new Mesh ("./graph/irrlicht-1.8.3/media/CircularObj.obj", "./graph/irrlicht-1.8.3/media/PowerUp1.png", this->smgr, this->driver, irr::video::EMT_SOLID);
  else if (type == e_PU::POWER_1)
    this->mapy[a][b] = new Mesh ("./graph/irrlicht-1.8.3/media/CircularObj.obj", "./graph/irrlicht-1.8.3/media/PowerUp2.png", this->smgr, this->driver, irr::video::EMT_SOLID);
  else
    this->mapy[a][b] = new Mesh ("./graph/irrlicht-1.8.3/media/CircularObj.obj", "./graph/irrlicht-1.8.3/media/Speed.png", this->smgr, this->driver, irr::video::EMT_SOLID);
  this->mapy[a][b]->setScale(12, 12, 12);
  this->mapy[a][b]->setPosition(x, y, z);
  this->mapy[a][b]->setRotation(0, 180, 0);
}

void		Init::checkUp(int i, int f, int x, int y, std::string path, float a, float c, int frame, std::array<std::array <t_case, 8> , 15 > *gameMap)
{
  while (i != (f + 1) && (*gameMap)[x][y].type == e_case::FLAM)
    {
      if (this->mapy[x][y] != NULL)
	this->deleteBlock(x, y);
      this->mapy[x][y] = new Mesh ("./graph/irrlicht-1.8.3/media/CircularObj.obj", path.c_str(), this->smgr, this->driver, irr::video::EMT_SOLID);
      this->mapy[x][y]->setScale(16, 16, 16);
      this->mapy[x][y]->setPosition(a, -150, c);
  this->mapy[x][y]->setRotation(0, rand() % 360, 0);
      if (y != 0)
	{
	  a = a + 35;
	  y = y - 1;
	}
      i = i + 1;
    }
}

void		Init::checkDown(int i, int f, int x, int y, std::string path, float a, float c, int frame, std::array<std::array <t_case, 8> , 15 > *gameMap)
{
  while (i != (f + 1) && (*gameMap)[x][y].type == e_case::FLAM)
    {
      if (this->mapy[x][y] != NULL)
	this->deleteBlock(x, y);
      this->mapy[x][y] = new Mesh ("./graph/irrlicht-1.8.3/media/CircularObj.obj", path.c_str(), this->smgr, this->driver, irr::video::EMT_SOLID);
      this->mapy[x][y]->setScale(16, 16, 16);
      this->mapy[x][y]->setPosition(a, -150, c);
  this->mapy[x][y]->setRotation(0, rand() % 360, 0);
      if (y != 7)
	{
	  a = a - 35;
	  y = y + 1;
	}
      i = i + 1;
      if ((*gameMap)[x][y - 1].type == e_case::D_BLOC)
	return ;
    }
}

void		Init::checkRight(int i, int f, int x, int y, std::string path, float a, float c, int frame, std::array<std::array <t_case, 8> , 15 > *gameMap)
{
  while (i != (f + 1) && (*gameMap)[x][y].type == e_case::FLAM)
    {
      if (this->mapy[x][y] != NULL)
	this->deleteBlock(x, y);
      this->mapy[x][y] = new Mesh ("./graph/irrlicht-1.8.3/media/CircularObj.obj", path.c_str(), this->smgr, this->driver, irr::video::EMT_SOLID);
      this->mapy[x][y]->setScale(16, 16, 16);
      this->mapy[x][y]->setPosition(a, -150, c);
  this->mapy[x][y]->setRotation(0, rand() % 360, 0);
      if (x != 14)
	{
	  c = c - 35;
	  x = x + 1;
	}
      i = i + 1;
      if ((*gameMap)[x - 1][y].type == e_case::D_BLOC)
	return ;
    }
}

void		Init::checkLeft(int i, int f, int x, int y, std::string path, float a, float c, int frame, std::array<std::array <t_case, 8> , 15 > *gameMap)
{
  while (i != (f + 1) && (*gameMap)[x][y].type == e_case::FLAM)
    {
      if (this->mapy[x][y] != NULL)
	this->deleteBlock(x, y);
      this->mapy[x][y] = new Mesh ("./graph/irrlicht-1.8.3/media/CircularObj.obj", path.c_str(), this->smgr, this->driver, irr::video::EMT_SOLID);
      this->mapy[x][y]->setScale(16, 16, 16);
      this->mapy[x][y]->setPosition(a, -150, c);
  this->mapy[x][y]->setRotation(0, rand() % 360, 0);
      if (x != 0)
	{
	      c = c + 35;
	      x = x - 1;
	}
      i = i + 1;
      if ((*gameMap)[x + 1][y].type == e_case::D_BLOC)
	return ;
    }
}

void		Init::Flam(std::vector <int> *lec, float c, float a, std::array<std::array <t_case, 8> , 15 > *gameMap) {
  std::string path;
  int	i;
  int	x;
  int	y;
  int	f;
  int	frame;

  x = (*lec)[0];
  y = (*lec)[1];
  f = (*lec)[2];
  frame = (*lec)[3];
  i = 0;
  path = "./graph/irrlicht-1.8.3/media/";
  path = path + std::to_string(frame) + ".png";
  if (this->mapy[x][y] != NULL)
    this->deleteBlock(x, y);
  this->mapy[x][y] = new Mesh ("./graph/irrlicht-1.8.3/media/CircularObj.obj", path.c_str(), this->smgr, this->driver, irr::video::EMT_SOLID);
  this->mapy[x][y]->setScale(16, 16, 16);
  this->mapy[x][y]->setPosition(c, -150, a);
  this->mapy[x][y]->setRotation(0, rand() % 360, 0);
  this->checkUp(i, f, x, y, path, a, c, frame, gameMap);
  this->checkDown(i, f, x, y, path, a, c, frame, gameMap);
  this->checkLeft(i, f, x, y, path, a, c, frame, gameMap);
  this->checkRight(i, f, x, y, path, a, c, frame, gameMap);
}

void		Init::Draw(irr::video::IVideoDriver* driver)
{
  this->driver->beginScene(true, true, irr::video::SColor(0.8, 128, 128, 128));
  this->drawWallpaper(driver);
  this->smgr->drawAll();
  this->driver->endScene();
}

void		Init::Empty(float x, float y, float z, int a, int b)
{
  this->mapy[a][b] = NULL;
  return ;
}

void		Init::Noth(float x, float y, float z, int a, int b)
{
  return ;
}

void		Init::movePlayer(std::map<int, int[2]> *pos, int n)
{
  float a;
  float b;
  int	i;

  i = 0;
  while (i != this->getNbp())
    {
      if ((*pos)[i][0] != -400)
	{
	  a = static_cast<float>((*pos)[i][1]) + 0.5;
	  b = static_cast<float>((*pos)[i][0]) + 0.5;
    a = a * (-1);
	  b = b * (-1);
	  this->player[i]->setPosition(a, -150, b);
	}
      i = i + 1;
    }
}

void		Init::placePlayers(int x, int z, int i) {
  float a;
  float b;

  a = static_cast<float>(x) + 0.5;
  b = static_cast<float>(z) + 0.5;
  a = a * -1;
  b = b * -1;
 Mesh ship("./graph/irrlicht-1.8.3/media/idle.obj",
      this->shipTextures[i], this->smgr, this->driver, irr::video::EMT_SOLID);
  ship.setScale(20, 20, 20);
  ship.setPosition(b, -150, a);
  ship.setRotation(0, 0, 180);
  this->player[i] = new Mesh(ship);
  this->player[i]->x = b;
  this->player[i]->z = a;
  this->player[i]->y = -150;
}
MyEventReceiver* Init::getHey() const
{
  return (this->hey);
}

irr::IrrlichtDevice* Init::getDevice() const
{
  return (this->device);
}

irr::video::IVideoDriver* Init::getDriver() const
{
  return (this->driver);
}

irr::scene::ISceneManager* Init::getSmgr() const
{
  return (this->smgr);
}

irr::scene::ISceneManager* Init::getSmgr2() const
{
  return (this->smgr2);
}

irr::gui::IGUIEnvironment* Init::getGuienv() const
{
  return (this->guienv);
}

irrklang::ISoundEngine* Init::getEngine() const
{
  return (this->engine);
}

std::vector<irr::io::path> const &Init::getShipTextures() const
{
  return (this->shipTextures);
}

std::array<std::array <Mesh*, 8>, 15> const &Init::getMapy() const
{
  return (this->mapy);
}

Mesh** Init::getPlayer()
{
  return (this->player);
}

irr::video::ITexture *Init::getImage() const
{
  return (this->image);
}

irr::core::dimension2d<irr::u32> const &Init::getTaille() const
{
  return (this->taille);
}

irr::core::position2d<irr::s32> const &Init::getPosition0() const
{
  return (this->position0);
}

irr::core::position2d<irr::s32> const &Init::getPosition1() const
{
  return (this->position1);
}

irr::core::rect<irr::s32> const &Init::getRectangle() const
{
  return (this->rectangle);
}

std::vector<irr::EKEY_CODE> const &Init::getCodeTab() const
{
  return (this->code_tab);
}

std::vector<e_case> const &Init::getCaseTab() const
{
  return (this->case_tab);
}

void Init::setHey(MyEventReceiver *he)
{
  this->hey = he;
}

void Init::setDevice(irr::IrrlichtDevice *id)
{
  this->device = id;
}

void Init::setDriver(irr::video::IVideoDriver *vd)
{
  this->driver = vd;
}

void Init::setSmgr(irr::scene::ISceneManager *sm1)
{
  this->smgr = sm1;
}

void Init::setSmgr2(irr::scene::ISceneManager *sm2)
{
  this->smgr2 = sm2;
}

void Init::setGuienv(irr::gui::IGUIEnvironment *ge)
{
  this->guienv = ge;
}

void Init::setEngine(irrklang::ISoundEngine *se)
{
  this->engine = se;
}

void Init::setShipTextures(std::vector<irr::io::path> const st)
{
  this->shipTextures = st;
}

void Init::setMapy(std::array<std::array <Mesh*, 8>, 15> const mpy)
{
  this->mapy = mpy;
}

void Init::setPlayer(Mesh **player)
{
  this->player[0] = player[0];
  this->player[1] = player[1];
  this->player[2] = player[2];
  this->player[3] = player[3];
}

void Init::setImage(irr::video::ITexture *img)
{
  this->image = img;
}

void Init::setTaille(irr::core::dimension2d<irr::u32> const taille)
{
  this->taille = taille;
}

void Init::setPosition0(irr::core::position2d<irr::s32> const pos0)
{
  this->position0 = pos0;
}

void Init::setPosition1(irr::core::position2d<irr::s32> const pos1)
{
  this->position1 = pos1;
}

void Init::setRectangle(irr::core::rect<irr::s32> rekt)
{
  this->rectangle = rekt;
}

void  Init::setCodeTab(std::vector<irr::EKEY_CODE> codeTab)
{
  this->code_tab = codeTab;
}

void Init::setCaseTab(std::vector<e_case> caseTab)
{
  this->case_tab = caseTab;
}
