/*
** my_swap.c for my_swap in /home/RODRIG_1/rendu/Piscine_C_J04
** 
** Made by rodriguez gwendoline
** Login   <RODRIG_1@epitech.net>
** 
** Started on  Thu Oct  2 10:52:27 2014 rodriguez gwendoline
** Last update Thu Oct  2 18:16:48 2014 rodriguez gwendoline
*/

int	my_swap(int *a, int *b)
{
  int c;

  c = *a;
  *a = *b;
  *b = c;
}
