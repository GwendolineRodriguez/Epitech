/*
** test.c for test in /home/RODRIG_1/rendu/Piscine_C_sapin
** 
** Made by rodriguez gwendoline
** Login   <RODRIG_1@epitech.net>
** 
** Started on  Sun Oct  5 15:48:33 2014 rodriguez gwendoline
** Last update Sun Oct  5 18:58:56 2014 rodriguez gwendoline
*/

int	my_putchar(char c)
{
  write(1, &c, 1);
}

int	space(int taille)
{
  int x;
  int n;

  x = taille;
  n = 4 * taille;
  while (x < n)
    {
      my_putchar(' ');
      x = x + 1;
    }
  my_putchar('*');
  my_putchar('\n');
  n = n - 1;
}

void	sapin(int taille)
{
  int n;

  n = 1;
  while (n <= 4)
    {
      space(taille);
      n = n + 1;
    }
}

int	main()
{
  sapin(1);
}
