/*
** do-op.c for do-op in /home/RODRIG_1/rendu/Piscine_C_J11/do-op
** 
** Made by rodriguez gwendoline
** Login   <RODRIG_1@epitech.net>
** 
** Started on  Mon Oct 20 13:42:21 2014 rodriguez gwendoline
** Last update Thu Nov 13 14:48:28 2014 gwendoline rodriguez
*/

int	my_add(char *nb1, char *nb2);
int     my_sub(char *nb1, char *nb2);
int     my_div(char *nb1, char *nb2);
int     my_mul(char *nb1, char *nb2);
int     my_mod(char *nb1, char *nb2);

int	calculate(char *nb1, char *op, char *nb2)
{
  int	(*fptr[5])(char*, char*);

  fptr[0] = &my_add;
  fptr[1] = &my_sub;
  fptr[2] = &my_div;
  fptr[3] = &my_mul;
  fptr[4] = &my_mod;
  if (op[0] == '+')
      fptr[0](nb1, nb2);
  else if (op[0] == '-')
    fptr[1](nb1, nb2);
  else if (op[0] == '/')
    fptr[2](nb1, nb2);
  else if (op[0] == '*')
    fptr[3](nb1, nb2);
  else if (op[0] == '%')
    fptr[4](nb1, nb2);
}

int	main(int argc, char **argv)
{
  if (argv[2] == "0")
    {
      my_putstr("Stop : division by zero");
      return (0);
    }
  if (argv[2] == "0")
    {
      my_putstr("Stop : modulo by zero");
      return (0);
    }
  if (argc == 4)
    calculate(argv[1], argv[2], argv[3]);
  else
    my_putstr("Usage : ./do-op number operator number\n");
  return (0);
}
