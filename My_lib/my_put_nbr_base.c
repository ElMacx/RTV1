/*
** my_put_nbr_base.c for my_put_nbr_base in /home/dulin_m/rendu/PSU_2013_my_printf
** 
** Made by maxime dulin
** Login   <dulin_m@epitech.net>
** 
** Started on  Mon Nov 25 16:54:44 2013 maxime dulin
** Last update Mon Nov 25 16:56:26 2013 maxime dulin
*/

int	my_put_nbr_base(long nb, char *base)
{
  int	ct_base;
  int	res;

  ct_base = my_strlen(base);
  if (nb == 0)
    return (0);
  res = nb - my_put_nbr_base(nb / ct_base, base) * ct_base;
  my_putchar(base[res]);
  return (nb);
}
