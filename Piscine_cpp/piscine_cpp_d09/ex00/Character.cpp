//
// Character.cpp for Character in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d09/ex00
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Thu Jan 14 09:51:59 2016 Gwendoline Rodriguez
// Last update Thu Jan 14 11:52:35 2016 Gwendoline Rodriguez
//

#include "Character.hh"

Character::Character(const std::string& name, int lvl) : name(name), Range(CLOSE) {
  this->lvl = lvl;
  this->Pv = 100;
  this->Energy = 100;

  this->Strength = 5;
  this->Stamina = 5;
  this->Intelligence = 5;
  this->Spirit = 5;
  this->Agility = 5;
  std::cout << this->name << " Created" << std::endl;
}

Character::~Character() {}

const std::string &Character::getName() const {
  return this->name;
}

int		Character::getLvl() const {
  return this->lvl;
}

int             Character::getPv() const {
  return this->Pv;
}

int             Character::getPower() const {
  return this->Energy;
}

int		Character::CloseAttack() {
  if (this->Energy >= 10) {
    this->Energy -= 10;
    std::cout << this->name << " strikes with a wood stick" << std::endl;
    return (10 + this->Strength);
  }
  else {
    std::cout << this->name << " out of power" << std::endl;
    return 0;
    }
}

int             Character::RangeAttack() {
  if (this->Energy >= 10) {
    this->Energy -= 10;
    std::cout << this->name << " launches a stone" << std::endl;
    return 5 + this->Strength;
  }
  else {
    std::cout << this->name << " out of power" << std::endl;
    return 0;
  }
}

void		Character::Heal() {
  this->Pv += 50;
  if (this->Pv > 100)
    this->Pv = 100;
  std::cout << this->name << " takes a potion" << std::endl;
}

void		Character::RestorePower() {
  this->Energy = 100;
  std::cout << this->name << " eats" << std::endl;
}

void		Character::TakeDamage(int _damage) {
  this->Pv -= _damage;
  if (this->Pv <= 0) {
    this->Energy = 0;
    std::cout << this->name << " out of combat" << std::endl;
  }
  else
    std::cout << this->name << " takes " << _damage << " damage" << std::endl;
}

// int		main()
// {
//   Character	koala("john", 2);;

//   koala.TakeDamage(70);
//   koala.Heal();
//   koala.TakeDamage(70);
//   koala.TakeDamage(70);
//   koala.TakeDamage(70);

//   koala.Range = Character::CLOSE;
//   return (0);
// }
