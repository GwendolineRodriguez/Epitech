/*
** my_str_isalpha.c for  in /home/daniel_b/Piscine_C_J06
** 
** Made by Erwan DANIEL
** Login   <daniel_b@epitech.net>
** 
** Started on  Tue Oct  7 11:54:54 2014 Erwan DANIEL
** Last update Sun Feb  1 19:42:53 2015 DANIEL Erwan
*/

#include <stdio.h>

int	my_str_isalpha(char *str)
{
  int	counter;
  int	return_value;

  return_value = 0;
  counter = 0;
  while (str[counter] != '\0')
    {
      if (str[counter] < 65)
	return (0);
      if (str[counter] > 90 && str[counter] < 97)
	return (0);
      if (str[counter] > 122)
	return (0);
      counter++;
    }
  return (1);
}
