/*
** shadow.c for RTV1 in /home/dulin_m/rendu/MUL_2014_rtv1
**
** Made by maxime dulin
** Login   <dulin_m@epitech.net>
**
** Started on  Sat Mar 15 14:55:08 2014 maxime dulin
** Last update Sat Mar 15 17:17:43 2014 maxime dulin
*/

int	set_new_pt(t_gen *gen)
{
  if (gen->pos.object == 3)
    {
      gen->lum.xpi = gen->pos.xpi + gen->cone.k * gen->lum.vlx;
      gen->lum.ypi = gen->pos.ypi + gen->cone.k * gen->lum.vly;
      gen->lum.zpi = gen->pos.zpi + gen->cone.k * gen->lum.vlz;
    }
  if (gen->pos.object == 2)
    {
      gen->lum.xpi = gen->pos.xpi + gen->cyl.kc * gen->lum.vlx;
      gen->lum.ypi = gen->pos.ypi + gen->cyl.kc * gen->lum.vly;
      gen->lum.zpi = gen->pos.zpi + gen->cyl.kc * gen->lum.vlz;
    }
  if (gen->pos.object == 1)
    {
      gen->lum.xpi = gen->pos.xpi + gen->pos.k * gen->lum.vlx;
      gen->lum.ypi = gen->pos.ypi + gen->pos.k * gen->lum.vly;
      gen->lum.zpi = gen->pos.zpi + gen->pos.k * gen->lum.vlz;
    }
  if (gen->pos.object == 0)
    {
      gen->lum.xpi = gen->pos.xpi + gen->pos.kp * gen->lum.vlx;
      gen->lum.ypi = gen->pos.ypi + gen->pos.kp * gen->lum.vly;
      gen->lum.zpi = gen->pos.zpi + gen->pos.kp * gen->lum.vlz;
    }
  return (0);
}

int	my_shadow(t_gen *gen)
{
  lum_vect(gen);
  set_new_pt(gen);
  return (0);
}
