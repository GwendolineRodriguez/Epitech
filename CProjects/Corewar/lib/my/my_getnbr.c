/*
** my_getnbr.c for my_getnbr in /home/rodrig_1/lib/my
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Tue Nov 18 18:35:20 2014 gwendoline rodriguez
** Last update Sun Mar  8 23:23:27 2015 gwendoline rodriguez
*/

int	if_neg(char *str, int *nb)
{
  int   i;
  int   sign;

  i = 0;
  sign = 0;
  while (str[i] != '\0' && (str[i] == '-' || str[i] == '+'))
    {
      if (str[i] == '-')
        sign = sign + 1;
      i = i + 1;
    }
  if (sign % 2 != 0)
    *nb = *nb * (-1);
  return (0);
}

int	my_getnbr(char *str)
{
  int	nb;
  int	i;

  nb = 0;
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= '0' && str[i] <= '9')
	{
	  nb = nb * 10;
	  nb = nb + (str[i] - 48);
	  i = i + 1;
	}
      else if (str[i] <= '0' && str[i] >= '9')
	return (nb);
      else
	i = i + 1;
    }
  if (nb > 2000000000)
    return (0);
  if_neg(str, &nb);
  return (nb);
}
