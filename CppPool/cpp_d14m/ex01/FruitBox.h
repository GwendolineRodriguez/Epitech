/*
** FruitBox.h for FruitBox in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d14m/ex00
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.eu>
**
** Started on  Tue Jan 19 12:28:06 2016 Gwendoline Rodriguez
** Last update Tue Jan 19 12:29:20 2016 Gwendoline Rodriguez
*/

#ifndef FRUITBOX_H
#define FRUITBOX_H

#include "Fruit.h"
#include "FruitNode.h"

class FruitBox {
  int         _size;
  int         _nbrFruits;
  FruitNode   *_list;
public:
    FruitBox(int);
    ~FruitBox();

    int nbFruits() const;
    bool putFruit(Fruit* f);
    Fruit* pickFruit();
    FruitNode* head();
};

#endif
