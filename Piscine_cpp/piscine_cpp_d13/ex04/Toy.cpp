//
// toy.cpp for toy in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d13
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Mon Jan 18 09:58:11 2016 Gwendoline Rodriguez
// Last update Mon Jan 18 23:41:42 2016 Gwendoline Rodriguez
//

#include "Woody.h"

std::ostream& operator <<(std::ostream& os, Toy const& toy)
{
  os << toy.getName() << std::endl << toy.getAscii() << std::endl;
  return os;
}

Toy& Toy::operator <<(std::string const &str)
{
  this->picture = str;
  return *this;
}

Toy::Toy() : type(Toy::BASIC_TOY), name("toy"), picture(Picture()) {
}

Toy::Toy(Toy const& toy) : type(toy.type), name(toy.name), picture(toy.picture) {
}

Toy::Toy(ToyType type, std::string const& name, std::string const& file) : type(type), name(name), picture(Picture(file)) {
}

Toy& Toy::operator=(Toy const& toy) {
  this->type = toy.type;
  this->name = toy.name;
  this->picture = toy.picture;
  return *this;
}

Toy::~Toy() {}

std::string const&	Toy::getName() const {
  return this->name;
}

Toy::ToyType		Toy::getType() const {
  return this->type;
}

std::string const&    Toy::getAscii() const {
  return this->picture.data;
}

void		Toy::setName(std::string const &name) {
  this->name = name;
}

bool            Toy::setAscii(std::string const &file) {
  return this->picture.getPictureFromFile(file);
}

void            Toy::speak(std::string const &statement) {
  std::cout << this->name << " \"" << statement << "\""<<std::endl;
}

int main()
{
  // Toy toto;
  // Toy ET(Toy::ALIEN, "green", "./../alien.txt");
  // Buzz light("buzz");
  // Woody woody("woody");

  // toto.setName("TOTO !");

  // if (toto.getType() == Toy::BASIC_TOY)
  //   std::cout << "basic toy: " << toto.getName() << std::endl
  //             << toto.getAscii() << std::endl;
  // if (ET.getType() == Toy::ALIEN)
  //   std::cout << "this alien is: " << ET.getName() << std::endl
  //             << ET.getAscii() << std::endl;

  // ET.speak("Téléphone maison");
  // woody.speak("Yiiiii haaaa !!");
  // light.speak("Vers l'infini et l'au delà !!");

  Toy a(Toy::BASIC_TOY, "REX", "./../tardis");

  std::cout << a;
  a << "\\o/";
  std::cout << a;
  return 1337;
}

