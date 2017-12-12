/*
** colle.c for Piscine Colle 01 in /home/tatibo_c/rendu/Piscine_C_colles-Semaine_01
** 
** Made by Charles Tatibouet
** Login   <tatibo_c@epitech.net>
** 
** Started on  Sat Oct  4 14:57:45 2014 Charles Tatibouet
** Last update Sat Oct  4 18:41:54 2014 Charles Tatibouet
*/

int	mini_droite1(int largeur, int hauteur)
{
  if (hauteur == 1 && largeur > 1)
    {
      afficher_caractere('o', 1);
      afficher_caractere('-', largeur - 2);
      afficher_caractere('o', 1);
    }
  if (largeur == 1)
    {
      if (hauteur != 1)
	{
	  afficher_caractere('o', 1);
	  afficher_caractere('\n', 1);
	  while (hauteur > 2)
	    {
	      afficher_caractere('|', 1);
	      afficher_caractere('\n', 1);
	      hauteur = hauteur - 1;
	    }
	  afficher_caractere('o', 1);
	}
    }
  if (hauteur == 1 && largeur == 1)
    afficher_caractere('o', 1);
  afficher_caractere('\n', 1);
}

int	colle1(int largeur, int hauteur)
{
  if (largeur == 1 || hauteur == 1)
    mini_droite(largeur, hauteur);
  else
    {
      if (largeur > 0 && hauteur > 0)
	{
	  afficher_ligne(largeur, 'o', '-', 'o');
	  while (hauteur > 2)
	    {
	      if (largeur == 1)
		afficher_ligne(largeur, 0, '|', 0);
	      if (largeur == 2)
		afficher_ligne(largeur, '|', 0, '|');
	      else
		{
		  afficher_ligne(largeur, '|', ' ', '|');
		}
	      hauteur = hauteur - 1;
	    }
	  afficher_ligne(largeur, 'o', '-', 'o');
	}
    }
  return (0);
}
