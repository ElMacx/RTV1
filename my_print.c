/*
** my_print.c for RT in /home/dulin_m/rendu/MUL_2014_rtv1
**
** Made by maxime dulin
** Login   <dulin_m@epitech.net>
**
** Started on  Wed Feb 19 17:06:37 2014 maxime dulin
** Last update Thu Mar 13 13:40:04 2014 maxime dulin
*/

#include "rtv1.h"

int	print_form(t_gen *gen, int xb, int yb)
{
  int	i;

  my_color(gen);
  i = gen->pam.sizeline * yb + 4 * xb;
  gen->pam.data[i] = gen->pos.color[0];
  gen->pam.data[i + 1] = gen->pos.color[1];
  gen->pam.data[i + 2] = gen->pos.color[2];
  gen->pam.data[i + 3] = 0;
  return (0);
}
