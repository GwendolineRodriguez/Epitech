/*
** main.c for main in /home/maure_d/rendu/Piscine_C_colles-Semaine_03
** 
** Made by Damien MAURE
** Login   <maure_d@epitech.net>
** 
** Started on  Sat Oct 25 18:49:42 2014 Damien MAURE
** Last update Sun Oct 26 00:12:02 2014 Damien MAURE
*/

#include <unistd.h>
#define BUFF_SIZE (4096)

int     main(int ac, char* av[])
{
  char  buff[BUFF_SIZE + 1];
  int   len;

  while ((len = read(0, buff, BUFF_SIZE)) > 0)
    {
      if (len != 0)
	{
          buff[len] = 0;
          colle1_1(buff);
	  colle1_2(buff);
	  colle1_3(buff);
	  colle1_4(buff);
	  colle1_5(buff);
	  if (*buff == 'B')
	    {
	      my_putstr("[colle1-3] [1] [1] || ");
	      my_putstr("[colle1-4] [1] [1] || [colle1-5] [1] [1]");
	    }
	  if (my_strlen(buff) == 1 && count_height(buff, 0, 0))
	    my_putstr("aucune");
	}
    }
  my_putchar('\n');
}
