/*
** sapin.c for sapin in /home/RODRIG_1/rendu/Piscine_C_sapin
** 
** Made by rodriguez gwendoline
** Login   <RODRIG_1@epitech.net>
** 
** Started on  Sat Oct  4 19:02:41 2014 rodriguez gwendoline
** Last update Sun Oct  5 18:22:06 2014 rodriguez gwendoline
*/

int     character(char c,int n, int taille)
{
  while (n <= taille)
    {
      n * my_putchar(c);
      n = n + 1;
      //my_putchar(c);
    }
  //my_putchar(c);
  my_putchar('\n');
}

xint	branch(int length)
{
  while (length > 0)
    {
    character('*', length);
    character('\n', length);
    length = length - 1;
  while (length > 0)
    {	  
      character('*', length);
      character('\n', length);
      length = length - 1;
    }
}

int	show_line(int line, int charact)
  {
  if (line > 2)
  {
  character(charact, 1);
  }
  character('\n', 1);
  return (0);
  }

/*int	branch(int length, int n)
{
  while (n < length)
    {
      character('*', 1, length);
      n = n + 1;
    }
}
*/
void	sapin(int taille)
{
  if (taille > 0)
    {
      show_line(taille, '*');
      while (taille > 2)
	{
	  show_line(taille, '*');
	  taille = taille - 1;
	}
      show_line(taille, '*');
    }
  branch(taille, 0);
}
