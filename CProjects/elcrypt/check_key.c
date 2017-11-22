/*
** check_key.c for check_key in /home/rodrig_1/rendu/Prgelm/elcrypt
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Sat Feb 28 14:26:02 2015 gwendoline rodriguez
** Last update Sun Mar  1 20:42:35 2015 gwendoline rodriguez
*/

#include "structs.h"
#include "my.h"

int		my_get16base(char *key, t_data *p, int i)
{
  char		*tmp;
  int		j;

  tmp = my_strdup(key);
  if (tmp == 0)
    exit(0);
  j = 0;
  while (key[i] != '\0' && tmp[j] != '\0')
    {
      if ((key[i] >= '0' && key[i] <= '9') || (key[i] >= 'A' && key[i] <= 'F'))
	tmp[j] = key[i];
      else
	my_error("The key contains forbidden characters.\n");
      i++;
      j++;
    }
  tmp[j] = '\0';
  if (my_strlen(tmp) != 16)
    my_error("The hexadecimal key does not have 16 characters.\n");
  p->key = my_strdup(tmp);
  p->base = "0123456789ABCDEF";
  p->check += 4;
  return (0);
}

int             my_get10base(char *key, t_data *p, int i)
{
  char          *tmp;
  int           j;

  tmp = my_strdup(key);
  if (tmp == 0)
    exit(0);
  j = 0;
  while (key[i] != '\0' && tmp[j] != '\0')
    {
      if (key[i] >= '0' && key[i] <= '9')
	tmp[j] = key[i];
      else
	my_error("The key contains forbidden characters.\n");
      i++;
      j++;
    }
  tmp[j] = '\0';
  if (my_strlen(tmp) != 20)
    my_error("The decimal key does not have 20 characters.\n");
  p->key = my_strdup(tmp);
  p->base = "0123456789";
  p->check += 4;
  return (0);
}

int		my_get8base(char *key, t_data *p, int i)
{
  char          *tmp;
  int           j;

  tmp = my_strdup(key);
  if (tmp == 0)
    exit(0);
  j = 0;
  while (key[i] != '\0')
    {
      if (key[i] >= '0' && key[i] <= '7')
	tmp[j] = key[i];
      else
	my_error("The key contains forbidden characters.\n");
      i++;
      j++;
    }
  tmp[j] = '\0';
  if (my_strlen(tmp) != 8)
    my_error("The octal key must have 8 characters.\n");
  p->key = my_strdup(tmp);
  p->base = "01234567";
  p->check += 4;
  return (0);
}

int		my_get2base(char *key, t_data *p, int i)
{
  char          *tmp;
  int           j;

  tmp = my_strdup(key);
  if (tmp == 0)
    exit(0);
  j = 0;
  while (key[i] != '\0')
    {
      if (key[i] == '0' || key[i] == '1')
	tmp[j] = key[i];
      else
	my_error("The key contains forbidden characters.\n");
      i++;
      j++;
    }
  tmp[j] = '\0';
  if (my_strlen(tmp) != 64)
    my_error("The binary key must have 64 characters.\n");
  p->key = my_strdup(tmp);
  p->base = "01";
  p->check += 4;
  return (0);
}

int             check_key(char *key, t_data *p)
{
  int		i;
  int		check;

  i = 0;
  check = 0;
  while (key[i] != '\0')
    {
      if (key[i] >= '0' && key[i] <= '9')
	check++;
      i++;
    }
  if (key[0] == '0' && key[1] == 'x')
    my_get16base(key, p, 2);
  else if (check == i)
    my_get10base(key, p, 0);
  else if (key[0] == '0' && key[1] != 'x' && my_strlen(key) == 9)
    my_get8base(key, p, 1);
  else if (key[0] == '%')
    my_get2base(key, p, 1);
  else
    my_error("ascii key is not supported.\n");
  return (0);
}
