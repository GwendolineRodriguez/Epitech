/*
1;2802;0c** white_rabbit.c for white_rabbit in /home/gwendoline/Epitech/Tek2/rendu/Piscine_cpp/piscine_cpp_d01/ex00
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.net>
**
** Started on  Wed Jan  6 09:26:59 2016 Gwendoline Rodriguez
** Last update Wed Jan  6 22:40:11 2016 Gwendoline Rodriguez
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int    follow_the_white_rabbit(void)
{
  int n;
  int check;
  int result;

  check = 0;
  result = 0;
  while (check == 0)
    {
      n = random() % 37 + 1;
      result += result + n;
      if (n == 1 || n == 37 || n >= 397)
	{
          check = 1;
          printf("LAPIN !!!\n");
        }
      else if ((n >= 4 && n <= 6) || n == 28 || (n >= 17 && n <= 21))
	printf("gauche\n");
      else if (n == 13 || n >= 34)
	printf("droite\n");
      else if (n == 10 || n == 15 || n == 23)
        printf("devant\n");
      else if (n == 26 || (n % 8 == 0))
        printf("derriere\n");
     }
  return (n);
}

/* int    main() */
/* { */
/*   srandom(44); */
/*   follow_the_white_rabbit(); */
/*   return (0); */
/* } */
