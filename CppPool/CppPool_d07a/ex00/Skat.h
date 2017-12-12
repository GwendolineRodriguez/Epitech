/*
** Skat.h for skat in /home/gwendoline/Epitech/Tek2/rendu/Piscine_cpp/piscine_cpp_d07a/ex00
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.net>
**
** Started on  Tue Jan 12 22:51:42 2016 Gwendoline Rodriguez
** Last update Tue Jan 12 22:54:47 2016 Gwendoline Rodriguez
*/

#include <string>

#ifndef SKAT_H_
# define SKAT_H_

class Skat {
 public:
  Skat(std::string const& name, int stimPaks);
  Skat();
  ~Skat();

 public:
  int& stimPaks();
  const std::string& name();

 public:
  void shareStimPaks(int number, int& stock);
  void addStimPaks(unsigned int number);
  void useStimPaks();

 public:
  void status();

 private:
  std::string	_name;
  int		_nbrStimPacks;
};

#endif
