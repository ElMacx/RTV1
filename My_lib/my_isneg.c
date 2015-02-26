/*
** my_isneg.c for my_isneg in /home/dulin_m/rendu/Piscine-C-lib/my
** 
** Made by maxime dulin
** Login   <dulin_m@epitech.net>
** 
** Started on  Tue Oct  8 21:54:18 2013 maxime dulin
** Last update Tue Oct  8 21:55:15 2013 maxime dulin
*/

int	my_isneg(int n)
{
  if (n < 0)
    {
      my_putchar ('N');
    }
  else
    {
      my_putchar ('P');
    }
}
