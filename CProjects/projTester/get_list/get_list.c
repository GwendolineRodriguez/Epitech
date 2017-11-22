/*
** parsing.c for parsing in /home/gwendoline/rendu/Piscine_Synthese/projTester/etape2
**
** Made by 
** Login   <gwendoline@epitech.net>
**
** Started on  Fri Jun 19 13:43:35 2015 
** Last update Sat Jun 20 23:04:33 2015 
*/

#include "./../header.h"

void		show_list(t_param *p)
{
  t_list	*tmp;
  int		i;

  tmp = p->list;
  printf("\npassage dans show_list\n");
  while (tmp)
    {
      i = 0;
      while (tmp->args[i] != NULL)
	{
	  printf("args[%d]:%s\n", i, tmp->args[i]);
	  i++;
	}
      printf("type:%s\n", tmp->type);
      tmp = tmp->next;
    }
  printf("sortie de showlist\n\n");
}

void            get_list(char **av, t_param *p, int fd)
{
  char          *line;
  t_list	*tmp;
  t_list	*first;

  first = create_elem();
  tmp = first;
  while (line = get_next_line(fd))
    {
      if (my_strcmp(line, "\n") != 0)
	{
	  tmp->args = my_strtowordtab(line);
	  tmp->type = my_strdup(tmp->args[0]);
	  if (my_strcmp(tmp->type, "ENTREE") == 0)
	    tmp->inputfile = my_strdup(tmp->args[1]);
	  else if (my_strcmp(tmp->type, "RES") == 0)
	    tmp->res = my_strdup(tmp->args[1]);
	  tmp->next = create_elem();
	  tmp->next->prev = tmp;
	  tmp = tmp->next;
	}
    }
  tmp->prev->next = 0;
  p->list = first;
}
