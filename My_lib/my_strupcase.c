/*
** my_strupcase.c for my_strupcase in /home/dulin_m/rendu/Piscine-C-lib/my
** 
** Made by maxime dulin
** Login   <dulin_m@epitech.net>
** 
** Started on  Tue Oct  8 22:41:30 2013 maxime dulin
** Last update Sun Nov 17 16:09:54 2013 maxime dulin
*/

char	*my_strupcase(char *str)
{
  int	new;
  int	counter;

  new = 0;
  counter = 0;
  while (str[counter] != '\0')
    {
      new = str[counter] + 32;
      counter = counter + 1;
      if (str[counter - 1] = 32)
	{
	  new = new + str[counter] + 32;
	}
    }
}
