//
// Lime.cpp for Lime in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d14m/ex01
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.eu>
//
// Started on  Tue Jan 19 13:07:50 2016 Gwendoline Rodriguez
// Last update Tue Jan 19 14:39:13 2016 Gwendoline Rodriguez
//

#include "Lime.h"

Lime::Lime() {
  this->_name = "lime";
  this->_vitamins = 2;
}

Lime::Lime(Lime const &f) : Lemon() {
  this->_name = f.getName();
  this->_vitamins = f.getVitamins();
}

Lime&  Lime::operator=(Lime const &f) {
  this->_name = f.getName();
  this->_vitamins = f.getVitamins();
  return *this;
}

Lime::~Lime() {}

std::string Lime::getName() const {
  return this->_name;
}
int Lime::getVitamins() const {
  return this->_vitamins;
}

