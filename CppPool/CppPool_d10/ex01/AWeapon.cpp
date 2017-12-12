//
// AWeapon.cpp for AWeapon in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d10/ex01
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Fri Jan 15 12:38:21 2016 Gwendoline Rodriguez
// Last update Fri Jan 15 12:44:58 2016 Gwendoline Rodriguez
//

#include "AWeapon.hh"

AWeapon::AWeapon(const std::string& name, int apcost, int damage) : name(name), AP(apcost), damage(damage) {
}

AWeapon::~AWeapon() {
}

const std::string &AWeapon::getName() const {
  return this->name;
}

int AWeapon::getAPCost() const {
  return this->AP;
}

int AWeapon::getDamage() const {
  return this->damage;
}

void	AWeapon::attack() const {
}
