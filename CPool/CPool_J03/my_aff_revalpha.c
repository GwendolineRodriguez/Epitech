/*
** my_aff_revalpha.c for my_aff_revalpha in /home/RODRIG_1/rendu/Piscine_C_J03
** 
** Made by rodriguez gwendoline
** Login   <RODRIG_1@epitech.net>
** 
** Started on  Wed Oct  1 13:12:59 2014 rodriguez gwendoline
** Last update Fri Oct  3 09:02:28 2014 rodriguez gwendoline
*/

int	my_aff_revalpha()
{
  char lettre;

  lettre = 123;
  while (lettre > 97)
    {
      lettre--;
      my_putchar(lettre);
    }
}
