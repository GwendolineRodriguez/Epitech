//
// Priest.cpp for Priest in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d09/ex02
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Thu Jan 14 16:54:58 2016 Gwendoline Rodriguez
// Last update Fri Jan 15 08:39:02 2016 Gwendoline Rodriguez
//

#include "Priest.hh"

Priest::Priest(const std::string& name, int lvl) : Mage(name, lvl) {
  this->Strength = 4;
  this->Stamina = 4;
  this->Intelligence = 42;
  this->Spirit = 21;
  this->Agility = 2;

  std::cout << this->name << " enters in the order" << std::endl;
}

Priest::~Priest() {}

int             Priest::CloseAttack() {
  if (this->Energy >= 10) {
    this->Energy -= 10;
    std::cout << this->name << " uses a spirit explosion" << std::endl;
    return (10 + this->Spirit);
  }
  else
    std::cout << this->name << " out of power" << std::endl;

  return (0);
}

void            Priest::Heal() {
  if (this->Energy >= 10) {
    this->Energy -= 10;
    this->Pv += 70;
    std::cout << this->name << " casts a little heal spell" << std::endl;
  }
  if (this->Pv > 100)
    this->Pv = 100;
}


