//
// SuperMutant.cpp for SuperMutant in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d10/ex01
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Fri Jan 15 13:40:26 2016 Gwendoline Rodriguez
// Last update Fri Jan 15 15:42:04 2016 Gwendoline Rodriguez
//

#include "SuperMutant.hh"

SuperMutant::SuperMutant() : AEnemy(170, "Super Mutant") {
  std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

SuperMutant::~SuperMutant() {
  std::cout << "Aaargh ..." << std::endl;
}

void    SuperMutant::takeDamage(int damage) {
  AEnemy::takeDamage(damage - 3);
}

