//
// PlasmaRifle.hh for PlasmaRifle in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d10/ex01
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Fri Jan 15 12:45:37 2016 Gwendoline Rodriguez
// Last update Fri Jan 15 13:15:02 2016 Gwendoline Rodriguez
//


#ifndef PLAMARIFLE_HH
#define PLAMARIFLE_HH

#include "AWeapon.hh"

class           PlasmaRifle : public AWeapon {
public:
  explicit PlasmaRifle();
  virtual ~PlasmaRifle();

  virtual void attack() const;
};

#endif

