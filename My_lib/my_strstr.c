/*
** my_strstr.c for my_strstr in /home/dulin_m/rendu/Piscine-C-lib/my
** 
** Made by maxime dulin
** Login   <dulin_m@epitech.net>
** 
** Started on  Tue Oct  8 22:17:42 2013 maxime dulin
** Last update Sun Nov 17 16:09:35 2013 maxime dulin
*/

char	*my_strstr(char *str, char *to_find)
{
  int	counter;
  int	counter_tf;

  counter = 0;
  counter_tf = 0;
  while (str[counter] != to_find[counter_tf])
    {
      counter = counter + 1;
      counter_tf = counter_tf + 1;
      while (str[counter] == to_find[counter_tf])
	{
	  counter = counter + 1;
	  counter_tf = counter_tf + 1;
	  if (to_find[counter_tf] == '\0')
	    {
	      return (&str[counter - counter_tf]);
	    }
	  if (to_find[counter_tf] != counter_tf)
	    {
	      counter_tf = 0;
	    }
	}
    }
}
