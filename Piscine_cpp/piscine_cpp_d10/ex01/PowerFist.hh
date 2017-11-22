//
// PowerFist.hh for PowerFist in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d10/ex01
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Fri Jan 15 13:15:41 2016 Gwendoline Rodriguez
// Last update Fri Jan 15 13:18:16 2016 Gwendoline Rodriguez
//

#ifndef POWERFIST_HH
#define POWERFIST_HH

#include "AWeapon.hh"

class           PowerFist : public AWeapon {
public:
  explicit PowerFist();
  virtual ~PowerFist();

  virtual void attack() const;
};

#endif


