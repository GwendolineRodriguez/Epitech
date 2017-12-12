/*
** tests-my_strcpy.c for tests-my_strcpy in /home/RODRIG_1/rendu/Piscine_C_J06/tests
** 
** Made by rodriguez gwendoline
** Login   <RODRIG_1@epitech.net>
** 
** Started on  Mon Oct  6 17:21:35 2014 rodriguez gwendoline
** Last update Tue Oct  7 10:24:22 2014 rodriguez gwendoline
*/

int     main()
{
  char  str[] = "hello\n";
  char  str2[] = "wor\n";

  my_putstr(str);
  my_putstr(str2);
  my_strcpy(str, str2);
  my_putstr(str);
  my_putstr(str2);
}
