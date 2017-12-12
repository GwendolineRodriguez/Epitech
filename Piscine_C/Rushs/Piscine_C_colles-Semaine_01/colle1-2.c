/*
** colle.c for Piscine Colle 01 in /home/tatibo_c/rendu/Piscine_C_colles-Semaine_01
** 
** Made by Charles Tatibouet
** Login   <tatibo_c@epitech.net>
** 
** Started on  Sat Oct  4 14:57:45 2014 Charles Tatibouet
** Last update Sat Oct 25 22:23:49 2014 rodriguez gwendoline
*/

int	afficher_caractere(char c, int nb)
{
  while (nb > 0)
    {
      my_putchar(c);
      nb = nb - 1;
    }
}

int	mini_droite(int largeur, int hauteur)
{
  if (hauteur == 1)
    {
      afficher_caractere('*', largeur);
      afficher_caractere('\n', 1);
    }
  if (largeur == 1)
    {
      if (hauteur != 1)
	{
	  while (hauteur > 0)
	    {
	      afficher_caractere('*', 1);
	      afficher_caractere('\n', 1);
	      hauteur = hauteur - 1;
	    }
	}
    }
}

int	afficher_ligne(int largeur, char gauche, char milieu, char droite)
{
  if (largeur == 2)
    {
      afficher_caractere(gauche, 1);
      afficher_caractere(droite, 1);
    }
  if (largeur > 2)
    {
      afficher_caractere(gauche, 1);
      afficher_caractere(milieu, largeur - 2);
      afficher_caractere(droite, 1);
    }
  afficher_caractere('\n', 1  return (0);
}

int	colle(int largeur, int hauteur)
{
  if (largeur == 1 || hauteur == 1)
    mini_droite(largeur, hauteur);
  else
    {
      if (largeur > 0 && hauteur > 0)
	{
	  afficher_ligne(largeur, '/', '*', '\\');
	  while (hauteur > 2)
	    {
	      if (largeur == 1)
		afficher_ligne(largeur, 0, '*', 0);
	      if (largeur == 2)
		afficher_ligne(largeur, '*', 0, '*');
	      else
		{
		  afficher_ligne(largeur, '*', ' ', '*');
		}
	      hauteur = hauteur - 1;
	    }
	  afficher_ligne(largeur, '\\', '*', '/');
	}
    }
}
