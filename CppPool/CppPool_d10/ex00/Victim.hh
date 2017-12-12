//
// Victim.hh for Victim in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d10/ex00
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Fri Jan 15 10:04:02 2016 Gwendoline Rodriguez
// Last update Fri Jan 15 10:50:02 2016 Gwendoline Rodriguez
//

#ifndef _VICTIM_H
#define _VICTIM_H

#include <iostream>
#include <string>
#include "Victim.hh"

class           Victim
{
protected:

  //Essentials
  const std::string     name;

public:
  //c_tor / d_tor
  explicit Victim(const std::string&);
  virtual ~Victim();

  //getters
  const std::string &getName() const;

  //Actions
  virtual void getPolymorphed() const;
};

std::ostream& operator<<(std::ostream&, Victim const&);

#endif

