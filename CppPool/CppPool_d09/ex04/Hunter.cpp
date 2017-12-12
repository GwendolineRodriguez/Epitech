//
// hunter.cpp for hunter in /home/gwendoline
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Fri Jan 15 08:06:57 2016 Gwendoline Rodriguez
// Last update Fri Jan 15 08:12:53 2016 Gwendoline Rodriguez
//

#include <iostream>
#include "Hunter.hh"

Hunter::Hunter(std::string const& name, int level) : Character(name, level), Warrior(name, level){
  this->Stamina = 9;
  this->Strength = 9;
  this->Intelligence = 5;
  this->Spirit = 6;
  this->Agility = 24;
  this->weaponName = "sword";
  std::cout << name << " is born from a tree" << std::endl;
}

Hunter::~Hunter() {}

int                 Hunter::RangeAttack() {
  if (this->Energy >= 25) {
    this->Energy -= 25;
    std::cout << this->name << " uses his bow" << std::endl;
    return 20 + this->Agility;
  }
  else {
    std::cout << this->name << " out of power" << std::endl;
    return 0;
  }
}

void                Hunter::RestorePower() {
  this->Energy = 100;

  std::cout << this->name << " meditates" << std::endl;
}
