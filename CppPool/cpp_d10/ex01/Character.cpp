//
// Character.cpp for Character in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d10/ex01
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Fri Jan 15 13:54:49 2016 Gwendoline Rodriguez
// Last update Fri Jan 15 15:56:53 2016 Gwendoline Rodriguez
//

#include "Character.hh"

Character::Character(std::string const & name) : name(name), AP(40) {
  std::cout << this->name << " Created" << std::endl;
}

Character::~Character() {}


const std::string &Character::getName() const {
  return this->name;
}

AWeapon		*Character::getWeapon() const {
  return (this->weapon ? this->weapon : NULL);
}

int		Character::getAp() const {
  return this->AP;
}

void             Character::recoverAP() {
  this->AP += 10;
  if (this->AP > 40)
    this->AP = 40;
}

void		Character::equip(AWeapon *weapon) {
  this->weapon = weapon;
}

void            Character::attack(AEnemy *enemy) {
  if (this->weapon && this->AP >= this->weapon->getAPCost()) {
    std::cout << this->name << " attacks "<< enemy->getType()
	      << " with a " << this->weapon->getName() << std::endl;
    this->weapon->attack();
    enemy->takeDamage(this->weapon->getDamage());
    this->AP -= this->weapon->getAPCost();
    if (enemy->getHP() <= 0) {
      delete enemy;
      enemy = NULL;
    }
  }
}

std::ostream& operator<<(std::ostream &os, Character const& hero) {
  if (hero.getWeapon())
    os << hero.getName() << " has " << hero.getAp()
       << " AP and wields a " << hero.getWeapon()->getName() << std::endl;
  else
    os << hero.getName() << " has " << hero.getAp() << " AP and is unarmed" << std::endl;
  return os;
}

// int main()
// {
//   Character* zaz = new Character("zaz");
//   std::cout << *zaz;

//   AEnemy* b = new RadScorpion();

//   AWeapon* pr = new PlasmaRifle();
//   AWeapon* pf = new PowerFist();

//   zaz->equip(pr);
//   std::cout << *zaz;
//   zaz->equip(pf);

//   zaz->attack(b);
//   std::cout << *zaz;
//   zaz->equip(pr);
//   std::cout << *zaz;
//   zaz->attack(b);
//   std::cout << *zaz;
//   zaz->attack(b);
//   std::cout << *zaz;

//   return 0;
// }
