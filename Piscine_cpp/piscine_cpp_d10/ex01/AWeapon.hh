//
// AWeapon.hh for AWeapon in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d10/ex01
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Fri Jan 15 12:27:34 2016 Gwendoline Rodriguez
// Last update Fri Jan 15 17:11:55 2016 Gwendoline Rodriguez
//

#ifndef AWEAPON_HH
#define AWEAPON_HH

#include <iostream>

class		AWeapon {
protected:
  const std::string name;
  const int   AP;
  const int	damage;

public:
  AWeapon(std::string const & name, int apcost, int damage);
  virtual ~AWeapon();

  const std::string& getName() const;
  int getAPCost() const;
  int getDamage() const;
  virtual void attack() const = 0;
};

#endif
