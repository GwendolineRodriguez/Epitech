/*
** main.c for main in /home/rodrig_1/fractals/gwen
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Tue Apr 28 11:36:00 2015 gwendoline rodriguez
** Last update Tue Apr 28 13:14:06 2015 gwendoline rodriguez
*/

int		check_error(char **av)
{
  int		i;
  int		c;

  c = 2;
  while (c < 4)
    {
      i = 0;
      while (av[c][i] != '\0')
	{
	  if (av[c][i] != '#' && av[c][i] != '@' && av[c][i] != ' ')
	    my_error("Strings only takes those caracters : ' ', '#', '@'.\n");
	  i++;
	}
      c++;
    }
}

int		main(int ac, char **av)
{
  if (ac == 4)
    {
      if ((av[1][0] >= '0' && av[1][0] <= '9') && av[1][1] == '\0'
	  && check_error(av) == 0)
	pars(av);
      else
	my_error("The first argument must be between 0 and 9.\n");
    }
  else
    my_error("The soft takes 3 arguments.\n");
  return (0);
}
