//
// Peon.cpp for Peon in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d10/ex00
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Fri Jan 15 10:17:49 2016 Gwendoline Rodriguez
// Last update Fri Jan 15 10:44:40 2016 Gwendoline Rodriguez
//

#include "Peon.hh"

Peon::Peon(const std::string& name) : Victim(name), name(name) {
  std::cout << "Zog zog." << std::endl;
}

Peon::~Peon() {
  std::cout << "Bleuark..." << std::endl;
}

void    Peon::getPolymorphed() const {
  std::cout << this->name << " has been turned into a pink pony !" << std::endl;
}

