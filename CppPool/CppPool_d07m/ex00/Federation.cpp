//
// Federation.cpp for namespace       Starfleet in /home/gwendoline/Epitech/Tek2/rendu/Piscine_cpp/piscine_cpp_d07m/ex01
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Tue Jan 12 09:50:44 2016 Gwendoline Rodriguez
// Last update Tue Jan 12 13:49:09 2016 Gwendoline Rodriguez
//

#include "Federation.hh"

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp)
{
  this->_length = length;
  this->_width = width;
  this->_name = name;
  this->_maxWarp = maxWarp;
  this->_core = NULL;

  std::cout << "The ship USS "<< name << " has been finished. It is "
	    << length << " m in length and " << width << "m in width.\nIt can go to Warp "
	    << maxWarp << std::endl;
}

Federation::Ship::Ship(int length, int width, std::string name)
{
  this->_length = length;
  this->_width = width;
  this->_name = name;

  std::cout << "The independant ship " << name << " just finished its construction. It is "
            << length << " m in length and " << width << "m in width." << std::endl;
}

Federation::Starfleet::Ship::~Ship() {
}

Federation::Ship::~Ship() {
}

void	Federation::Starfleet::Ship::setupCore(WarpSystem::Core *core) {
  this->_core = core;
  std::cout << "USS " << this->_name << ": The core is set." << std::endl;
}

void	Federation::Starfleet::Ship::checkCore() {
  std::cout << "USS " << this->_name << ": The core is "
	    << (this->_core->checkReactor()->isStable() == true ?
		"stable" : "unstable") << " at the time." << std::endl;
}

void	Federation::Ship::setupCore(WarpSystem::Core *core) {
  this->_core = core;
  std::cout << this->_name << ": The core is set." << std::endl;
}

void	Federation::Ship::checkCore() {
  std::cout << this->_name << ": The core is "
	    << (this->_core->checkReactor()->isStable() == true ?
		"stable" : "unstable") << " at the time." << std::endl;
}

// int main(void)
// {
//   Federation::Starfleet::Ship UssKreog(289, 132, "Kreog", 6);
//   Federation::Ship Independant(150, 230, "Greok");
//   WarpSystem::QuantumReactor QR;
//   WarpSystem::QuantumReactor QR2;
//   WarpSystem::Core core(&QR);
//   WarpSystem::Core core2(&QR2);

//   UssKreog.setupCore(&core);
//   UssKreog.checkCore();
//   Independant.setupCore(&core2);
//   Independant.checkCore();

//   QR.setStability(false);
//   QR2.setStability(false);
//   UssKreog.checkCore();
//   Independant.checkCore();
//   return 0;
// }
