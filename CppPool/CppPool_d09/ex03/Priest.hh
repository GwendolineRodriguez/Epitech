//
// Priest.hh for Priest in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d09/ex02
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Thu Jan 14 16:50:20 2016 Gwendoline Rodriguez
// Last update Thu Jan 14 18:54:34 2016 Gwendoline Rodriguez
//

#ifndef _PRIEST_HH
#define _PRIEST_HH

#include "Mage.hh"

class           Priest : public Mage
{
public:
  explicit Priest(const std::string&, int);
  ~Priest();

  int CloseAttack();
  void Heal();
};

#endif

