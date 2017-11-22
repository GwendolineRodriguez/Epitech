/*
** my_graph.c for my_graph in /home/rodrig_1/rendu/Igraph/MUL_2014_wolf3d
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Fri Dec 12 17:30:27 2014 gwendoline rodriguez
** Last update Mon Nov 13 15:29:19 2017 Gwendoline Rodriguez
*/

#include "header.h"

int		calc(int x, int y)
{
  t_vect	v;
  double	kp;
  double	ks;
  double	kc;

  kp = 0.f;
  ks = 0.f;
  kc = 0.f;
  v.Vx = 100;
  v.Vy = (WIDTH / 2) - x;
  v.Vz = (HEIGHT / 2) - y;
  kp = inter_plan(v);
  ks = inter_sphere(v);
  kc = inter_cylinder(v);
  if (kp >= 0.0001 && ((kp <= ks && kp <= kc) || (kp <= ks && kc == -1)
		       || (kp <= kc && ks == -1) || (ks == -1 && kc == -1)))
    return (light_plan(v, COLPLAN, kp));
  else if (ks >= 0.0001 && ((ks <= kp && ks <= kc) || (ks <= kp && kc == -1)
			    || (ks <= kc && kp == -1) ||
			    (kp == -1 && kc == -1)))
    return (light_spher(v, COLSPHER, ks));
  else if (kc >= 0.0001 && ((kc <= kp && kc <= ks) || (kc <= kp && ks == -1)
			    || (kc <= ks && kp == -1) ||
			    (kp == -1 && ks == -1)))
    return (light_cylinder(v, COLCYL, kc));
  return (0x000000);
}

void            loading(int nbline)
{
  int		percent;

  if (nbline == 0)
    puts("please wait...\n");
  percent = (nbline / WIDTH) * 100;
  printf("%d\n",percent);
  puts("%\n");
}

void		my_env(t_ptr *lx)
{
  int		x;
  int		y;

  x = 0;
  while (x != WIDTH)
    {
      loading(x);
      y = 0;
      while (y != HEIGHT)
	{
	  mlx_pixel_put_to_image(lx, x, y, calc(x, y));
	  y++;
	}
      x++;
    }
}
