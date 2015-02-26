/*
** my_color.c for RT in /home/dulin_m/rendu/MUL_2014_rtv1
**
** Made by maxime dulin
** Login   <dulin_m@epitech.net>
**
** Started on  Wed Feb 19 16:49:05 2014 maxime dulin
** Last update Sun Mar 16 16:39:16 2014 maxime dulin
*/

#include "rtv1.h"

int	lum_vect(t_gen *gen)
{
  gen->lum.vlx = gen->lum.xs - gen->pos.xpi;
  gen->lum.vly = gen->lum.ys - gen->pos.ypi;
  gen->lum.vlz = gen->lum.zs - gen->pos.zpi;
  return (0);
}

int	luminosity(t_gen *gen, int xb, int yb)
{
  xb = xb;
  yb = yb;
  gen->lum.xs = -1000;
  gen->lum.ys = 0;
  gen->lum.zs = 200;
  lum_vect(gen);
  set_norm(gen);
  gen->del.cosa = (gen->lum.xn * gen->lum.vlx + gen->lum.yn * gen->lum.vly
		   + gen->lum.zn * gen->lum.vlz) / (sqrt(pow(gen->lum.xn, 2) +
					      pow(gen->lum.yn, 2) +
					      pow(gen->lum.zn, 2)) *
					 sqrt(pow(gen->lum.vlx, 2) +
					      pow(gen->lum.vly, 2) +
					      pow(gen->lum.vlz, 2)));
  if (gen->del.cosa >= 0.f && gen->del.cosa <= 1.f)
    print_form(gen, xb, yb);
  else
    gen->del.cosa = 0;
  return (0);
}

int	set_norm(t_gen *gen)
{
  if (gen->pos.object == 0)
    {
      gen->lum.xn = 0;
      gen->lum.yn = 0;
      gen->lum.zn = 100;
    }
  else if (gen->pos.object == 1)
    {
      gen->lum.xn = gen->pos.xpi;
      gen->lum.yn = gen->pos.ypi;
      gen->lum.zn = gen->pos.zpi;
    }
  else if (gen->pos.object == 2)
    {
      gen->lum.xn = gen->pos.xpi;
      gen->lum.yn = gen->pos.ypi;
      gen->lum.zn = 0;
    }
  else if (gen->pos.object == 3)
    {
      gen->lum.xn = gen->pos.xpi;
      gen->lum.yn = gen->pos.ypi;
      gen->lum.zn = -(gen->cone.alpha * PI / 180) * gen->pos.zpi;
    }
  return (0);
}

int	my_color(t_gen *gen)
{
  int	color;

  if (gen->pos.object == 0)
    color = 0x0033FF;
  else if (gen->pos.object == 1)
    color = 0xFF33FF;
  else if (gen->pos.object == 2)
    color = 0xFF0055;
  else if (gen->pos.object == -1)
    color = 0x000000;
  else if (gen->pos.object == 3)
    color = 0x99FF33;
  gen->pos.color[0] = color / pow(16, 4);
  color -= gen->pos.color[0] * pow(16, 4);
  gen->pos.color[1] = color / (16 * 16);
  color -= gen->pos.color[1] * pow(16, 2);
  gen->pos.color[2] = color;
  gen->pos.color[3] = -1;
  gen->pos.color[0] *= gen->del.cosa;
  gen->pos.color[1] *= gen->del.cosa;
  gen->pos.color[2] *= gen->del.cosa;
  return (0);
}
