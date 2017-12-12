//
// Lemon.cpp for Lemon in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d14m/ex00
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Tue Jan 19 10:48:01 2016 Gwendoline Rodriguez
// Last update Tue Jan 19 14:37:32 2016 Gwendoline Rodriguez
//

#include "Lemon.h"

Lemon::Lemon() : Fruit(3, "lemon") {}

Lemon::Lemon(Lemon const& f) : Fruit(f.getVitamins(), f.getName()) {
}

Lemon&  Lemon::operator=(Lemon const &f) {
  this->_name = f.getName();
  this->_vitamins = f.getVitamins();
  return *this;
}

Lemon::~Lemon() {}

std::string Lemon::getName() const {
  return this->_name;
}
int Lemon::getVitamins() const {
  return this->_vitamins;
}

