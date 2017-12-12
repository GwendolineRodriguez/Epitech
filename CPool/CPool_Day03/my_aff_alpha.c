/*
** my_aff_alpha.c for my_aff_alpha in /home/RODRIG_1/rendu/Piscine_C_J03
** 
** Made by rodriguez gwendoline
** Login   <RODRIG_1@epitech.net>
** 
** Started on  Wed Oct  1 09:23:53 2014 rodriguez gwendoline
** Last update Fri Oct  3 08:59:34 2014 rodriguez gwendoline
*/

int	my_aff_alpha()
{
  char	lettre;

  lettre = 96;
  while (lettre < 122)
    {
      lettre++;
      my_putchar(lettre);
    }
}
