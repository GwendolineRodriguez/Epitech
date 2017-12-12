//
// Paladin.cpp for Paladin in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d09/ex03
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Thu Jan 14 17:49:41 2016 Gwendoline Rodriguez
// Last update Thu Jan 14 18:07:25 2016 Gwendoline Rodriguez
//

#include "Paladin.hh"

Paladin::Paladin(std::string const &name, int level) : Character(name, level), Warrior(name, level), Priest(name, level) {
  this->Strength = 9;
  this->Stamina = 10;
  this->Intelligence = 10;
  this->Spirit = 10;
  this->Agility = 2;

  std::cout << "the light falls on " << name << std::endl;
}

Paladin::~Paladin() {}

int Paladin::Intercept() {
  return Warrior::RangeAttack();
}

