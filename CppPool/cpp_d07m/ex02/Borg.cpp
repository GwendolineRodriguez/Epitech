//
// Borg.cpp for Borg in /home/gwendoline/Epitech/Tek2/rendu/Piscine_cpp/piscine_cpp_d07m/ex01
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Tue Jan 12 14:04:52 2016 Gwendoline Rodriguez
// Last update Tue Jan 12 22:46:55 2016 Gwendoline Rodriguez
//

#include <iostream>
#include "Borg.hh"

Borg::Ship::Ship() : _side(300), _maxWarp(9), _home(UNICOMPLEX) {
  std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl;
  std::cout << "Your biological characteristics and technologies will be assimilated." << std::endl;
  std::cout << "Resistance is futile." << std::endl;
}

Borg::Ship::~Ship() {}

void Borg::Ship::setupCore(WarpSystem::Core *core) {
  this->_core = core;
}

void Borg::Ship::checkCore() {
  std::cout << (this->_core->checkReactor()->isStable() == true ? "Everything is in order." : "Critical failure imminent.") << std::endl;
}

bool Borg::Ship::move(int warp, Destination d) {
  if (warp <= (int)this->_maxWarp && d != this->_location && this->_core->checkReactor()->isStable()) {
    this->_location = d;
    return (true);
  }
  return (false);
}

bool Borg::Ship::move(int warp) {
  if (warp <= (int)this->_maxWarp && this->_core->checkReactor()->isStable())
    {
      this->_location = this->_home;
      return (true);
    }
  return (false);
}

bool Borg::Ship::move(Destination d) {
  if (this->_location != d && this->_core->checkReactor()->isStable())
    {
      this->_location = d;
      return (true);
    }
  else    return (false);
}

bool Borg::Ship::move() {
  if (this->_core->checkReactor()->isStable())
    {
      this->_location = this->_home;
      return (true);
    }
  return (false);
}
