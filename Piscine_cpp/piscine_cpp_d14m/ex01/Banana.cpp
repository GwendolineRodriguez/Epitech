//
// Banana.cpp for Banana in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d14m/ex00
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Tue Jan 19 10:45:52 2016 Gwendoline Rodriguez
// Last update Tue Jan 19 12:41:57 2016 Gwendoline Rodriguez
//

#include "Banana.h"

Banana::Banana() : Fruit(5, "banana") {}

Banana::Banana(Banana const &f) : Fruit(f.getVitamins(), f.getName()) {
}

Banana&  Banana::operator=(Banana const &f) {
  this->_name = f.getName();
  this->_vitamins = f.getVitamins();
  return *this;
}

Banana::~Banana() {}

std::string Banana::getName() const {
  return this->_name;
}
int Banana::getVitamins() const {
  return this->_vitamins;
}

