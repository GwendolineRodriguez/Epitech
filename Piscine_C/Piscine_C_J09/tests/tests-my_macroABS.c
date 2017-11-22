/*
** tests-my_macroABS.c for tests-my_macroABS in /home/RODRIG_1/rendu/Piscine_C_J09
** 
** Made by rodriguez gwendoline
** Login   <RODRIG_1@epitech.net>
** 
** Started on  Thu Oct  9 14:34:11 2014 rodriguez gwendoline
** Last update Tue Nov  4 11:44:08 2014 rodriguez gwendoline
*/

#include "./../ex_01/my_macroABS.h"

int     main()
{
  int   i;

  i = -2;
  i = ABS(i);
  my_putchar(i + '0');
}
