//
// Warrior.cpp for Warrior in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d09/ex01
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Thu Jan 14 11:22:46 2016 Gwendoline Rodriguez
// Last update Fri Jan 15 07:58:47 2016 Gwendoline Rodriguez
//

#include "Warrior.hh"

Warrior::Warrior(const std::string& name, int lvl) : Character(name, lvl) , weaponName("hammer") {
  this->Strength = 12;
  this->Stamina = 12;
  this->Intelligence = 6;
  this->Spirit = 5;
  this->Agility = 7;

  std::cout << "I'm " << this->name
	    << " KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG" << std::endl;
}

Warrior::~Warrior() {};

int             Warrior::CloseAttack() {
  if (this->Energy >= 30) {
    this->Energy -= 30;
    std::cout << this->name << " strikes with his "<< this->weaponName << std::endl;
    return (20 + this->Strength);
  }
  else {
    std::cout << this->name << " out of power" << std::endl;
    return (0);
  }
}

int             Warrior::RangeAttack() {
  if (this->Energy >= 10) {
    this->Energy -= 10;
    std::cout << this->name << " intercepts" << std::endl;
    this->Range = Character::CLOSE;
    return (5 + this->Strength);
  }
  else {
    std::cout << this->name << " out of power" << std::endl;
    return (0);
  }
}

// int          main()
// {
//   Warrior  koala("john", 2);

//   koala.TakeDamage(70);
//   koala.RangeAttack();
//   koala.Heal();
//   koala.TakeDamage(70);
//   koala.TakeDamage(70);
//   koala.TakeDamage(70);

//   koala.Range = Character::CLOSE;
//   return (0);
// }
