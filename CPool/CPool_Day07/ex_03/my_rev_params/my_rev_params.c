/*
** my_rev_params.c for my_rev_params in /home/RODRIG_1/rendu/Piscine_C_J07/ex_03
** 
** Made by rodriguez gwendoline
** Login   <RODRIG_1@epitech.net>
** 
** Started on  Wed Oct  8 17:31:08 2014 rodriguez gwendoline
** Last update Wed Oct  8 18:31:22 2014 rodriguez gwendoline
*/

int	main(int argc, char **argv)
{
  int	i;

  i = argc - 1;
  while (i >= 0)
    {
      my_putstr(argv[i]);
      i = i - 1;
      my_putchar('\n');
    }
  return (0);
}
