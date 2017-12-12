/*
** LittleHand.h for LittleHand in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d14m/ex01
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.eu>
**
** Started on  Tue Jan 19 12:58:02 2016 Gwendoline Rodriguez
** Last update Tue Jan 19 14:30:51 2016 Gwendoline Rodriguez
*/

#ifndef LITTLEHAND_H
#define LITTLEHAND_H

#include <iostream>
#include "Lemon.h"
#include "FruitBox.h"

class           LittleHand {
 public:
  static void sortFruitBox(FruitBox& unsorted,
			   FruitBox& lemons,
			   FruitBox& bananas,
			   FruitBox& limes);

};

#endif
