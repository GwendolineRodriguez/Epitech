//
// Borg.cpp for Borg in /home/gwendoline/Epitech/Tek2/rendu/Piscine_cpp/piscine_cpp_d07m/ex01
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Tue Jan 12 14:04:52 2016 Gwendoline Rodriguez
// Last update Tue Jan 12 16:55:53 2016 Gwendoline Rodriguez
//

#include "Borg.hh"
#include "Federation.hh"
#include <iostream>

Borg::Ship::Ship()
{
  this->_side = 300;
  this->_maxWarp = 9;
  std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally.\n"
	    << "Your biological characteristics and technologies will be assimilated.\n"
	    << "Resistance is futile." << std::endl;
}

Borg::Ship::~Ship() {
}

void    Borg::Ship::setupCore(WarpSystem::Core *core) {
  this->_core = core;
}

void    Borg::Ship::checkCore() {
  std::cout << (this->_core->checkReactor()->isStable() == true ?
		"Everything is in order." : "Critical failure imminent.") << std::endl;
}

// int main(void)
// {
//   Federation::Starfleet::Ship UssKreog(289, 132, "Kreog", 6);
//   Federation::Starfleet::Captain James("James T. Kirk");
//   Federation::Starfleet::Ensign Ensign("Pavel Chekov");
//   WarpSystem::QuantumReactor QR;
//   WarpSystem::QuantumReactor QR2;
//   WarpSystem::Core core(&QR);
//   WarpSystem::Core core2(&QR2);

//   UssKreog.setupCore(&core);
//   UssKreog.checkCore();
//   UssKreog.promote(&James);

//   Borg::Ship Cube;
//   Cube.setupCore(&core2);
//   Cube.checkCore();

//   return 0;
// }

