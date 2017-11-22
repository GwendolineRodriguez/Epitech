/*
** my_getnbr_base.c for  in /home/daniel_b/Rendu/Piscine_C_J06
** 
** Made by Erwan DANIEL
** Login   <daniel_b@epitech.net>
** 
** Started on  Thu Oct  9 11:25:12 2014 Erwan DANIEL
** Last update Sun Feb  1 19:27:45 2015 DANIEL Erwan
*/

#include <stdio.h>

int	get_pos_in_base(char c, char *base)
{
  int	pos;

  pos = 0;
  while (*(base + pos) && *(base + pos) != c)
    pos++;
  if (*(base + pos))
    return (pos);
  else
    return (-1);
}

void	check_isneg(int *isneg, int *size, char **str)
{
  if (*str[0] == '-')
    {
      *isneg = 1;
      (*str)++;
      (*size)--;
    }
}

int	get_size(char *str)
{
  int	result;

  result = 0;
  while (str[result] != '\0')
    result++;
  return (result);
}

int	my_getnbr_base(char *str, char *base)
{
  int	result;
  int	base_len;
  int	size;
  int	counter;
  int	isneg;

  base_len = 0;
  counter = 0;
  size = 0;
  result = 0;
  size = get_size(str) - 1;
  base_len = get_size(base);
  check_isneg(&isneg, &size, &str);
  while (size >= 0)
    {
      result = result + get_pos_in_base(str[size], base)
	* my_pow(base_len, counter);
      counter++;
      size--;
    }
  if (isneg == 1)
    result *= -1;
  return (result);
}

int	my_pow(int nb, int pow)
{
  int	result;

  result = 1;
  while (pow > 0)
    {
      result = nb * result;
      pow--;
    }
  return (result);
}
