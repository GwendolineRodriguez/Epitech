/*
** analyse_data.c for analyse_data in /home/backou_a/rendu/CPE_2014_corewar/arthur
**
** Made by arthur backouche
** Login   <backou_a@epitech.net>
**
** Started on  Sat Apr 11 19:02:04 2015 arthur backouche
** Last update Sun Apr 12 21:03:00 2015 gwendoline rodriguez
*/

#include "./../header/header.h"

int	line_correct(int i, int label)
{
  if (i == label)
    {
      my_putstr("Usage: use correct syntaxe.\n");
      return (-1);
    }
  return (0);
}

int	line_correct_syntaxe(char *line)
{
  int	cpt;
  int	i;
  int	label;

  cpt = 0;
  i = 1;
  label = my_strlen(LABEL_CHARS);
  while (line[cpt] != '\0')
    {
      if (line[cpt] == COMMENT_CHAR || line[cpt] == LABEL_CHAR || line[cpt]
	  == DIRECT_CHAR || line[cpt] == SEPARATOR_CHAR || line[cpt]
	  == LABEL_CHARS[0] || line[cpt] == '\t')
	cpt++;
      else
      	{
	  while (LABEL_CHARS[i] != line[cpt] && i < label)
      	    ++i;
	  if (LABEL_CHARS[i] == line[cpt])
      	    ++cpt;
	  line_correct(i, label);
      	}
      return (0);
    }
  return (0);
}

int	count_separator(char *line)
{
  int	cpt;
  int	virg;

  cpt = 0;
  virg = 0;
  while (line[cpt] != '\0' && line[cpt] != COMMENT_CHAR)
    {
      if (line[cpt] == SEPARATOR_CHAR)
	virg++;
      cpt++;
    }
  return (virg);
}

int	brows_file(int fd)
{
  char	*line;
  int	name;
  int	comment;
  int	check;

  check = 0;
  if ((line = get_next_line(fd)) == NULL)
    {
      close(fd);
      my_error("Error on open file.\n");
    }
  if ((name = analyse_name(line)) == -1)
    {
      my_putstr("usage: champion have no .name\n");
      return (-1);
    }
  line = get_next_line(fd);
  if ((comment = analyse_comment(line)) == -1)
    {
      my_putstr("usage: champion have no .comment\n");
      return (-1);
    }
  check = analyse_instruction(line, fd);
  return (check);
}

int	check_file(char *name_file)
{
  int	fd;
  int	check;

  fd = -1;
  check = 0;
  check_arg(name_file);
  if ((fd = open(name_file, O_RDONLY)) == -1)
    my_error("This file does not exist.\n");
  check = brows_file(fd);
  return (check);
}
