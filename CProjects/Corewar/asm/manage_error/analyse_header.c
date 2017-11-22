/*
** analyse_header.c for analyse_header in /home/backou_a/rendu/CPE_2014_corewar/arthur
**
** Made by arthur backouche
** Login   <backou_a@epitech.net>
**
** Started on  Sun Apr 12 14:41:19 2015 arthur backouche
** Last update Sun Apr 12 21:02:40 2015 gwendoline rodriguez
*/

#include "./../header/header.h"

int     analyse_instruction(char *line, int fd)
{
  int	syntaxe;
  int	check;

  check = 0;
  line = get_next_line(fd);
  while (line != NULL)
    {
      if ((line = get_next_line(fd)) == NULL)
	return (0);
      if ((syntaxe = line_correct_syntaxe(line)) != -1)
	{
	  check = find_live_zjmp_fork_lfork_aff(line);
	  check = check + find_ld_st_lld_lldi(line);
	  check = check + find_add_sub_and_or_xor(line);
	}
    }
  return (check);
}

int     analyse_comment(char *line)
{
  if (my_strncmp(line, COMMENT_CMD_STRING, my_strlen(NAME_CMD_STRING) != 0))
    return (-1);
  return (0);
}

int     analyse_name(char *line)
{
  if (my_strncmp(line, NAME_CMD_STRING, my_strlen(NAME_CMD_STRING) != 0))
    return (-1);
  return (0);
}
