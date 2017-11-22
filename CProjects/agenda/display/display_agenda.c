/*
** display_agenda.c for display_agenda in /home/gwendoline/rendu/Piscine_Synthese/agenda
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.net>
**
** Started on  Tue Jun 30 11:30:19 2015 Gwendoline Rodriguez
** Last update Wed Jul  1 19:53:27 2015 Gwendoline Rodriguez
*/

#include "header.h"

static int      compare(const void *a, const void *b)
{
  return strcmp(*(char **)a, *(char **)b);
}

char            **sort_tab(char **tab)
{
  int           i;

  i = -1;
  while (tab[++i])
    tab[i] = rev_word(tab[i]);
  qsort(tab, len_tab(tab), sizeof *tab, compare);
  i = -1;
  while (tab[++i])
    tab[i] = rev_word(tab[i]);
  return (tab);
}

void		display_empmeet(t_employee *tmp)
{
  int		i;
  int		j;
  int		h;
  int		y;

  j = -1;
  h = -1;
  y = -1;
  while (tmp->meeting[++j][0] != NULL)
    {
      i = -1;
      if (tmp->meeting[j][0] != NULL)
	{
	  tmp->meeting[j] = sort_tab(tmp->meeting[j]);
	  printf("réunion le %s, %s, avec ", tmp->day[++h], tmp->zipmeet[++y]);
	  while (tmp->meeting[j][++i] != NULL)
	    {
	      printf("%s", tmp->meeting[j][i]);
	      if (tmp->meeting[j][i + 1] != NULL)
		printf(", ");
	    }
	  printf("\n");
	}
    }
}

void            display_employee(t_employee *employee)
{
  t_employee    *tmp;

  tmp = employee;
  while (tmp)
    {
      if (tmp->name != NULL && tmp->forename != NULL)
        {
          printf("*****************************\n");
          printf("%s %s\n", tmp->forename, tmp->name);
          printf("poste: %s\n", tmp->job);
          printf("ville: %s\n", tmp->zip);
	  if (tmp->meeting[0][0] != NULL)
	    display_empmeet(tmp);
        }
      tmp = tmp->next;
    }
}

void            display_meeting(t_meeting *meeting, int i)
{
  t_meeting    *tmp;

  tmp = meeting;
  while (tmp)
    {
      if (tmp->day != NULL && tmp->zip != NULL && tmp->names[0] != NULL)
	{
	  i = -1;
	  tmp->names = sort_tab(tmp->names);
	  printf("*****************************\n");
	  printf("REUNION\n");
	  printf("date: %s\n", tmp->day);
	  printf("lieu: %s\n", tmp->zip);
	  if (tmp->names[0] != NULL)
	    printf("avec ");
	  while (tmp->names[++i] != NULL)
	    {
	      printf("%s", tmp->names[i]);
	      if (tmp->names[i + 1] != NULL)
		printf(", ");
	    }
	  printf("\n");
	}
      tmp = tmp->next;
    }
}
