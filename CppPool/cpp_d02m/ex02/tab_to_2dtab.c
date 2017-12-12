/*
** tab_to_2dtab.c for tab_to_2dtab in /home/gwendoline/Epitech/Tek2/rendu/Piscine_cpp/piscine_cpp_d02m/ex02
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.net>
**
** Started on  Thu Jan  7 10:44:05 2016 Gwendoline Rodriguez
** Last update Thu Jan  7 11:27:26 2016 Gwendoline Rodriguez
*/

#include <stdio.h>
#include <stdlib.h>

void	tab_to_2dtab(int *tab, int length, int width, int ***res)
{
  int i;
  int j;

  i = 0;
  *res = malloc(length * sizeof(int*) + 1);
  while(i <= length)
    {
      j = 0;
      (*res)[i] = malloc(width * sizeof(int) + 1);
      while(j <= width)
	{
	  (*res)[i][j] = tab[i * width + j];
	  j++;
	}
      i++;
    }
}

/* int main(void) */
/* { */
/*   int **tab_2d; */
/*   int tab[42] = {0, 1, 2, 3, 4, 5, */
/* 		 6, 7, 8, 9, 10, 11, */
/* 		 12, 13, 14, 15, 16, 17, */
/* 		 18, 19, 20, 21, 22, 23, */
/* 		 24, 25, 26, 27, 28, 29, */
/* 		 30, 31, 32, 33, 34, 35, */
/* 		 36, 37, 38, 39, 40, 41}; */

/*   tab_to_2dtab(tab, 7, 6, &tab_2d); */
/*   printf("tab2[%d][%d] = %d\n", 0, 0, tab_2d[0][0]); */
/*   printf("tab2[%d][%d] = %d\n", 6, 5, tab_2d[6][5]); */
/*   printf("tab2[%d][%d] = %d\n", 4, 4, tab_2d[4][4]); */
/*   printf("tab2[%d][%d] = %d\n", 0, 3, tab_2d[0][3]); */
/*   printf("tab2[%d][%d] = %d\n", 3, 0, tab_2d[3][0]); */
/*   printf("tab2[%d][%d] = %d\n", 4, 2, tab_2d[4][2]); */
/*   return (0); */
/* } */
