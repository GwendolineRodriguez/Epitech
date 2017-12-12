x/*
** tests-my_strstr.c for tests-my_strstr in /home/RODRIG_1/rendu/Piscine_C_J06/tests
** 
** Made by rodriguez gwendoline
** Login   <RODRIG_1@epitech.net>
** 
** Started on  Tue Oct  7 10:16:09 2014 rodriguez gwendoline
** Last update Tue Oct  7 10:25:41 2014 rodriguez gwendoline
*/

int     main()
{
  char  str[] = "hello world genius\n";
  char  str2[] = "world\n";

  my_putstr(str);
  my_putstr(str2);
  my_strstr(str, str2);
  my_putstr(str);
  my_putstr(str2);
  strstr(str, str2);
  my_putstr(str);
  my_putstr(str2);
}
