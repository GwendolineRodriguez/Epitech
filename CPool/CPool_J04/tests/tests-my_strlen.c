/*
** tests-my_strlen.c for tests-my_strlen in /home/RODRIG_1/rendu/Piscine_C_J04/tests
** 
** Made by rodriguez gwendoline
** Login   <RODRIG_1@epitech.net>
** 
** Started on  Thu Oct  2 23:23:24 2014 rodriguez gwendoline
** Last update Fri Oct  3 21:17:24 2014 rodriguez gwendoline
*/

int     my_putchar(char c)
{
  write(1, &c, 1);
}

int     main()
{
  int	i;
  char	*str;

  str= "epitech";
  i = my_strlen(str);
  i = i + 48;
  my_putchar(i);
}
