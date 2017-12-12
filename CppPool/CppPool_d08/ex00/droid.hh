//
// droid.hh for droid in /home/gwendoline/Epitech/Tek2/rendu/Piscine_cpp/piscine_cpp_d08/ex00
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Wed Jan 13 10:00:38 2016 Gwendoline Rodriguez
// Last update Wed Jan 13 23:52:50 2016 Gwendoline Rodriguez
//

#ifndef _DROID_HH
#define _DROID_HH

#include <iostream>
#include <string>

class Droid {
  std::string	Id;
  size_t	Energy;
  size_t const	Attack;
  size_t const	Toughness;
  std::string	*Status;

public:
  Droid(Droid const &);
  Droid();
  Droid(std::string);
  Droid& operator=(Droid const &);
  ~Droid();

  std::string getId() const;
  void        setId(std::string);
  size_t      getEnergy() const;
  void        setEnergy(size_t);
  std::string *getStatus() const;
  void        setStatus(std::string *);
  size_t      getAttack() const;
  size_t      getToughness() const;

  bool operator==(Droid const &) const;
  bool operator!=(Droid const &) const;
  Droid& operator<<(size_t &);
};

std::ostream& operator <<(std::ostream&, Droid const &) ;

#endif

