//
// SuperMutant.hh for SuperMutant in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d10/ex01
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Fri Jan 15 13:29:31 2016 Gwendoline Rodriguez
// Last update Fri Jan 15 15:42:13 2016 Gwendoline Rodriguez
//

#ifndef SUPERMUTANT_HH
#define SUPERMUTANT_HH

#include "AEnemy.hh"

class           SuperMutant : public AEnemy
{

public:
  SuperMutant();
  virtual ~SuperMutant();

  void takeDamage(int);
};

#endif

