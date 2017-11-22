/*
** tp3_firstimage.c for tp3_fisrtimage in /home/RODRIG_1/rendu/Minilibx-TP.3
**
** Made by rodriguez gwendoline
** Login   <RODRIG_1@epitech.net>
**
** Started on  Thu Nov 13 10:09:32 2014 rodriguez gwendoline
** Last update Mon Nov 13 16:05:47 2017 Gwendoline Rodriguez
*/

#include "header.h"

void		mlx_pixel_put_to_image(t_ptr *lx, int x, int y, int color)
{
  int		i;

  i = x * (lx->bpp / 8) + y * lx->sizeline;
  lx->data[i] = (color & 0xFF);
  lx->data[i + 1] = (color & 0xFF00) >> 8;
  lx->data[i + 2] = (color & 0xFF0000) >> 16;
}

int		my_gere_expose(t_ptr *lx)
{
  mlx_put_image_to_window(lx->mlx_ptr, lx->win_ptr, lx->img, 0, 0);
  return (0);
}

int		gere_key(int keycode)
{
  if (keycode == 65307)
    exit(0);
  printf("%d\n",keycode);
  putchar('\n');
  return (0);
}

int		main()
{
  t_ptr		lx;

  lx.mlx_ptr = mlx_init();
  lx.win_ptr = mlx_new_window(lx.mlx_ptr, WIDTH, HEIGHT, "Raytracer");
  lx.img = mlx_new_image(lx.mlx_ptr, WIDTH, HEIGHT);
  lx.data = mlx_get_data_addr(lx.img, &lx.bpp, &lx.sizeline, &lx.endian);
  mlx_expose_hook(lx.win_ptr, my_gere_expose, &lx);
  my_env(&lx);
  mlx_key_hook(lx.win_ptr, &gere_key, &lx);
  mlx_put_image_to_window(lx.mlx_ptr, lx.win_ptr, lx.img, 0, 0);
  mlx_loop(lx.mlx_ptr);
  return (0);
}
