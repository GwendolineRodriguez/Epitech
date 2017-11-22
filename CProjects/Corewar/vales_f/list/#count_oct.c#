/*
** count_oct.c for count_oct in /home/vales_f/rendu/CPE_2014_corewar/vales_f/list
**
** Made by florian Vales
** Login   <vales_f@epitech.net>
**
** Started on  Sun Apr 12 16:38:50 2015 florian Vales
** Last update Sun Apr 12 22:11:13 2015 florian Vales
*/

int		nbr_oct(char **tab, char **lab_tab)
{
  int		x;
  int		y;
  int static	z = 0;

  x = 0;
  y = 0;
  if (z != 0)
    z = 0;
  /* while (tab[x][0] == '.') */ /* la c'est pour passer les .machin*/
  /*   x++; */      /*mais j'ai du mal a voir si je le laisse là ou si je le fais avant */
  while (my_str_nfirst_cmp(tab[x], lab_tab[x], my_strlen(lab_tab[x])) != 0)
    x++;
  while (y < x)
    {
      z = nbr_oct_follow(y, tab);
      y++;
    }
  return (oct);
}

int	nbr_oct_follow(int y, char **tab)
{
  int	oct;

  oct = 0;
  /* il manque la vérif de label pour commencer la vérif après le nom du label */
  /* a voir dans une fonction juste avant, mais la je suis au max de ligne */
  if (my_str_nfirst_cmp(tab[y], "\tlive", 5) == 0)
    oct++;
  else if (my_str_nfirst_cmp(tab[y], "\tld", 3) == 0 ||
	   my_str_nfirst_cmp(tab[y], "\tst", 3) == 0 ||
	   my_str_nfirst_cmp(tab[y], "\tadd", 4) == 0 ||
	   my_str_nfirst_cmp(tab[y], "\tsub", 4) == 0 ||
	   my_str_nfirst_cmp(tab[y], "\tand", 4) == 0 ||
	   my_str_nfirst_cmp(tab[y], "\tor", 3) == 0 ||
	   my_str_nfirst_cmp(tab[y], "\txor", 4) == 0 ||
	   my_str_nfirst_cmp(tab[y], "\tzjmp", 5) == 0 ||
	   my_str_nfirst_cmp(tab[y], "\tldi", 4) == 0 ||
	   my_str_nfirst_cmp(tab[y], "\tsti", 4) == 0 ||
	   my_str_nfirst_cmp(tab[y], "\tfork", 5) == 0 ||
	   my_str_nfirst_cmp(tab[y], "\tlld", 4) == 0 ||
	   my_str_nfirst_cmp(tab[y], "\tlldi", 5) == 0 ||
	   my_str_nfirst_cmp(tab[y], "\tlfork", 6) == 0 ||
	   my_str_nfirst_cmp(tab[y], "\taff", 4) == 0)
    oct += 2;
  oct += nbr_oct_after_inst(y, tab);
  return (oct);
}

int	nbr_oct_after_inst(int y, char **tab)
{
  int	c;
  int	oct;

  c = 0;
  oct = 0;
  while (tab[y][c] != LABEL_CHAR && tab[y][c] != DIRECT_CHAR &&
	 tab[y][c] != 'r')
    c++;
  while (tab[y][c] != '\0' && tab[y][c] != '\n')
    {
      if (tab[y][c] == 'r' && tab[y][c + 1] >= 48 &&
	  tab[y][c + 1] <= REG_NUMBER)
	oct++;
      if (tab[y][c] == DIRECT_CHAR)
	oct += 4;
      if (tab[y][c] == SEPARATOR_CHAR &&
	  (tab[y][c + 1] == 'r' && tab[y][c + 2] >= 48 &&
	   tab[y][c + 2] < REG_NUMBER))
	oct++;
      if (tab[y][c] == SEPARATOR_CHAR && tab[y][c + 1] == DIRECT_CHAR)
	oct += 4;
      c++;
    }
  oct += nbr_oct_after_inst2(y, tab);
  return (oct);
}

int	nbr_oct_after_inst2(int	y, char **tab)
{
  int	c;
  int	oct;

  c = 0;
  oct = 0;
  while (tab[y][c] != LABEL_CHAR && tab[y][c] != DIRECT_CHAR &&
	 tab[y][c] != 'r')
    c++;
  while (tab[y][c] != '\0' && tab[y][c] != '\n')
    {
      if (tab[y][c] == LABEL_CHAR || (tab[y][c] >= 48 &&
				      tab[y][c] <= 58))
	oct += 2;
      if (tab[y][c] == SEPARATOR_CHAR &&
	  (tab[y][c + 1] == LABEL_CHAR || tab[y][c] >= 48 &&
	   tab[y][c] <= 58))
	oct += 2;
      c++;
    }
  return (oct);
}
