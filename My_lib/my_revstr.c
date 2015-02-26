/*
** my_revstr.c for my_revstr in /home/dulin_m/rendu/Piscine-C-lib/my
** 
** Made by maxime dulin
** Login   <dulin_m@epitech.net>
** 
** Started on  Tue Oct  8 22:13:28 2013 maxime dulin
** Last update Sun Nov 17 16:14:22 2013 maxime dulin
*/

char	*my_revstr(char *str)
{
  int	longi;
  int	counter;
  int	t;

  counter = 0;
  longi = my_strlen(str) - 1;
  while (longi >= counter)
    {
      t = str[longi];
      str[longi] = str[counter];
      str[counter] = t;
      counter = counter + 1;
      longi = longi - 1;
    }
  return (str);
}
