/*
** tests-my_putstr.c for tests-my_putstr in /home/RODRIG_1/rendu/Piscine_C_J04/tests
** 
** Made by rodriguez gwendoline
** Login   <RODRIG_1@epitech.net>
** 
** Started on  Thu Oct  2 22:22:23 2014 rodriguez gwendoline
** Last update Fri Oct  3 21:16:45 2014 rodriguez gwendoline
*/

int	my_putchar(char c)
{
  write(1, &c, 1);
}

int	main()
{
  int	i;
  char	*str;

  str= "epitech";
  my_strlen(str);
}
