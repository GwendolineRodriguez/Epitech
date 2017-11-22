//
// Fruit.cpp for Fruit in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d14m/ex00
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Tue Jan 19 10:24:56 2016 Gwendoline Rodriguez
// Last update Tue Jan 19 12:44:25 2016 Gwendoline Rodriguez
//

#include "Lemon.h"
#include "FruitBox.h"

Fruit::Fruit(int vitamins, std::string const& name) : _vitamins(vitamins), _name(name) {}

Fruit::Fruit(Fruit const& f) : _vitamins(f._vitamins), _name(f._name) {
}

Fruit&	Fruit::operator=(Fruit const &f) {
  this->_name = f._name;
  this->_vitamins = f._vitamins;
  return *this;
}

Fruit::~Fruit() {}

// int main(void)
// {
//   Lemon l;
//   Banana b;
//   std::cout << l.getVitamins() << std::endl;
//   std::cout << b.getVitamins() << std::endl;
//   std::cout << l.getName() << std::endl;
//   std::cout << b.getName() << std::endl;
//   Fruit& f = l;
//   std::cout << f.getVitamins() << std::endl;
//   std::cout << f.getName() << std::endl;
//   std::cout << "########## test list" << std::endl;
//   FruitBox      box(3);
//   Lemon         l2;
//   Banana        b2;
//   std::cout << "### insertion" << std::endl;
//   std::cout << (box.head() == NULL) << "  "  << box.nbFruits() << std::endl;
//   std::cout << std::boolalpha << box.putFruit(&l) << std::endl;
//   std::cout << box.putFruit(&l) << std::endl;
//   std::cout << (box.head() == NULL) << "  "  << box.nbFruits() << std::endl;
//   std::cout << box.putFruit(&b) << std::endl;
//   std::cout << box.putFruit(&b) << std::endl;
//   std::cout << (box.head() == NULL) << "  "  << box.nbFruits() << std::endl;
//   std::cout << box.putFruit(&l2) << std::endl;
//   std::cout << box.putFruit(&b2) << std::endl;
//   std::cout << (box.head() == NULL) << "  "  << box.nbFruits() << std::endl;
//   std::cout << "### extraction" << std::endl;
//   std::cout << (box.pickFruit() == &l) << std::endl;
//   std::cout << (box.head() == NULL) << "  "  << box.nbFruits() << std::endl;
//   std::cout << (box.pickFruit() == &b) << std::endl;
//   std::cout << (box.head() == NULL) << "  "  << box.nbFruits() << std::endl;
//   std::cout << (box.pickFruit() == &l2) << std::endl;
//   std::cout << (box.head() == NULL) << "  "  << box.nbFruits() << std::endl;
//   return 1337;
// }
