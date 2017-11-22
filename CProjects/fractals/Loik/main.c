/*
** main.c for main in /home/rodrig_1/fractals/gwen
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Tue Apr 28 11:36:00 2015 gwendoline rodriguez
** Last update Tue Apr 28 10:24:13 2015 Loik Fauré-Berlinguette
*/

int		main(int ac, char **av)
{
  if (ac == 4)
    {
      if ((av[1][0] >= '0' && av[1][0] <= '9') && av[1][1] == '\0')
	{
	  pars(av);
	}
      else
	my_error("The first argument must be between 0 and 9.\n");
    }
  else
    my_error("The soft takes 3 arguments\n");
  return (0);
}
