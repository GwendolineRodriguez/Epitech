/*
** func_ptr.c for func_ptr in /home/gwendoline/Epitech/Tek2/rendu/Piscine_cpp/piscine_cpp_d02m/ex03
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.net>
**
** Started on  Thu Jan  7 11:28:07 2016 Gwendoline Rodriguez
** Last update Thu Jan  7 18:29:56 2016 Gwendoline Rodriguez
*/

#include "func_ptr.h"

int     get_array_size(char *str)
{
  char  *temp_str;
  int   size_of_array;

  temp_str = str;
  size_of_array = 0;
  while (*temp_str != '\0')
    {
      size_of_array++;
      temp_str = temp_str + sizeof (char);
    }
  return (size_of_array);
}

void revstr(char *s)
{
  char *i1, *i2, *m;
  int len;

  len = strlen(s), i1 = s, i2 = i1+len-1, m = i1 + len/2;
  while (i1 < m) {
    char c;
    c = *i1;
    *i1++ = *i2;
    *i2-- = c;
  }
}

char    *my_strupcase(char *str)
{
  int   size_of_str;
  int   counter;

  counter = 0;
  size_of_str = 0;
  while (str[size_of_str] != '\0')
    size_of_str++;
  while (counter != size_of_str)
    {
      if (str[counter] >= 97 && str[counter] <= 122)
        str[counter] = str[counter] - 32;
      counter++;
    }
  return (str);
}

void	print_normal(char *str)
{
  printf("%s\n", str);
}

void	print_reverse(char *str)
{
  char *tmp;

  tmp = malloc(strlen(str) - 1);
  strcat(tmp, str);
  revstr(tmp);
  printf("%s\n", tmp);
}

void	print_upper(char *str)
{
  char *tmp;

  tmp = malloc(strlen(str) - 1);
  strcat(tmp, str);
  printf("%s\n", my_strupcase(tmp));
}

void	print_42(__attribute__ ((unused))char *str)
{
  printf("42\n");
}

void	do_action(t_action action, char *str)
{
  int	i;
  t_action_func list[] = {
    {PRINT_NORMAL, &print_normal},
    {PRINT_REVERSE, &print_reverse},
    {PRINT_UPPER, &print_upper},
    {PRINT_42, &print_42},
  };

  i = 0;
  while(i <= 4)
     {
      if (action == list[i].action)
	{
	  (*list[i].func)(str);
	  return;
	}
      i++;
    }
}

/* int main(void) */
/* { */
/*   char *str = "J'tilise les pointeurs sur fonctions !"; */
/*   do_action(PRINT_NORMAL, str); */
/*   do_action(PRINT_REVERSE, str); */
/*   do_action(PRINT_UPPER, str); */
/*   do_action(PRINT_42, str); */

/*   return (0); */
/* } */
