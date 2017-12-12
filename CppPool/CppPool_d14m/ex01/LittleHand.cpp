//
// LittleHand.cpp for LittleHand in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d14m/ex01
//
// Made by Gwendoline Rodriguez
// Login   <gwendoline@epitech.eu>
//
// Started on  Tue Jan 19 14:27:22 2016 Gwendoline Rodriguez
// Last update Tue Jan 19 14:27:54 2016 Gwendoline Rodriguez
//

#include "LittleHand.h"

void LittleHand::sortFruitBox(FruitBox& unsorted,
                              FruitBox& lemons,
                              FruitBox& bananas,
                              FruitBox& limes) {
  FruitBox    tmp(unsorted.nbFruits());
  Fruit       *fruit;
  while ((fruit = unsorted.pickFruit())) {
    if (fruit->getName() == "lemon") {
      if (!lemons.putFruit(fruit))
	tmp.putFruit(fruit);
    }
    else if (fruit->getName() == "lime") {
      if (!limes.putFruit(fruit))
	tmp.putFruit(fruit);
    }
    else if (fruit->getName() == "banana") {
      if (!bananas.putFruit(fruit))
	tmp.putFruit(fruit);
    }
    else            tmp.putFruit(fruit);
  }
  while ((fruit = tmp.pickFruit())) {
    unsorted.putFruit(fruit);
  }
}

