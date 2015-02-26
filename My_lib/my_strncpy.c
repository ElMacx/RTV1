/*
** my_strncpy.c for my_strncpy in /home/dulin_m/rendu/Piscine-C-lib/my
** 
** Made by maxime dulin
** Login   <dulin_m@epitech.net>
** 
** Started on  Tue Oct  8 22:07:54 2013 maxime dulin
** Last update Sun Nov 17 16:09:20 2013 maxime dulin
*/

char	*my_strncpy(char *dest, char *src, int n)
{
  int	strlength;
  int	counter;

  counter = 0;
  strlength = 0;
  while (counter != n)
    {
      dest[counter] = src[counter];
      counter = counter + 1;
    }
  while (src[strlength] != '\0')
    {
      strlength = strlength + 1;
    }
  if (n > strlength)
    {
      dest[strlength + 1] = '\0';
    }
  dest[n] = '\0';
  return (dest);
}
