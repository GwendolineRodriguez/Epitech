//
// Sorcerer.cpp for Sorcerer in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d10/ex00
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Fri Jan 15 09:42:03 2016 Gwendoline Rodriguez
// Last update Fri Jan 15 10:57:30 2016 Gwendoline Rodriguez
//

#include "Sorcerer.hh"

Sorcerer::Sorcerer(const std::string& name, const std::string& title) : name(name), title(title) {
  std::cout << this->name << ", " << this->title << ", is born !" << std::endl;
}

Sorcerer::~Sorcerer() {
  std::cout << this->name << ", " << this->title
	    << ", is dead. Consequences will never be the same !" << std::endl;
}

const std::string &Sorcerer::getName() const {
  return this->name;
}

const std::string &Sorcerer::getTitle() const {
  return this->title;
}

std::ostream& operator<<(std::ostream& os, Sorcerer const& Sorcerer)
{
  os << "I am  " << Sorcerer.getName() << ", "
     << Sorcerer.getTitle() << ", and I like ponies !" << std::endl;
  return os;
}

void Sorcerer::polymorph(Victim const& Victim) const {
  Victim.getPolymorphed();
}

// int main()
// {
//   Sorcerer robert("Robert", "the Magnificent");
//   Victim jim("Jimmy");
//   Peon joe("Joe");

//   std::cout << robert << jim << joe;

//   robert.polymorph(jim);
//   robert.polymorph(joe);

//   return 0;
// }

