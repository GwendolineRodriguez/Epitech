//
// AMateria.cpp for AMetaria in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d10/ex06
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Fri Jan 15 16:48:55 2016 Gwendoline Rodriguez
// Last update Fri Jan 15 17:04:41 2016 Gwendoline Rodriguez
//

#include "AMetaria.hh"

AMateria::AMateria() {
}

AMateria::AMateria(std::string const& type) : type(type), xp_(0) {
}

AMateria::AMateria(AMateria const &amateria) : Type(amateria.getType()), xp_(0) {
}

AMateria&  AMateria::operator=(AMateria const &amateria) {
  if (&ametaria != this)
    {
      this->xp = amateria.getXP();
      if (this->type)
        delete this->Type;
      this->type = new std::string(*amateria.getType());
    }
  return *this;
}

AMateria::~AMateria() {
  delete this->Status;
}

const std::string& AMateria::getType() const {
  return (this->type);
}

unsigned int	AMateria::getXP() const {
  return this->xp_;
}

AMateria*	AMateria::clone() const {

}
