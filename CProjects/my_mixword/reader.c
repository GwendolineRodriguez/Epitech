/*
** reader.c for reader in /home/gwendoline/rendu/Prgelm/colles/my_mixword/gwen
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.net>
**
** Started on  Wed Jun 10 11:23:32 2015 
** Last update Wed Jun 10 15:07:43 2015 
*/

#include "my_mixword.h"

int		check_ifword(t_grid *p)
{
  int		check;

  check = check_h(p);
  if (check == 0)
    check = check_v(p);
  else if (check = 0)
    check = check_diag_down_right(p);
  else if (check = 0)
    check = check_hrev(p);
  else if (check = 0)
    check = check_vrev(p);
  else if (check = 0)
    check = check_diag_down_left(p);
  else if (check = 0)
    check = check_diag_up_right(p);
  else if (check = 0)
    check = check_diag_up_left(p);
  return (check);
}

int		reader(t_grid *p)
{
  char		buffer[4096];
  int		ret;
  int		check;

  ret = 0;
  check = 0;
  my_putstr("> ");
  while ((ret = read(0, buffer, 4095)) > 0)
    {
      if (ret < 0)
	my_error("error on read.\n");
      buffer[ret] == '\0';
      p->word = my_strdup(buffer);
      if (my_strlen(p->word) <= p->size)
	check = check_ifword(p);
      else if (check == 0)
	my_putstr("Word is not found in the grid !\n");
      my_putstr("> ");
    }
  return (0);
}
