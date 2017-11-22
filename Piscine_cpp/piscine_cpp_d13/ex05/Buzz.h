/*
** Buzz.h for Buzz in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d13/ex02
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.net>
**
** Started on  Mon Jan 18 14:14:34 2016 Gwendoline Rodriguez
** Last update Tue Jan 19 00:00:49 2016 Gwendoline Rodriguez
*/

#ifndef BUZZ_H
#define BUZZ_H

#include "Toy.h"

class		Buzz : public Toy {
 public:
  //c_tor/d_tor
  explicit Buzz(std::string const &name);
  explicit Buzz(std::string const &name, std::string const &file);
  explicit Buzz(Buzz const&);
  Buzz& operator=(Buzz const&);
  ~Buzz();

  void          speak(std::string const&);
  bool		speak_es(std::string const&);

};

#endif
