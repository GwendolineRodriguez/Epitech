//
/*
** toy.h for toy in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d13
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.net>
**
** Started on  Mon Jan 18 09:57:22 2016 Gwendoline Rodriguez
** Last update Mon Jan 18 23:32:22 2016 Gwendoline Rodriguez
*/

#ifndef TOY_H
#define TOY_H

#include <iostream>
#include <fstream>
#include <string>
#include "Picture.h"

class		Buzz;
class		Woody;

class		Toy {
 public:
  enum		ToyType {
    BASIC_TOY,
    ALIEN,
    BUZZ,
    WOODY
  };

 protected:
  ToyType       type;
  std::string	name;
  Picture	picture;

 public:
  //c_tor/d_tor
  Toy();
  Toy(Toy const&);
  Toy(ToyType type, std::string const& name, std::string const& file);
  Toy& operator=(Toy const&);
  ~Toy();

  //Getters
  ToyType               getType() const;
  std::string const&	getName() const;
  std::string const&	getAscii() const;

  //Setters
  void		setName(std::string const&);
  bool		setAscii(std::string const&);

  //Action
  void		speak(std::string const &);
  Toy& operator<<(std::string const&);

};

std::ostream& operator<<(std::ostream&, Toy const &);

#endif
