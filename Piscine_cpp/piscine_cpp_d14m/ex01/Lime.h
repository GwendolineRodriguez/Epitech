/*
** Lime.h for Lime in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d14m/ex01
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.eu>
**
** Started on  Tue Jan 19 13:04:47 2016 Gwendoline Rodriguez
** Last update Tue Jan 19 13:10:46 2016 Gwendoline Rodriguez
*/

#ifndef LIME_H
#define LIME_H

#include "Lemon.h"

class           Lime : public Lemon {
 public:
  Lime();
  Lime(Lime const&);
  Lime& operator=(Lime const&);
  virtual ~Lime();

  virtual std::string  getName() const;
  virtual int           getVitamins() const;
};

#endif
