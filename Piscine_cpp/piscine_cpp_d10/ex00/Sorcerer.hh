//
// Sorcerer.hh for Sorcerer in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d10/ex00
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Fri Jan 15 09:35:07 2016 Gwendoline Rodriguez
// Last update Fri Jan 15 10:49:11 2016 Gwendoline Rodriguez
//

#ifndef _SORCERER_H
#define _SORCERER_H

#include <iostream>
#include <string>
#include "Victim.hh"
#include "Peon.hh"

class           Sorcerer
{
protected:

  //Essentials
  const std::string     name;
  const std::string	title;

public:
  //c_tor / d_tor
  explicit Sorcerer(const std::string&, const std::string&);
  virtual ~Sorcerer();

  //getters
  const std::string &getName() const;
  const std::string &getTitle() const;

  //Actions
  virtual void polymorph(Victim const &) const;
};

std::ostream& operator<<(std::ostream&, Sorcerer const&);

#endif

