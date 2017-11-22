/*
** struct.h for structs in /home/rodrig_1/rendu/Igraph/MUL_2014_wolf3d
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Wed Dec 10 16:10:31 2014 gwendoline rodriguez
** Last update Mon Nov 13 15:00:36 2017 Gwendoline Rodriguez
*/

#ifndef _STRUCTS_
#define _STRUCTS_

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "./lib/my/my.h"
#include "./lib/mlx/mlx.h"

#define HEIGHT 800
#define WIDTH 1200
#define BRILL 0
#define COLSPOT 0xFEFDF0
#define COLPLAN 0xFEFDF0
#define COLSPHER 0xFF005D
#define COLCYL 0x14A8CC
#define COLCONE 0xFFEB19
#define XEYE -300
#define YEYE 10
#define ZEYE 20
#define XSPOT -300
#define YSPOT -200
#define ZSPOT 50
#define XSPHER 0
#define YSPHER 0
#define ZSPHER -200
#define XPLAN 0
#define YPLAN 0
#define ZPLAN 0
#define XCYL 0
#define YCYL 0
#define ZCYL 0
#define XCONE 0
#define YCONE 0
#define ZCONE 0

typedef struct	s_ptr
{
  void		*mlx_ptr;
  void		*win_ptr;
  void		*img;
  char		*data;
  int		bpp;
  int		endian;
  int		sizeline;
}		t_ptr;

typedef struct  s_vect
{
  double        Vx;
  double        Vy;
  double        Vz;
  double        Nx;
  double        Ny;
  double        Nz;
  double	Lx;
  double	Ly;
  double	Lz;
  double	Epx;
  double	Epy;
  double	Epz;
  double        scal;
  double        norm;
  double        lum;
  double        cosa;
}               t_vect;

typedef struct  s_equation
{
  double        a;
  double        b;
  double        c;
  double	R;
  double	delta;
  double	kt[2];
  double	k;
}               t_equation;

void            mlx_pixel_put_to_image(t_ptr *lx, int x, int y, int color);
int             my_gere_expose(t_ptr *lx);
int             gere_key(int keycode);
int             calc(int x, int y);
void            loading(int nbline);
void            my_env(t_ptr *lx);
double          inter_sphere(t_vect v);
double          inter_plan(t_vect v);
double		inter_cylinder(t_vect v);
double          inter_cone(t_vect v);
int		hexa_to_rgb(int r, int g, int b);
int		light_spher(t_vect v, int color, int k);
int             light_plan(t_vect v, int color, int k);
int		light_cylinder(t_vect v, int color, int k);

#endif /* !_STRUCT_ */
