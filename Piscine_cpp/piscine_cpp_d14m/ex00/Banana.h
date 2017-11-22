/*
** Banana.h for Banana in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d14m/ex00
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.net>
**
** Started on  Tue Jan 19 11:01:49 2016 Gwendoline Rodriguez
** Last update Tue Jan 19 12:19:23 2016 Gwendoline Rodriguez
*/

#ifndef BANANA_H
#define BANANA_H

#include "Fruit.h"

class           Banana : public Fruit {
 public:
  Banana();
  Banana(Banana const&);
  Banana& operator=(Banana const&);
  virtual ~Banana();

  virtual std::string  getName() const;
  virtual int           getVitamins() const;
};

#endif

