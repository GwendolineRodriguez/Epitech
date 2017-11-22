/*
** 101pong.c for 101pong in /home/rodrig_1/rendu/101pong
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Mon Nov 10 18:10:19 2014 gwendoline rodriguez
** Last update Tue Nov 11 16:08:05 2014 gwendoline rodriguez
*/

#include <math.h>

int	speedvector(int	t1, int t2)
{
  int	cpt;

  cpt = t2 - t1;
  return (cpt);
}

void	incidence(int *t1, int *t2)
{
  double ang;

  ang = (180/3.14159265359)*atan((t2[2] - t1[2]) / sqrt(pow(t2[0] - t1[0], 2) + pow(t1[1] - t2[1], 2)));
  if (ang < 0)
    ang = ang * (-1);
  printf("L'angle d'incidence est de %.2f degrés.\n", ang);
}

void	pong(int *t1, int *t2, int n)
{
  int	tvit[3];

  my_putstr("Les coordonnées du vecteur vitesse sont ");
  my_putchar('(');
  my_put_nbr((tvit[0] = speedvector(t1[0], t2[0])));
  my_putchar(';');
  my_put_nbr((tvit[1] = speedvector(t1[1], t2[1])));
  my_putchar(';');
  my_put_nbr((tvit[2] = speedvector(t1[2], t2[2])));
  my_putstr(").");
  my_putchar('\n');
  my_putstr("A l'instant t+");
  my_put_nbr(n);
  my_putstr(", les coordonnées de la balle seront ");
  my_putchar('(');
  my_put_nbr(tvit[0] * n + t2[0]);
  my_putchar(';');
  my_put_nbr(tvit[1] * n + t2[1]);
  my_putchar(';');
  my_put_nbr(tvit[2] * n + t2[2]);
  my_putstr(").");
  my_putchar('\n');
  incidence(t1, t2);
}

int	main(int ac, char **av)
{
  int	t1[3];
  int	t2[3];
  int	n;
  int	i;

  if (ac == 8 && n > 0)
    {
      i = 0;
      n = my_getnbr(av[7]);
      while (i != 4)
	{
	  t1[i] = my_getnbr(av[i + 1]);
	  t2[i] = my_getnbr(av[i + 4]);
	  i = i + 1;
	}
      pong(t1, t2, n);
    }
  else
    write(2, "Usage : ./101pong  xt-1 yt-1 zt-1 xt yt zt n\n", 45);
  return (0);
}
