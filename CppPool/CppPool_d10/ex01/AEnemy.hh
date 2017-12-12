//
// AEnemy.hh for AEnemy in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d10/ex01
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.net>
//
// Started on  Fri Jan 15 13:19:08 2016 Gwendoline Rodriguez
// Last update Fri Jan 15 15:41:39 2016 Gwendoline Rodriguez
//

#ifndef AENEMY_HH
#define AENEMY_HH

#include <iostream>

class           AEnemy {
private:

  int		hp;
  const std::string type;

public:
  AEnemy(int hp, std::string const & type);
  virtual ~AEnemy();


  std::string const&  getType() const;
  int getHP() const;
  virtual void takeDamage(int);
};

#endif

