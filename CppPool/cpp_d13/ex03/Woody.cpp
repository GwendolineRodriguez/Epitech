//
// Woody.cpp for Woody in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d13/ex02
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Mon Jan 18 16:02:06 2016 Gwendoline Rodriguez
// Last update Mon Jan 18 16:38:47 2016 Gwendoline Rodriguez
//

#include "Woody.h"

Woody::Woody(Woody const& toy) : Toy(WOODY, toy.name, "") {
  this->picture = toy.picture;
}

Woody& Woody::operator=(Woody const& toy) {
  this->name = toy.name;
  this->type = toy.type;
  this->picture = toy.picture;
  return *this;
}

Woody::~Woody() {}

Woody::Woody(std::string const& name) : Toy(WOODY, name, "./buzz.txt") {
}

Woody::Woody(std::string const& name, std::string const& file) : Toy(WOODY, name, file) {
}

void          Woody::speak(std::string const & statement) {
  std::cout << "WOODY: " << this->name << " \"" << statement << "\""<< std::endl;
}

