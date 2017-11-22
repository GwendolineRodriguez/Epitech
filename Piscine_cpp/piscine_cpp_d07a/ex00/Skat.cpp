//
// Skat.cpp for skat in /home/gwendoline/Epitech/Tek2/rendu/Piscine_cpp/piscine_cpp_d07a/ex00
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Tue Jan 12 22:51:08 2016 Gwendoline Rodriguez
// Last update Tue Jan 12 22:57:53 2016 Gwendoline Rodriguez
//

#include <iostream>
#include <string>
#include "Skat.h"

Skat::Skat() : _name("bob"), _nbrStimPacks(15) {}

Skat::Skat(std::string const& name, int stimPaks) {
  _name = name;
  _nbrStimPacks = stimPaks;
}

Skat::~Skat() {}

int& Skat::stimPaks() {
  return (_nbrStimPacks);
}

const std::string &Skat::name() {
  return (_name);
}

void Skat::shareStimPaks(int number, int& stock) {
  if (_nbrStimPacks < number)
    std::cout << "Don't be greedy" << std::endl;
  else    {
    stock += number;
    _nbrStimPacks -= number;
    std::cout << "Keep the change." << std::endl;
  }
}

void Skat::addStimPaks(unsigned int number) {
  if (number == 0)
    std::cout << "Hey boya, did you forget something ?" << std::endl;
  else    _nbrStimPacks += number;
}

void Skat::useStimPaks() {
  if (_nbrStimPacks > 0)
    {
      std::cout << "Time to kick some ass and chew bubble gum." << std::endl;
      --_nbrStimPacks;
    }
  else    std::cout << "Mediiiiiic" << std::endl;
}

void Skat::status() {
  std::cout << "Soldier " << _name << " reporting " << _nbrStimPacks << " stimpaks remaining sir !" << std::endl;
}

// int main()
// {
//   Skat s("Junior", 5);

//   std::cout << "Soldier " << s.name() << std::endl;

//   s.status();

//   s.useStimPaks();

//   return 0;
// }
