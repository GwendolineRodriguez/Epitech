/*
** effect.c for effect in /home/rodrig_1/rendu/Igraph/MUL_2014_rtv1
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Thu Feb 26 15:19:57 2015 gwendoline rodriguez
** Last update Tue May 26 16:30:30 2015 
*/

#include "header.h"

int		hexa_to_rgb(int r, int g, int b)
{
  if (r > 255)
    r = 255;
  if (g > 255)
    g = 255;
  if (b > 255)
    b = 255;
  return (b * 256 * 256 + g * 256 + r);
}

int		light_plan(t_vect v, int color, int k)
{
  int		colorlum;

  v.Nx = 0;
  v.Ny = 0;
  v.Nz = 100;
  v.Lx = XSPOT - v.Vx + XPLAN;
  v.Ly = YSPOT - v.Vy + YPLAN;
  v.Lz = ZSPOT - v.Vz + ZPLAN;
  v.norm = sqrt(pow(v.Nx, 2) + pow(v.Ny, 2) + pow(v.Nz, 2));
  v.lum = sqrt(pow(v.Lx, 2) + pow(v.Ly, 2) + pow(v.Lz, 2));
  v.scal = (v.Nx * v.Lx) + (v.Ny * v.Ly) + (v.Nz * v.Lz);
  v.cosa = (v.scal / (v.lum * v.norm));
  color = color * (1 - BRILL) + COLSPOT * BRILL;
  if (k < 1 && k > 0)
    return (0);
  if (v.cosa <= 0.0001)
    return (0);
  if (v.cosa >= 1)
    v.cosa = 1;
  colorlum = hexa_to_rgb(v.cosa * (color & 0xFF),
			 v.cosa * ((color >> 8) & 0xFF),
			 v.cosa * ((color >> 16) & 0xFF));
  return (colorlum);
}

int		light_spher(t_vect v, int color, int k)
{
  int		colorlum;

  v.Nx = XEYE + k * (v.Vx + XSPHER);
  v.Ny = YEYE + k * (v.Vy + YSPHER);
  v.Nz = ZEYE + k * (v.Vz + ZSPHER);
  v.Lx = XSPOT - v.Nx;
  v.Ly = YSPOT - v.Ny;
  v.Lz = ZSPOT - v.Nz;
  v.norm = sqrt(pow(v.Nx, 2) + pow(v.Ny, 2) + pow(v.Nz, 2));
  v.lum = sqrt(pow(v.Lx, 2) + pow(v.Ly, 2) + pow(v.Lz, 2));
  v.scal = (v.Nx * v.Lx) + (v.Ny * v.Ly) + (v.Nz * v.Lz);
  v.cosa = (v.scal / (v.norm * v.lum));
  if (v.cosa <= 0.0001)
    return (0);
  if (v.cosa >= 1)
    v.cosa = 1;
  colorlum = hexa_to_rgb(v.cosa * (color & 0xFF),
			 v.cosa * ((color >> 8) & 0xFF),
			 v.cosa * ((color >> 16) & 0xFF));
  return (colorlum);
}

int             light_cylinder(t_vect v, int color, int k)
{
  int           colorlum;

  v.Nx = XEYE + k * (v.Vx + XCYL);
  v.Ny = YEYE + k * (v.Vy + YCYL);
  v.Nz = (0 + ZCYL);
  v.Lx = XSPOT - v.Nx;
  v.Ly = YSPOT - v.Ny;
  v.Lz = ZSPOT - v.Nz;
  v.norm = sqrt(pow(v.Nx, 2) + pow(v.Ny, 2) + pow(v.Nz, 2));
  v.lum = sqrt(pow(v.Lx, 2) + pow(v.Ly, 2) + pow(v.Lz, 2));
  v.scal = (v.Nx * v.Lx) + (v.Ny * v.Ly) + (v.Nz * v.Lz);
  v.cosa = (v.scal / (v.norm * v.lum));
  if (v.cosa <= 0.0001)
    return (0);
  if (v.cosa >= 1)
    v.cosa = 1;
  colorlum = hexa_to_rgb(v.cosa * (color & 0xFF),
			 v.cosa * ((color >> 8) & 0xFF),
			 v.cosa * ((color >> 16) & 0xFF));
  return (colorlum);
}
