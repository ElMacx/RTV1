/*
** my_strcmp.c for my_strcmp in /home/dulin_m/rendu/Piscine-C-lib/my
**
** Made by maxime dulin
** Login   <dulin_m@epitech.net>
**
** Started on  Tue Oct  8 22:24:14 2013 maxime dulin
** Last update Wed Jan  8 14:37:29 2014 maxime dulin
*/

int	my_strcmp(char *s1, char *s2)
{
  int	ct;
  int	diff;

  ct = 0;
  diff = 0;
  while (s1[ct] == s2[ct] && s1[ct] != '\0' && s2[ct] != '\0')
    {
      ct = ct + 1;
      if (s1[ct] != s2[ct])
	{
	  diff = s1[ct] - s2[ct];
	  return (diff);
	}
    }
  diff = s1[ct] - s2[ct];
  return (diff);
}
