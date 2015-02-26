/*
** calc_cone.c for RTV1 in /home/dulin_m/rendu/MUL_2014_rtv1
**
** Made by maxime dulin
** Login   <dulin_m@epitech.net>
**
** Started on  Wed Mar 12 15:17:21 2014 maxime dulin
** Last update Sun Mar 16 17:43:11 2014 maxime dulin
*/

#include "rtv1.h"

int     calc_vect_cone(t_gen *gen)
{
  gen->cone.vx = gen->pos.x1;
  gen->cone.vy = gen->pos.y1;
  gen->cone.vz = gen->pos.z1;
  return (0);
}

int     check_k_cone(t_gen *gen)
{
  float tmp;

  gen->cone.k = ((-gen->del.b) - sqrt(gen->del.delta)) / (2 * gen->del.a);
  tmp = (-gen->del.b + sqrt(gen->del.delta)) / (2 * gen->del.a);
  if (tmp < gen->cone.k && tmp > MIN)
    gen->cone.k = tmp;
  if (gen->cone.k >= MIN)
    return (1);
  return (0);
}

int     calc_cone(t_gen *gen)
{
  gen->cone.x = 0;
  gen->cone.y = -200;
  gen->cone.z = 50;
  gen->cone.alpha = 60;
  calc_vect_cone(gen);
  gen->cone.tana = pow((tan(gen->cone.alpha * PI / 180)), 2);
  gen->del.a = pow(gen->cone.vx, 2) + pow(gen->cone.vy, 2)
    - (pow(gen->cone.vz, 2) / gen->cone.tana);
  gen->del.b = 2 * ((gen->pos.x0 - gen->cone.x) * gen->cone.vx +
		    (gen->pos.y0 - gen->cone.y) * gen->cone.vy)
    - (gen->cone.vz / gen->cone.tana);
  gen->del.c = pow((gen->pos.x0 - gen->cone.x), 2) +
    pow((gen->pos.y0 - gen->cone.y), 2) - (gen->pos.z0 / gen->cone.tana);
  gen->del.delta = pow(gen->del.b, 2) - 4 * gen->del.a * gen->del.c;
  if (gen->del.delta >= MIN)
    {
      if ((check_k_cone(gen)) == 1)
	return (1);
    }
  else
    gen->cone.k = 1000000;
  return (0);
}
