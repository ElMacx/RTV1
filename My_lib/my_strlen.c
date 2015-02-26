/*
** my_strlen.c for my_strlen in /home/dulin_m/rendu/Piscine-C-lib/my
** 
** Made by maxime dulin
** Login   <dulin_m@epitech.net>
** 
** Started on  Tue Oct  8 22:00:14 2013 maxime dulin
** Last update Tue Oct  8 22:01:06 2013 maxime dulin
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str [i] != 0)
    {
      i = i + 1;
    }
  return (i);
}
