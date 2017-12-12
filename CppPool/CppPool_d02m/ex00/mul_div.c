/*
** mul_div.c for mul_div in /home/gwendoline/Epitech/Tek2/rendu/Piscine_cpp/piscine_cpp_d02m/ex00
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.net>
**
** Started on  Thu Jan  7 09:13:40 2016 Gwendoline Rodriguez
** Last update Thu Jan  7 09:31:53 2016 Gwendoline Rodriguez
*/

#include <stdio.h>

void	add_mul_4param(int first, int second, int *add, int *mul)
{
  *add = first + second;
  *mul = first * second;
}

void	add_mul_2param(int *first, int *second)
{
  *first = *first + *second;
  *second = (*first - *second) * *second;
}

/* int main(void) */
/* { */
/*   int first; */
/*   int second; */
/*   int add_res; */
/*   int mul_res; */

/*   first = 5; */
/*   second = 6; */

/*   add_mul_4param(first, second, &add_res, &mul_res); */
/*   printf("%d + %d = %d\n", first, second, add_res); */
/*   printf("%d * %d = %d\n", first, second, mul_res); */

/*   add_res = first; */
/*   mul_res = second; */
/*   add_mul_2param(&add_res, &mul_res); */
/*   printf("%d + %d = %d\n", first, second, add_res); */
/*   printf("%d * %d = %d\n", first, second, mul_res); */
/*   return (0); */
/* } */
