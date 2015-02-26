/*
** my_swap.c for my_swap in /home/dulin_m/rendu/Piscine-C-lib/my
** 
** Made by maxime dulin
** Login   <dulin_m@epitech.net>
** 
** Started on  Tue Oct  8 21:56:55 2013 maxime dulin
** Last update Sun Nov 17 16:10:04 2013 maxime dulin
*/

int	my_swap (int *a, int *b)
{
  int	transition;

  transition = *b;
  *b = *a;
  *a = transition;
}
