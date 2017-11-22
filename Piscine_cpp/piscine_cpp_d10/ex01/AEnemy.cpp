//
// AEnemy.cpp for AEnemy in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d10/ex01
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Fri Jan 15 13:23:12 2016 Gwendoline Rodriguez
// Last update Fri Jan 15 15:54:42 2016 Gwendoline Rodriguez
//

#include "AEnemy.hh"

AEnemy::AEnemy(int hp, std::string const & type) : hp(hp), type(type) {
}

AEnemy::~AEnemy() {}

const std::string &AEnemy::getType() const {
  return this->type;
}

int AEnemy::getHP() const {
  return this->hp;
}

void    AEnemy::takeDamage(int damage) {
  if (damage > 0)
    this->hp -= damage;
}

