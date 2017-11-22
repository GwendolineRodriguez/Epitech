//
// Buzz.cpp for Buzz in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d13/ex02
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Mon Jan 18 14:38:29 2016 Gwendoline Rodriguez
// Last update Mon Jan 18 16:39:07 2016 Gwendoline Rodriguez
//

#include "Buzz.h"

Buzz::Buzz(Buzz const& toy) : Toy(BUZZ, toy.name, "") {
  this->picture = toy.picture;
}

Buzz& Buzz::operator=(Buzz const& toy) {
  this->name = toy.name;
  this->type = toy.type;
  this->picture = toy.picture;
  return *this;
}

Buzz::~Buzz() {}

Buzz::Buzz(std::string const& name) : Toy(BUZZ, name, "./buzz.txt") {
}

Buzz::Buzz(std::string const& name, std::string const& file) : Toy(BUZZ, name, file) {
}

void          Buzz::speak(std::string const& statement) {
  std::cout << "BUZZ: " << this->name << " \"" << statement << "\""<< std::endl;
}

