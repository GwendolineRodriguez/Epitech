//
// hunter.hh for hunter in /home/gwendoline
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Fri Jan 15 08:07:10 2016 Gwendoline Rodriguez
// Last update Fri Jan 15 08:07:13 2016 Gwendoline Rodriguez
//

#ifndef __piscine_cpp_d09__Hunter__
#define __piscine_cpp_d09__Hunter__

#include <string>
#include "Warrior.hh"

class   Hunter : public Warrior {
public:
  Hunter(std::string const&, int);
  ~Hunter();

  int                 RangeAttack();
  void                RestorePower();
  using Warrior::CloseAttack;
  using Warrior::Heal;
};

#endif
