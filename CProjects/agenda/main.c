/*
1;2802;0c1;2802;0c** main.c for main in /home/gwendoline/rendu/Piscine_Synthese/agenda
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.net>
**
** Started on  Mon Jun 29 13:12:07 2015 Gwendoline Rodriguez
** Last update Tue Jun 30 16:13:43 2015 Gwendoline Rodriguez
*/

#include "header.h"

char		*check_end(char *buffer)
{
  if (my_strncmp(&buffer[my_strlen(buffer) - 4], "END", 3) != 0)
    put_error("commande incorrecte\n");
  return (buffer);
}

int		main(int ac, UNUSED char **av)
{
  char		*buffer;
  t_employee	*employee;
  t_meeting	*meeting;
  int		ret;
  int		fd;

  buffer = malloc(sizeof(char) * BUFF_MAX);
  employee = malloc(sizeof(t_employee));
  meeting = malloc(sizeof(t_meeting));
  if (ac == 1)
    {
      if ((ret = (read(0, buffer, BUFF_MAX))) == -1 && ret != 0)
	return (0);
      buffer[ret] = '\0';
      buffer = check_end(buffer);
      fd = open("file", O_CREAT | O_WRONLY, 0644);
      write(fd, buffer, ret);
      close(fd);
      setup_agenda(employee, meeting, fd);
    }
  return (0);
}
