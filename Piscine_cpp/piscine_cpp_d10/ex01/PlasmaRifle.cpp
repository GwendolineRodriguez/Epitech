//
// PlasmaRifle.cpp for PlasmaRifle in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d10/ex01
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Fri Jan 15 12:48:18 2016 Gwendoline Rodriguez
// Last update Fri Jan 15 15:49:30 2016 Gwendoline Rodriguez
//

#include "PlasmaRifle.hh"

PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Rifle", 5, 21) {
}

PlasmaRifle::~PlasmaRifle() {
}

void    PlasmaRifle::attack() const {
  std::cout << "* piouuu piouuu piouuu *" << std::endl;
}

