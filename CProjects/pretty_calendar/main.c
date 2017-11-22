/*
** main.c for calendar in /home/duclos_r/Tek-1/Colle/pretty_calendar
** 
** Made by Rémi Duclos
** Login   <duclos_r@epitech.net>
** 
** Started on  Tue Jun  9 21:29:50 2015 Rémi Duclos
** Last update Tue Jun  9 21:31:42 2015 Rémi Duclos
*/

#include "calendar.h"

void	show_list(t_calendar *cal)
{
  t_calendar	*tmp;

  tmp = cal->next;
  while (tmp != cal)
    {
      my_putstr(get_alpha_nbr(tmp->day));
      my_putchar(' ');
      my_putstr(get_alpha_month(tmp->month));
      my_putchar(' ');
      my_putnbr(tmp->year);
      my_putstr(" =>\n");
      my_putnbr(tmp->h_begin);
      my_putstr(" heure -> ");
      my_putnbr(tmp->h_end);
      my_putstr(" heure : ");
      my_putstr(tmp->activity);
      my_putstr(".\n");
      tmp = tmp->next;
    }
}

int	main(int ac, char **av)
{
  parsing(av);
  return (0);
}
