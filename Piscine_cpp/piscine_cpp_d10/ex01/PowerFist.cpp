//
// PowerFist.cpp for PowerFist in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d10/ex01
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Fri Jan 15 13:16:47 2016 Gwendoline Rodriguez
// Last update Fri Jan 15 23:21:17 2016 Gwendoline Rodriguez
//

#include "PowerFist.hh"

PowerFist::PowerFist() : AWeapon("Power Fist", 8, 50) {
}

PowerFist::~PowerFist() {
}

void    PowerFist::attack() const {
  std::cout << "* pschhh... SBAM! *" << std::endl;
}

