/*
** derotation.c for RTV1$ in /home/dulin_m/rendu/MUL_2014_rtv1
**
** Made by maxime dulin
** Login   <dulin_m@epitech.net>
**
** Started on  Fri Mar 14 15:00:03 2014 maxime dulin
** Last update Fri Mar 14 15:14:35 2014 maxime dulin
*/

#include "rtv1.h"

int	derotat_x(t_gen *gen)
{
  float	al;

  al = -(ANG / PI) * 180;
  gen->pos.x1 = gen->pos.x1;
  gen->pos.y1 = gen->pos.y1 * cos(al) + gen->pos.z1 * sin(al);
  gen->pos.z1 = gen->pos.y1 * -sin(al) + gen->pos.z1 * cos(al);
  return (0);
}

int	derotat_y(t_gen *gen)
{
  float	al;

  al = (ANG / PI) * 180;
  gen->pos.x1 = gen->pos.x1 * cos(al) + gen->pos.z1 * sin(al);
  gen->pos.y1 = gen->pos.y1;
  gen->pos.z1 = gen->pos.x1 * -sin(al) + gen->pos.z1 * cos(al);
  return (0);
}

int	derotat_z(t_gen *gen)
{
  float	al;

  al = (ANG / PI) * 180;
  gen->pos.x1 = gen->pos.x1 * cos(al) + gen->pos.y1 * -sin(al);
  gen->pos.y1 = gen->pos.x1 * sin(al) + gen->pos.y1 * cos(al);
  gen->pos.z1 = gen->pos.z1;
  return (0);
}
