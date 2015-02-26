/*
** calc_cercle.c for MUL_2014_rtv1 in /home/dulin_m/rendu/MUL_2014_rtv1
**
** Made by maxime dulin
** Login   <dulin_m@epitech.net>
**
** Started on  Tue Feb 11 09:32:51 2014 maxime dulin
** Last update Sun Mar 16 16:30:23 2014 maxime dulin
*/

#include "rtv1.h"

int	calc_vect(t_gen *gen)
{
  gen->pos.vx = gen->pos.x1;
  gen->pos.vy = gen->pos.y1;
  gen->pos.vz = gen->pos.z1;
  return (0);
}

int	check_k(t_gen *gen)
{
  float tmp;

  gen->pos.k = ((-gen->del.b) - sqrt(gen->del.delta)) / (2 * gen->del.a);
  tmp = (-gen->del.b + sqrt(gen->del.delta)) / (2 * gen->del.a);
  if (tmp < gen->pos.k && tmp > MIN)
    gen->pos.k = tmp;
  if (gen->pos.k > MIN)
    return (1);
  return (0);
}

int	check_delta(t_gen *gen)
{
  gen->del.a = pow(gen->pos.vx, 2) + pow(gen->pos.vy, 2) + pow(gen->pos.vz, 2);
  gen->del.b = 2 * ((gen->pos.x0 + gen->sphe.x) * gen->pos.vx
		    + (gen->pos.y0 + gen->sphe.y)* gen->pos.vy +
		    (gen->pos.z0 + gen->sphe.z) * gen->pos.vz);
  gen->del.c = pow(gen->pos.x0, 2) + pow(gen->pos.y0, 2)
    + pow(gen->pos.z0, 2) - pow(gen->pos.r, 2);
  gen->del.delta = pow(gen->del.b, 2) - 4 * gen->del.a * gen->del.c;
  if (gen->del.delta >= MIN)
    {
      if ((check_k(gen)) == 1)
	return (1);
    }
  else
    gen->pos.k = 1000000;
  return (0);
}

int	resolv_k(t_gen *gen)
{
  if (gen->pos.object == 1)
    {
      gen->pos.xpi = (gen->pos.x0 + gen->sphe.x) + gen->pos.k * gen->pos.vx;
      gen->pos.ypi = (gen->pos.y0 + gen->sphe.y) + gen->pos.k * gen->pos.vy;
      gen->pos.zpi = (gen->pos.z0 + gen->sphe.z) + gen->pos.k * gen->pos.vz;
    }
  else if (gen->pos.object == 0)
    {
      gen->pos.xpi = gen->pos.x0 + gen->pos.kp * gen->pos.vx;
      gen->pos.ypi = gen->pos.y0 + gen->pos.kp * gen->pos.vy;
      gen->pos.zpi = gen->pos.z0 + gen->pos.kp * gen->pos.vz;
    }
  else if (gen->pos.object == 2)
    {
      gen->pos.xpi = (gen->pos.x0 - gen->cyl.xc) + gen->cyl.kc * gen->cyl.vxc;
      gen->pos.ypi = (gen->pos.y0 - gen->cyl.yc)+ gen->cyl.kc * gen->cyl.vyc;
      gen->pos.zpi = (gen->pos.z0 - gen->cyl.zc) + gen->cyl.kc * gen->cyl.vzc;
    }
  else if (gen->pos.object == 3)
    {
      gen->pos.xpi = (gen->pos.x0 - gen->cone.x) + gen->cone.k * gen->cone.vx;
      gen->pos.ypi = (gen->pos.y0 - gen->cone.y) + gen->cone.k * gen->cone.vy;
      gen->pos.zpi = (gen->pos.z0 - gen->cone.z) + gen->cone.k * gen->cone.vz;
    }
  return (0);
}

int	calc_gen(t_gen *gen)
{
  int	xb;
  int	yb;

  yb = 0;
  initialize(gen);
  while (yb++ <= 720)
    {
      xb = 0;
      while (xb++ <= 1280)
	{
	  gen->pos.z1 = 720 / 2 - yb;
	  gen->pos.y1 = 1280 / 2 - xb;
	  calc_vect(gen);
	  if ((check_delta(gen)) == 1 || (calc_plan(gen)) == 1
	      || calc_cylindre(gen) == 1 || calc_cone(gen) == 1)
	    {
	      set_object(gen);
	      resolv_k(gen);
	      luminosity(gen, xb, yb);
	    }
	}
    }
  return (0);
}
