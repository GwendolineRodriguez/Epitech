//
// Mage.hh for mage in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d09/ex02
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Thu Jan 14 16:20:33 2016 Gwendoline Rodriguez
// Last update Thu Jan 14 17:10:07 2016 Gwendoline Rodriguez
//

#ifndef _MAGE_HH
#define _MAGE_HH

#include "Warrior.hh"

class		Mage : public Character
{

public:
  explicit Mage(const std::string&, int);
  ~Mage();

  void RestorePower();
  int RangeAttack();
  int CloseAttack();
};

#endif
