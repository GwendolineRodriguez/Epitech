//
// Character.hh for Character in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d10/ex01
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Fri Jan 15 13:50:41 2016 Gwendoline Rodriguez
// Last update Fri Jan 15 15:46:26 2016 Gwendoline Rodriguez
//

#ifndef _CHARACTER_H
#define _CHARACTER_H

#include <iostream>
#include <string>
#include "PlasmaRifle.hh"
#include "PowerFist.hh"
#include "SuperMutant.hh"
#include "RadScorpion.hh"

class           Character {
protected:

  const std::string name;
  int		AP;
  AWeapon	*weapon;

public:
  //c_tor / d_tor
  Character();
  Character(std::string const & name);
  virtual ~Character();


  //getters
  std::string const& getName() const;
  int		getAp() const;
  AWeapon	*getWeapon() const;

  //Actions
  void recoverAP();
  void equip(AWeapon*);
  void attack(AEnemy*);

};

std::ostream& operator<<(std::ostream &os, Character const& hero);

#endif

