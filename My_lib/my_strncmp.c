/*
** my_strncmp.c for my_strncmp in /home/dulin_m/rendu/Piscine-C-lib/my
** 
** Made by maxime dulin
** Login   <dulin_m@epitech.net>
** 
** Started on  Tue Oct  8 22:29:07 2013 maxime dulin
** Last update Sun Nov 17 16:11:57 2013 maxime dulin
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  int	counter;
  int	diff;
  int	stop;

  counter = 0;
  diff = 0;
  stop = 0;

  while (stop < n)
    {
      while (s1[counter] == s2[counter])
	{
	  if (s1[counter] != s2[counter])
	    {
	      diff = s1[counter] - s2[counter];
	      return (diff);
	    }
	  else
	    {
	      diff = s1[counter] - s2[counter];
	      stop = stop + 1;
	    }
	  counter = counter + 1;
	}
    }
}
