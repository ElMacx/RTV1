/*
** rtv1.h for MUL_2014_rtv1 in /home/dulin_m/rendu/MUL_2014_rtv1
**
** Made by maxime dulin
** Login   <dulin_m@epitech.net>
**
** Started on  Tue Feb  4 13:37:43 2014 maxime dulin
** Last update Sun Mar 16 16:27:02 2014 maxime dulin
*/

#ifndef __RTV1_H__
# define __RTV1_H__

/*
** ------ DEFINES ------
*/

# define MIN 0.000001
# define PI 3.14159265359
# define ANG 20

/*
** ------ INCLUDES ------
*/

#include <stdlib.h>
#include <unistd.h>
#include <mlx.h>
#include <stdio.h>
#include <math.h>

/*
** ------- SRTUCTURES -------
*/

typedef struct	s_cord
{
  void		*mlx;
  void		*win;
  void		*img;
}		t_cord;

typedef struct	s_param
{
  int		bpp;
  char		*data;
  int		sizeline;
  int		endian;
}		t_param;

typedef struct	s_pos
{
  float		x0;
  float		y0;
  float		z0;
  float		x1;
  float		y1;
  float		z1;
  float		vx;
  float		vy;
  float		vz;
  float		xpi;
  float		ypi;
  float		zpi;
  float		r;
  float		k;
  int		color[4];
  int		object;
  float		kp;
}		t_pos;

typedef struct	s_lum
{
  float		xs;
  float		ys;
  float		zs;
  float		vlx;
  float		vly;
  float		vlz;
  float		xn;
  float		yn;
  float		zn;
  float		xpi;
  float		ypi;
  float		zpi;
}		t_lum;

typedef struct	s_del
{
  float		cosa;
  float		delta;
  float		a;
  float		b;
  float		c;
}		t_del;

typedef struct	s_cyl
{
  float		xc;
  float		yc;
  float		zc;
  float		vxc;
  float		vyc;
  float		vzc;
  float		rc;
  float		kc;
}		t_cyl;

typedef struct	s_cone
{
  float		k;
  float		x;
  float		y;
  float		z;
  float		vx;
  float		vz;
  float		vy;
  float		tana;
  float		alpha;
}		t_cone;

typedef struct	s_sphe
{
  float		x;
  float		y;
  float		z;
}		t_sphe;

typedef struct	s_gen
{
  t_cord	cord;
  t_del		del;
  t_cyl		cyl;
  t_cone	cone;
  t_lum		lum;
  t_param	pam;
  t_pos		pos;
  t_sphe	sphe;
}		t_gen;

/*
** ------- PROTOTYPES -------
*/


/*
** rtv1.c
*/

int	gest_key(int , t_gen *);
int	gest_expose(t_gen *);
int	main();

/*
** calc_cerlce.c
*/

int	calc_gen(t_gen *);
int	calc_vect(t_gen *);
int	check_k(t_gen *);
int	check_delta(t_gen *);
int	resolv_k(t_gen *);

/*
** my_color.c
*/

int	my_color(t_gen *);
int	luminosity(t_gen *, int, int);
int	set_norm(t_gen *);
int	lum_vect(t_gen *);

/*
** my_print.c
*/

int	print_form(t_gen *, int, int);

/*
** calc_plan.c
*/

int	calc_plan(t_gen *);
void	initialize(t_gen *);
void	set_object(t_gen *);

/*
** calc_cylindre.c
*/

int	calc_cylindre(t_gen *);
int	check_k_cylindre(t_gen *);
int	calc_vect_cylindre(t_gen *);

/*
** calc_cone.c
*/

int     calc_vect_cone(t_gen *gen);
int     check_k_cone(t_gen *gen);
int     calc_cone(t_gen *gen);

/*
** rotation.c
*/

int     rotate_x(t_gen *gen);
int     rotate_y(t_gen *gen);
int     rotate_z(t_gen *gen);

/*
** ne derotation.c
*/

int     derotat_x(t_gen *gen);
int     derotat_y(t_gen *gen);
int     derotat_z(t_gen *gen);

#endif
