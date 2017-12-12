//
// Federation.cpp for namespace       Starfleet in /home/gwendoline/Epitech/Tek2/rendu/Piscine_cpp/piscine_cpp_d07m/ex01
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Tue Jan 12 09:50:44 2016 Gwendoline Rodriguez
// Last update Tue Jan 12 22:48:01 2016 Gwendoline Rodriguez
//

#include <iostream>
#include <string>
#include <stdlib.h>
#include "Federation.hh"

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp) : _captain(NULL), _home(EARTH) {
  this->_length = length;
  this->_width = width;
  this->_name = name;
  this->_maxWarp = maxWarp;
  this->_core = NULL;
  std::cout << "The ship USS " << name << " has been finished. It is " << length << " m in length and " << width << " m in width." << std::endl << "It can go to Warp " << maxWarp << "!" << std::endl;
}

Federation::Starfleet::Ship::~Ship() {}

void Federation::Starfleet::Ship::setupCore(WarpSystem::Core *core) {
  this->_core = core;
  std::cout << "USS " << this->_name << ": The core is set." << std::endl;
}


void Federation::Starfleet::Ship::checkCore() {
  std::cout << "USS " << this->_name << ": The core is " << (this->_core->checkReactor()->isStable() == true ? "stable" : "unstable") << " at the time." << std::endl;
}

void Federation::Starfleet::Ship::promote(Federation::Starfleet::Captain *captain) {
  this->_captain = captain;
  std::cout << captain->_name << ": I'm glad to be the captain of the USS " << this->_name << "." << std::endl;
}

bool Federation::Starfleet::Ship::Ship::move(int warp, Destination d) {
  if (warp <= (int)this->_maxWarp && d != this->_location && this->_core->checkReactor()->isStable()) {
    this->_location = d;
    return (true);
  }
  return (false);
}

bool Federation::Starfleet::Ship::Ship::move(int warp) {
  if (warp <= (int)this->_maxWarp && this->_core->checkReactor()->isStable())
    {
      this->_location = this->_home;
      return (true);
    }
  return (false);
}

bool Federation::Starfleet::Ship::Ship::move(Destination d) {
  if (this->_location != d && this->_core->checkReactor()->isStable())
    {
      this->_location = d;
      return (true);
    }
  else    return (false);
}

bool Federation::Starfleet::Ship::Ship::move() {
  if (this->_core->checkReactor()->isStable())
    {
      this->_location = this->_home;
      return (true);
    }
  return (false);
}

Federation::Starfleet::Captain::Captain(std::string name) : _age(42) {
  this->_name = name;
}

Federation::Starfleet::Captain::~Captain() {}

void Federation::Starfleet::Captain::setAge(int age) {
  this->_age = age;
}

int Federation::Starfleet::Captain::getAge() {
  return (this->_age);
}

Federation::Starfleet::Ensign::Ensign(std::string name) {
  this->_name = name;
  std::cout << "Ensign " << name << ", awaiting orders." << std::endl;
}

Federation::Starfleet::Ensign::~Ensign() {
}

Federation::Ship::Ship(int length, int width, std::string name) : _home(VULCAN){
  this->_length = length;
  this->_width = width;
  this->_name = name;

  std::cout << "The independant ship " << name << " just finished its construction. It is " << length << " m in length and " << width << " m in width." << std::endl;
}

Federation::Ship::~Ship() {}

void Federation::Ship::setupCore(WarpSystem::Core *core) {
  this->_core = core;
  std::cout << this->_name << ": The core is set." << std::endl;
}

void Federation::Ship::checkCore() {
  std::cout << this->_name << ": The core is " << (this->_core->checkReactor()->isStable() == true ? "stable" : "unstable") << " at the time." << std::endl;
}

bool Federation::Ship::move(int warp, Destination d) {
  if (warp <= (int)this->_maxWarp && d != this->_location && this->_core->checkReactor()->isStable()) {
    this->_location = d;
    return (true);
  }
  return (false);
}

bool Federation::Ship::move(int warp) {
  if (warp <= (int)this->_maxWarp && this->_core->checkReactor()->isStable())
    {
      this->_location = this->_home;
      return (true);
    }
  return (false);
}

bool Federation::Ship::move(Destination d) {
  if (this->_location != d && this->_core->checkReactor()->isStable())
    {
      this->_location = d;
      return (true);
    }
  else    return (false);
}

bool Federation::Ship::move() {
  if (this->_core->checkReactor()->isStable())
    {
      this->_location = this->_home;
      return (true);
    }
  return (false);
}
