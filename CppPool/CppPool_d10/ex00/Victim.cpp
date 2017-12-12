//
// Victim.cpp for Victim in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d10/ex00
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Fri Jan 15 10:07:42 2016 Gwendoline Rodriguez
// Last update Fri Jan 15 17:13:59 2016 Gwendoline Rodriguez
//

#include "Victim.hh"

std::ostream& operator <<(std::ostream& os, Victim const& Victim)
{
  os << "I'm  " << Victim.getName() << " and i like otters !" << std::endl;
  return os;
}

Victim::Victim(const std::string& name) : name(name) {
  std::cout << "Some random victim called " << this->name << " just popped !" << std::endl;
}

Victim::~Victim() {
  std::cout << "Victim " << this->name
            << " just died for no apparent reason !" << std::endl;
}

const std::string &Victim::getName() const {
  return this->name;
}

void	Victim::getPolymorphed() const {
  std::cout << this->name << " has been turned into a cute little sheep !" << std::endl;
}
