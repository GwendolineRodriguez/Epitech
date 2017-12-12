//
// Paladin.hh for Paladin in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d09/ex03
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Thu Jan 14 17:16:20 2016 Gwendoline Rodriguez
// Last update Thu Jan 14 19:03:56 2016 Gwendoline Rodriguez
//

#ifndef _PALADIN_HH
#define _PALADIN_HH

#include "Warrior.hh"
#include "Priest.hh"

class           Paladin : public Warrior, public Priest
{

public:
  explicit Paladin(const std::string&, int);
  ~Paladin();

  using               Warrior::CloseAttack;
  using               Warrior::RestorePower;
  using               Priest::Heal;
  using               Priest::RangeAttack;

  int                 Intercept();
};

#endif

