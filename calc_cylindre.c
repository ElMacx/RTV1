/*
** calc_cylindre.c for RT in /home/dulin_m/rendu/MUL_2014_rtv1
**
** Made by maxime dulin
** Login   <dulin_m@epitech.net>
**
** Started on  Fri Feb 21 16:24:31 2014 maxime dulin
** Last update Sun Mar 16 17:42:37 2014 maxime dulin
*/

#include "rtv1.h"

int     calc_vect_cylindre(t_gen *gen)
{
  gen->cyl.vxc = gen->pos.x1;
  gen->cyl.vyc = gen->pos.y1;
  return (0);
}

int     check_k_cylindre(t_gen *gen)
{
  float tmp;

  gen->cyl.kc = ((-gen->del.b) - sqrt(gen->del.delta)) / (2 * gen->del.a);
  tmp = (-gen->del.b + sqrt(gen->del.delta)) / (2 * gen->del.a);
  if (tmp < gen->cyl.kc && tmp > MIN)
    gen->cyl.kc = tmp;
  if (gen->cyl.kc >= MIN)
    return (1);
  return (0);
}

int     calc_cylindre(t_gen *gen)
{
  gen->cyl.xc = -200;
  gen->cyl.rc = 50;
  gen->cyl.yc = 200;
  gen->cyl.zc = 0;
  calc_vect_cylindre(gen);
  gen->del.a = pow(gen->cyl.vxc, 2) + pow(gen->cyl.vyc, 2);
  gen->del.b = 2 * ((gen->pos.x0 - gen->cyl.xc) * gen->cyl.vxc +
		    (gen->pos.y0 - gen->cyl.yc) * gen->cyl.vyc);
  gen->del.c = pow((gen->pos.x0 - gen->cyl.xc), 2) +
    pow((gen->pos.y0 - gen->cyl.yc), 2) - pow(gen->cyl.rc, 2);
  gen->del.delta = pow(gen->del.b, 2) - 4 * gen->del.a * gen->del.c;
  if (gen->del.delta >= MIN)
    {
      if ((check_k_cylindre(gen)) == 1)
	return (1);
    }
  else
    gen->cyl.kc = 1000000;
  return (0);
}
