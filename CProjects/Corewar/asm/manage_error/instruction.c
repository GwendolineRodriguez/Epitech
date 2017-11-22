/*
** instruction.c for instructions in /home/backou_a/rendu/CPE_2014_corewar/arthur
**
** Made by arthur backouche
** Login   <backou_a@epitech.net>
**
** Started on  Sun Apr 12 14:38:39 2015 arthur backouche
** Last update Sun Apr 12 17:51:31 2015 gwendoline rodriguez
*/

#include "./../header/header.h"

int     find_add_sub_and_or_xor(char *line)
{
  int   separator;

  if (my_strncmp(line, "\tadd", 5) == 0 || my_strncmp(line, "\tsub", 5) == 0
      || my_strncmp(line, "\tand", 5) == 0
      || my_strncmp(line, "\tor", 4) == 0 || my_strncmp(line, "\txor", 5) == 0)
    {
      if ((separator = count_separator(line)) > 2)
	{
	  my_putstr("usage: only three param for [add][sub][and][or][xor]\n");
	  return (-1);
	}
    }
  return (0);
}

int     find_ld_st_lld_lldi(char *line)
{
  int   separator;

  if (my_strncmp(line, "\tld", 4) == 0 || my_strncmp(line, "\tst", 4) == 0
      || my_strncmp(line, "\tlld", 5) == 0
      || my_strncmp(line, "\tlldi", 6) == 0)
    {
      if ((separator = count_separator(line)) > 1)
	{
	  my_putstr("usage: only two param for [ld][st][lld][lldi]\n");
	  return (-1);
	}
    }
  return (0);
}

int     find_live_zjmp_fork_lfork_aff(char *line)
{
  int   separator;

  if (my_strncmp(line, "\tlive", 6) == 0 || my_strncmp(line, "\tzjmp", 6) == 0
      || my_strncmp(line, "\tfork", 6) == 0 || my_strncmp(line, "\tlfork", 7)
      == 0 || my_strncmp(line, "\taff", 5) == 0)
    {
      if ((separator = count_separator(line)) != 0)
	{
	  my_putstr("usage: only one param for ");
	  my_putstr("[live][zjmp][fork][lfork][aff]\n");
	  return (-1);
	}
    }
  return (0);
}
