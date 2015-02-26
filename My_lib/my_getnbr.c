/*
** my_getnbr.c for piscine_jour_04 in /home/laffar_a/rendu/Piscine-C-Jour_04
** 
** Made by Antoine Laffargue
** Login   <laffar_a@epitech.net>
** 
** Started on  Thu Oct  3 16:45:57 2013 Antoine Laffargue
** Last update Sun Nov 17 16:28:23 2013 maxime dulin
*/

int	my_power(int p)
{
  int	count;
  int	power;

  power = 1;
  count = 0;
  while (count < (p-1))
    {
      power = power * 10;
      count = count + 1;
    }
  return (power);
}

int	test(char *str, int *count)
{
  int	neg;

  neg = 0;
  while (str[*count] == '+' || str[*count] == '-')
    {
      if (str[*count] == '-')
	neg = neg + 1;
      *count = *count + 1;
    }
  if ((neg % 2) != 0)
    neg = 1;
  return (neg);
}

int	size(int str, int neg)
{
  if (str > 0 && neg == 1)
    return (1);
  if (str < 0 && neg != 1)
    return (1);
  return (0);
}

int	my_getnbr(char *str)
{
  int	count;
  int	*p_i;
  int	neg;
  int	return_int;
  int	a;
  int	length;

  count = 0;
  p_i = &count;
  length = my_strlen(str);
  return_int = 0;
  neg = test(str, p_i);
  if (*str == '-' && (*str >='0'|| *str < '9'));
  while (str[count] >= '0' && str[count] <= '9')
    {
      a = my_power(length - count);
      return_int = return_int + ((str[count] - '0') * a);
      count = count + 1;
    }
  return_int = return_int / a;
  if (neg == 1)
    return_int = return_int * -1;
  if (size(return_int, neg))
    return (0);
  return (return_int);
}
