//
// Warrior.hh for Warrior in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d09/ex01
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Thu Jan 14 11:22:32 2016 Gwendoline Rodriguez
// Last update Thu Jan 14 18:52:20 2016 Gwendoline Rodriguez
//

#ifndef _WARRIOR_HH
#define _WARRIOR_HH

#include "Character.hh"

class		Warrior : virtual public Character
{
protected:
  std::string		weaponName;

public:
  explicit Warrior(const std::string&, int);
  ~Warrior();

  int CloseAttack();
  int RangeAttack();
};

#endif
