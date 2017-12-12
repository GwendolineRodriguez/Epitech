/*
** my_aff_params.c for my_aff_params in /home/RODRIG_1/rendu/Piscine_C_J07/ex_02
** 
** Made by rodriguez gwendoline
** Login   <RODRIG_1@epitech.net>
** 
** Started on  Wed Oct  8 08:20:14 2014 rodriguez gwendoline
** Last update Wed Oct  8 17:15:39 2014 rodriguez gwendoline
*/

int	main(int argc, char **argv)
{
  int	i;

  i = 0;
  while (i < argc)
    {
      my_putstr(argv[i]);
      i = i + 1;
      my_putchar('\n');
    }
  return (0);
}
