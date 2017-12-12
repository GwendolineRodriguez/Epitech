/*
** eval_expr.c for eval_expr in /home/RODRIG_1/rendu/Piscine_C_eval_expr
** 
** Made by rodriguez gwendoline
** Login   <RODRIG_1@epitech.net>
** 
** Started on  Fri Oct 24 09:49:35 2014 rodriguez gwendoline
** Last update Wed Oct 29 13:13:07 2014 rodriguez gwendoline
*/

int     my_add(char *nb1, char *nb2);
int     my_sub(char *nb1, char *nb2);
int     my_div(char *nb1, char *nb2);
int     my_mul(char *nb1, char *nb2);
int     my_mod(char *nb1, char *nb2);

int     eval_expr(char **str)
{
  int   (*fptr[5])(char*, char*);
  int	res;

  fptr[0] = &my_add;
  fptr[1] = &my_sub;
  fptr[2] = &my_div;
  fptr[3] = &my_mul;
  fptr[4] = &my_mod;
  if (str[2][0] == '+')
    res = fptr[0](str[1], str[3]);
  else if (str[2][0] == '-')
    res = fptr[1](str[1], str[3]);
  else if (str[2][0] == '/')
    res = fptr[2](str[1], str[3]);
  else if (str[2][0] == '*')
    res = fptr[3](str[1], str[3]);
  else if (str[2][0] == '%')
    res = fptr[4](str[1], str[3]);
  return (res);
}

int	main(int ac, char **av)
{
  if (ac > 1)
    {
      my_put_nbr(eval_expr(av));
      my_putchar('\n');
    }
  return (0);
}
