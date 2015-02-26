/*
** calc_plan.c for RT in /home/dulin_m/rendu/MUL_2014_rtv1
**
** Made by maxime dulin
** Login   <dulin_m@epitech.net>
**
** Started on  Wed Feb 19 20:15:03 2014 maxime dulin
** Last update Sun Mar 16 18:10:35 2014 maxime dulin
*/

#include "rtv1.h"

void	initialize(t_gen *gen)
{
  gen->pos.r = 100;
  gen->pos.x0 = -1100;
  gen->pos.y0 = 0;
  gen->pos.z0 = 0;
  gen->pos.x1 = 1100;
  gen->sphe.x = 0;
  gen->sphe.y = 0;
  gen->sphe.z = 0;
}

void	set_object(t_gen *gen)
{
  if (gen->pos.k < gen->pos.kp && gen->pos.k < gen->cyl.kc
      && gen->pos.k < gen->cone.k && gen->pos.k != 1000000)
    gen->pos.object = 1;
  else if (gen->cyl.kc < gen->pos.kp && gen->cyl.kc < gen->pos.k
  	   && gen->cyl.kc < gen->cone.k && gen->cyl.kc != 1000000)
    gen->pos.object = 2;
  else if (gen->cone.k < gen->pos.kp && gen->cone.k < gen->pos.k
  	   && gen->cone.k < gen->cyl.kc && gen->cone.k != 1000000)
    gen->pos.object = 3;
  else if (gen->pos.kp < gen->cyl.kc && gen->pos.kp < gen->cyl.kc
  	   && gen->pos.kp < gen->cone.k && gen->pos.kp != 1000000)
    gen->pos.object = 0;
}

int	calc_plan(t_gen *gen)
{
  gen->pos.kp = -(100 / gen->pos.vz);
  if (gen->pos.kp > MIN)
    return (1);
  else
    gen->pos.kp = 1000000;
  return (0);
}
