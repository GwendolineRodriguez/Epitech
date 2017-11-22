/*
** Woody.h for Woody in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d13/ex02
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.net>
**
** Started on  Mon Jan 18 16:00:37 2016 Gwendoline Rodriguez
** Last update Mon Jan 18 16:35:32 2016 Gwendoline Rodriguez
*/

#ifndef WOODY_H
#define WOODY_H

#include "Buzz.h"

class           Woody : public Toy {
 public:
  //c_tor/d_tor
  explicit Woody(std::string const &name);
  explicit Woody(std::string const &name, std::string const &file);
  explicit Woody(Woody const&);
  Woody& operator=(Woody const&);
  ~Woody();

  void          speak(std::string const &);

};

#endif

