/*
** tests-my_strncpy.c for tests-my_strncpy in /home/RODRIG_1/rendu/Piscine_C_J06/tests
** 
** Made by rodriguez gwendoline
** Login   <RODRIG_1@epitech.net>
** 
** Started on  Mon Oct  6 17:18:43 2014 rodriguez gwendoline
** Last update Mon Oct  6 17:18:55 2014 rodriguez gwendoline
*/

int     main()
{
  char  str[] = "hello\n";
  char  str2[] = "world\n";

  my_putstr(str);
  my_putstr(str2);
  my_strncpy(str, str2, 3);
  my_putstr(str);
  my_putstr(str2);
}
