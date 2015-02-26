/*
** my_power_rec.c for my_power_rec in /home/dulin_m/rendu/Piscine-C-lib/my
** 
** Made by maxime dulin
** Login   <dulin_m@epitech.net>
** 
** Started on  Tue Oct  8 22:03:12 2013 maxime dulin
** Last update Tue Oct  8 22:04:38 2013 maxime dulin
*/

int	my_power_rec(int nb, int power)
{
  if (power < 0)
    {
      return (0);
    }
  else
    {
      if (power > 1)
	{
	  nb = my_power_rec (nb, power - 1);
	  nb = nb * nb;
	}
      return (nb);
    }
}
