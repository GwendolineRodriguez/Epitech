/*
** volumes.c for volumes in /home/rodrig_1/rendu/Igraph/MUL_2014_rtv1
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Mon Feb 23 14:28:10 2015 gwendoline rodriguez
** Last update Tue May 26 16:26:08 2015 
*/

#include "header.h"

double          inter_sphere(t_vect v)
{
  t_equation    eq;

  eq.R = 200;
  eq.a = pow((v.Vx + XSPHER), 2) + pow((v.Vy + YSPHER), 2)
    + pow((v.Vz + ZSPHER), 2);
  eq.b = 2 * ((XEYE * (v.Vx + XSPHER)) + (YEYE * (v.Vy + XSPHER))
	      + (ZEYE * (v.Vz + ZSPHER)));
  eq.c = pow(XEYE, 2) + pow(YEYE, 2) + pow(ZEYE, 2) - pow(eq.R, 2);
  eq.delta = pow(eq.b, 2) - 4 * (eq.a * eq.c);
  eq.k = -1.0;
  if (eq.delta >= 0)
    {
      if ((eq.kt[0] = (-eq.b - sqrt(eq.delta)) / (2 * eq.a)) < 0.0001)
	eq.kt[0] = -1;
      if ((eq.kt[1] = (-eq.b + sqrt(eq.delta)) / (2 * eq.a)) < 0.0001)
	eq.kt[1] = -1;
      if (eq.kt[0] > eq.kt[1])
	eq.k = eq.kt[1];
      else
	eq.k = eq.kt[0];
    }
  return (eq.k);
}

double		inter_plan(t_vect v)
{
  double	k;

  k = 0.f;
  k = - (ZEYE / (v.Vz + ZPLAN));
  if (k <= 0.0001 || fabs(v.Vz + ZPLAN) <= 0.0001)
    return (-1);
  return (k);
}

double		inter_cylinder(t_vect v)
{
  t_equation    eq;

  eq.R = 100;
  eq.a = pow((v.Vx + XCYL), 2) + pow((v.Vy + YCYL), 2);
  eq.b = (2 * XEYE * (XCYL + v.Vx)) + (2 * YEYE * (YCYL + v.Vy));
  eq.c = pow(XEYE, 2) + pow(YEYE, 2) - pow(eq.R, 2);
  eq.delta = pow(eq.b, 2) - 4 * (eq.a * eq.c);
  eq.k = -1.0;
  if (eq.delta >= 0)
    {
      if ((eq.kt[0] = (-eq.b - sqrt(eq.delta)) / (2 * eq.a)) < 0.0001)
	eq.kt[0] = -1;
      if ((eq.kt[1] = (-eq.b + sqrt(eq.delta)) / (2 * eq.a)) < 0.0001)
	eq.kt[1] = -1;
      if (eq.kt[0] > eq.kt[1])
	eq.k = eq.kt[1];
      else
	eq.k = eq.kt[0];
    }
  return (eq.k);
}

double          inter_cone(t_vect v)
{
  t_equation    eq;
  double	ang;

  ang = 180;
  ang = (ang * M_PI) / 180;
  eq.a = pow((v.Vx + XCONE), 2) + pow((v.Vy + YCONE), 2)
    - (pow((v.Vz + ZCONE), 2) / pow(tan(ang), 2));
  eq.b = (2 * XEYE * (XCONE + v.Vx)) + (2 * YEYE * (YCONE + v.Vy))
    - (2 * ZEYE * (ZCONE + v.Vz) / pow(tan(ang), 2));
  eq.c = pow(XEYE, 2) + pow(YEYE, 2) - pow(ZEYE, 2) / pow(tan(ang), 2);
  eq.delta = pow(eq.b, 2) - 4 * (eq.a * eq.c);
  eq.k = -1.0;
  if (eq.delta >= 0)
    {
      if ((eq.kt[0] = (-eq.b - sqrt(eq.delta)) / (2 * eq.a)) < 0.0001)
	eq.kt[0] = -1;
      if ((eq.kt[1] = (-eq.b + sqrt(eq.delta)) / (2 * eq.a)) < 0.0001)
	eq.kt[1] = -1;
      if (eq.kt[0] > eq.kt[1])
	eq.k = eq.kt[1];
      else
	eq.k = eq.kt[0];
    }
  return (eq.k);
}
