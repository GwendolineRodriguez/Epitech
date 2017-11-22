/*
** Lemon.h for Lemon in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d14m/ex00
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.net>
**
** Started on  Tue Jan 19 10:15:12 2016 Gwendoline Rodriguez
** Last update Tue Jan 19 14:37:40 2016 Gwendoline Rodriguez
*/

#ifndef LEMON_H
#define LEMON_H

#include "Banana.h"

class           Lemon : public Fruit {
 public:
  Lemon();
  Lemon(Lemon const&);
  Lemon& operator=(Lemon const&);
  virtual ~Lemon();

  virtual std::string  getName() const;
  virtual int           getVitamins() const;
};

#endif

