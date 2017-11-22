/*
** my_aff_chiffre.c for my_aff_chiffre in /home/RODRIG_1/rendu/Piscine_C_J03
** 
** Made by rodriguez gwendoline
** Login   <RODRIG_1@epitech.net>
** 
** Started on  Wed Oct  1 13:23:10 2014 rodriguez gwendoline
** Last update Fri Oct  3 09:02:29 2014 rodriguez gwendoline
*/

int	my_aff_chiffre()
{
  char chiffre;

  chiffre = 47;
  while (chiffre < 57)
    {
      chiffre++;
      my_putchar(chiffre);
    }
}
