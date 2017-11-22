/*
** parsing.c for calendar in /home/duclos_r/Tek-1/Colle/pretty_calendar
** 
** Made by Rémi Duclos
** Login   <duclos_r@epitech.net>
** 
** Started on  Tue Jun  9 19:12:11 2015 Rémi Duclos
** Last update Wed Jun 10 00:04:13 2015 
*/

#include "calendar.h"

void		parsing(char **av)
{
  t_calendar	*cal;
  char		buffer[4096];
  int		fd;
  int		rd;

  fd = -1;
  if (av[1] != NULL)
    fd = open(av[1], O_RDONLY);
  if (fd > 0)
    {
      rd = read(fd, buffer, 4095);
      if (rd > 0)
	{
	  buffer[rd] = '\0';
	  cal = create_list();
	  fill_list(cal, buffer);
	  show_list(cal);
	}
    }
}

void		fill_list(t_calendar *cal, char *buffer)
{
  int		cnt;

  cnt = 0;
  while (buffer[cnt] != '\0')
    {
      put_in_next(cal);
      cal->next->day = get_nbr_sep(buffer, &cnt);
      cnt++;
      cal->next->month = get_nbr_sep(buffer, &cnt);
      cnt++;
      cal->next->year = get_nbr_sep(buffer, &cnt);
      cnt++;
      cal->next->h_begin = get_nbr_sep(buffer, &cnt);
      cnt++;
      cal->next->h_end = get_nbr_sep(buffer, &cnt);
      cnt++;
      cal->next->activity = strdup_sep(buffer, &cnt, '#');
      cnt++;
    }
}

int		get_nbr_sep(char *buffer, int *cnt)
{
  int		res;

  res = 0;
  while (buffer[(*cnt)] != '\0' && (buffer[(*cnt)] >= '0'
				    && buffer[(*cnt)] <= '9'))
    {
      res = (res * 10) + (buffer[(*cnt)] - '0');
      (*cnt)++;
    }
  return (res);
}

char		*strdup_sep(char *buffer, int *cnt, char sep)
{
  char		*res;
  int		len;
  int		cnt2;

  len = (*cnt);
  while (buffer[len] != '\0' && buffer[len] != sep)
    len++;
  res = malloc(sizeof(*res) * ((len - (*cnt)) + 1));
  if (res == NULL)
    exit(0);
  cnt2 = 0;
  while (buffer[(*cnt)] != '\0' && buffer[(*cnt)] != sep)
    {
      res[cnt2] = buffer[(*cnt)];
      (*cnt)++;
      cnt2++;
    }
  res[cnt2] = '\0';
  return (res);
}
