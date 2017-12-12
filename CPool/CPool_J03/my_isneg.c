/*
** my_isneg.c for my_isneg in /home/RODRIG_1/rendu/Piscine_C_J03
** 
** Made by rodriguez gwendoline
** Login   <RODRIG_1@epitech.net>
** 
** Started on  Wed Oct  1 13:39:59 2014 rodriguez gwendoline
** Last update Fri Oct  3 09:02:25 2014 rodriguez gwendoline
*/

int	my_isneg(int n)
{
  int	positif;
  int	negatif;

  positif = 80;
  negatif = 78;
  if (n >= 0)
    {
      my_putchar(positif);
    }

  else if (n < 0)
    {
      my_putchar(negatif);
    }
}
