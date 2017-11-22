/*
** my_printf.c for  in /home/daniel_b/Rendu/PSU_2014_my_printf
** 
** Made by daniel_b
** Login   <daniel_b@epitech.net>
** 
** Started on  Thu Nov 13 20:02:41 2014 daniel_b
** Last update Sat Jan 17 16:23:54 2015 DANIEL Erwan
*/

#include <stdarg.h>
#include <stdio.h>

int		my_printf(const char *format, ...)
{
  va_list	ap;
  int		counter;

  va_start(ap, format);
  counter = 0;
  while (format[counter])
    {
      if (format[counter] == '%')
	{
	  if (!check_format(format, counter++, &ap))
	    write(1, &format[counter], 1);
	}
      else
	write(1, &format[counter], 1);
      counter++;
    }
  va_end(ap);
  return (counter);
}

int	get_unsigned(int nb)
{
  if (nb < 0)
    return (nb + 4294967295 / 2);
  else
    return (nb);
}

void	put_non_printable(char *str)
{
  int	counter;

  counter = 0;
  while (str[counter])
    {
      if (str[counter] < 32 || str[counter] >= 127)
	{
	  write(1, "\\", 1);
	  my_putnbr_base(str[counter], "01234567");
	}
      else
	write(1, &str[counter], 1);
      counter++;
    }
}

int	check_format(char *format, int pos, va_list *ap)
{
  if (format[pos + 1] == '%')
    my_putstr("%");
  if (format[pos + 1] == 'd' || format[pos + 1] == 'i')
    my_put_nbr(va_arg(ap, int));
  if (format[pos + 1] == 's')
    my_putstr(va_arg(ap, char *));
  if (format[pos + 1] == 'c')
    my_putchar(va_arg(ap, int));
  if (format[pos + 1] == 'o')
    my_putnbr_base(get_unsigned(va_arg(ap, int)), "01234567");
  if (format[pos + 1] == 'x')
    my_putnbr_base(get_unsigned(va_arg(ap, int)), "0123456789ABCDEF");
  if (format[pos + 1] == 'S')
    put_non_printable(va_arg(ap, char *));
  return (1);
}
