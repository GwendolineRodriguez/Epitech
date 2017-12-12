/*
** FruitNode.h for FruitNode in /home/gwendoline/Epitech/Tek2/Piscine_cpp/piscine_cpp_d14m/ex00
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.eu>
**
** Started on  Tue Jan 19 12:30:23 2016 Gwendoline Rodriguez
** Last update Tue Jan 19 12:30:44 2016 Gwendoline Rodriguez
*/

#ifndef FRUITNODE_H
#define FRUITNODE_H

#include "Fruit.h"

typedef struct          s_FruitNode {
    Fruit               *fruit;
    struct s_FruitNode  *next;
}                       FruitNode;

#endif
