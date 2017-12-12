//
// Peon.hh for Peon in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d10/ex00
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Fri Jan 15 10:14:22 2016 Gwendoline Rodriguez
// Last update Fri Jan 15 10:50:11 2016 Gwendoline Rodriguez
//

#ifndef _PEON_H
#define _PEON_H

#include <iostream>
#include <string>
#include "Victim.hh"

class           Peon : public Victim {
protected:

  //Essentials
    const std::string     name;

public:
  //c_tor / d_tor
  explicit Peon(const std::string&);
  virtual ~Peon();

  //getters
  //  const std::string &getName() const;

  //Actions
  virtual void getPolymorphed() const;
};


#endif

