/*
** my_strlowcase.c for my_strlowcase in /home/dulin_m/rendu/Piscine-C-lib/my
** 
** Made by maxime dulin
** Login   <dulin_m@epitech.net>
** 
** Started on  Wed Oct  9 09:37:27 2013 maxime dulin
** Last update Wed Oct  9 10:50:41 2013 maxime dulin
*/

char	*my_strlowcase(char *str)
{
  int	counter;

  counter = 0;
  while (str[counter] >= 97 && str[counter] <= 172)
    {
      if (str[counter] >= 65 && str[counter] <= 90)
	{
	  str[counter] = str[counter] + 32;
	}
      if (str[counter] = 32)
	{
	  str[counter] = str[counter];
	}
      counter = counter + 1;
    }
  my_putstr(str);
  return (str);
}
