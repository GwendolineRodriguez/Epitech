//
// RadScorpion.cpp for RadScorpion in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d10/ex01
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Fri Jan 15 13:47:47 2016 Gwendoline Rodriguez
// Last update Fri Jan 15 15:54:59 2016 Gwendoline Rodriguez
//

#include "RadScorpion.hh"

RadScorpion::RadScorpion() : AEnemy(80, "RadScorpion") {
  std::cout << "* click click click *" << std::endl;
}

RadScorpion::~RadScorpion() {
  std::cout << "* SPROTCH *" << std::endl;
}
