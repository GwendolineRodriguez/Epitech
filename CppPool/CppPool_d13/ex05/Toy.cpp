//
// toy.cpp for toy in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d13
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Mon Jan 18 09:58:11 2016 Gwendoline Rodriguez
// Last update Tue Jan 19 00:31:04 2016 Gwendoline Rodriguez
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

Toy::Error&   Toy::getLastError() { return error; }

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
  bool res;

  res = this->picture.getPictureFromFile(file);
  if (res == false)
    this->error.type = Error::PICTURE;
  return res;
}

void            Toy::speak(std::string const &statement) {
  std::cout << this->name << " \"" << statement << "\""<<std::endl;
}

bool    Toy::speak_es(std::string const& sentence) {
  (void)sentence;
  this->error.type = Error::SPEAK;
  return false;
}

std::string Toy::Error::what() const{
  if (this->type == UNKNOWN)
    return "";
  else if (this->type == PICTURE)
    return "bad new illustration";
  else
    return "wrong mode";
}

std::string Toy::Error::where() const{
  if (this->type == UNKNOWN)
    return "";
  else if (this->type == PICTURE)
    return "setAscii";
  else
    return "speak_es";
}

Toy::Error::Error() : type(UNKNOWN){}

// int main()
// {
//   Woody w("wood");

//   if (w.setAscii("file_who_does_not_exist.txt") == false)
//     {
//       Toy::Error e = w.getLastError();
//       if (e.type == Toy::Error::PICTURE)
// 	{
// 	  std::cout << "Error in " << e.where()
// 		    << ": " << e.what() << std::endl;
// 	}
//     }

//   if (w.speak_es("Woody does not have spanish mode") == false)
//     {
//       Toy::Error e = w.getLastError();
//       if (e.type == Toy::Error::SPEAK)
// 	{
// 	  std::cout << "Error in " << e.where()
// 		    << ": " << e.what() << std::endl;
// 	}
//     }

//   if (w.speak_es("Woody does not have spanish mode") == false)
//     {
//       Toy::Error e = w.getLastError();
//       if (e.type == Toy::Error::SPEAK)
// 	{
// 	  std::cout << "Error in " << e.where()
// 		    << ": " << e.what() << std::endl;
// 	}
//     }
// }
