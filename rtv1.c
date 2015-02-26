/*
** rtv1.c for MUL_2014_rtv1 in /home/dulin_m/rendu/MUL_2014_rtv1
**
** Made by maxime dulin
** Login   <dulin_m@epitech.net>
**
** Started on  Tue Feb  4 13:37:03 2014 maxime dulin
** Last update Thu Feb 20 16:51:22 2014 maxime dulin
*/

#include "rtv1.h"
#include "./My_lib/my.h"

int	gest_key(int key, t_gen *gen)
{
  gen = gen;
  if (key == 65307)
    exit(0);
  return (0);
}

int	gest_expose(t_gen *gen)
{
  mlx_put_image_to_window(gen->cord.mlx, gen->cord.win, gen->cord.img, 0, 0);
  mlx_do_sync(gen->cord.mlx);
  return (0);
}

int	main()
{
  t_gen	gen;

  if ((gen.cord.mlx = mlx_init()) == NULL)
    return (0);
  gen.cord.win = mlx_new_window(gen.cord.mlx, 1280, 720, "RTV1");
  gen.cord.img = mlx_new_image(gen.cord.mlx, 1280, 720);
  gen.pam.data = mlx_get_data_addr(gen.cord.img, &gen.pam.bpp,
				   &gen.pam.sizeline, &gen.pam.endian);
  mlx_put_image_to_window(gen.cord.mlx, gen.cord.win, gen.cord.img, 0, 0);
  mlx_do_sync(gen.cord.mlx);
  mlx_key_hook(gen.cord.win, gest_key, &gen);
  mlx_expose_hook(gen.cord.win, gest_expose, &gen);
  calc_gen(&gen);
  mlx_loop(gen.cord.mlx);
  mlx_destroy_window(gen.cord.mlx, gen.cord.win);
  return (0);
}
