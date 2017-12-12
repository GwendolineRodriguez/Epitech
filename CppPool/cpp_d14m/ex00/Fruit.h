/*
** Fruit.h for Fruit in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d14m/ex00
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.net>
**
** Started on  Tue Jan 19 09:57:43 2016 Gwendoline Rodriguez
** Last update Tue Jan 19 12:21:20 2016 Gwendoline Rodriguez
*/

#ifndef FRUIT_H
#define FRUIT_H

#include <iostream>

class		Fruit {
 protected:
  int           _vitamins;
  std::string	_name;

 public:
  explicit Fruit(int vitamins, std::string const& name);
  explicit Fruit(Fruit const&);
  Fruit& operator=(Fruit const&);
  virtual ~Fruit();

  //Getters
  virtual std::string	getName() const = 0;
  virtual int		getVitamins() const = 0;

};

#endif
