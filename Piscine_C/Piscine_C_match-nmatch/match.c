/*
** match.c for match in /home/RODRIG_1/rendu/Piscine_C_match-nmatch
** 
** Made by rodriguez gwendoline
** Login   <RODRIG_1@epitech.net>
** 
** Started on  Thu Oct  9 18:43:33 2014 rodriguez gwendoline
** Last update Sun Oct 12 22:59:01 2014 rodriguez gwendoline
*/

int	match(char *s1, char*s2)
{
  int	i;
  int	i2;

  i = 0;
  i2 = 0;
  while (s1[i] != '\0')
    {
      while (s1[i] != s2[i2] && s2[i2] == '*')
        {
          while (s2[i2] == '*')
            {
              i2 = i2 + 1;
            }
	  i = i + 1;
	}
      if (s1[i] != s2[i2] && s2[i2] != '*')
	return (0);
      while (s1[i] == s2[i2])
	{
	  i = i + 1;
	  i2 = i2 + 1;
	}
    }
  return (1);
}

int	main()
{
  my_put_nbr(match("hello", "**************llo"));
  my_putchar('\n');
}
