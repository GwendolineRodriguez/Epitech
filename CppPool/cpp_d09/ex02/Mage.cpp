//
// Mage.cpp for mage in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d09/ex02
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Thu Jan 14 16:34:58 2016 Gwendoline Rodriguez
// Last update Fri Jan 15 08:32:24 2016 Gwendoline Rodriguez
//

#include "Mage.hh"

Mage::Mage(const std::string& name, int lvl) : Character(name, lvl) {
  this->Strength = 6;
  this->Stamina = 6;
  this->Intelligence = 12;
  this->Spirit = 11;
  this->Agility = 7;

  std::cout << this->name << " teleported" << std::endl;
}

Mage::~Mage() {}

int		Mage::CloseAttack() {
  if (this->Energy >= 10) {
    this->Energy -= 10;
    std::cout << this->name << " blinks" << std::endl;
  }
  else
    std::cout << this->name << " out of power" << std::endl;
  this->Range = Character::RANGE;
  return (0);
}

int		Mage::RangeAttack() {
  if (this->Energy >= 25) {
    this->Energy -= 25;
    std::cout << this->name << " launches a fire ball" << std::endl;

    return (20 + this->Spirit);
  }
  else {
    std::cout << this->name << " out of power" << std::endl;
    return (0);
  }
}

void            Mage::RestorePower() {
  this->Energy = 50 + this->Intelligence;
  if (this->Energy > 100)
    this->Energy = 100;
  std::cout << this->name << " takes a mana potion" << std::endl;
}
