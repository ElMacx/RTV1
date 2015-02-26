/*
** my_printf.c for my_printf in /home/dulin_m/PSU_2013_my_printf
** 
** Made by maxime dulin
** Login   <dulin_m@epitech.net>
** 
** Started on  Tue Nov 12 17:05:58 2013 maxime dulin
** Last update Sun Nov 17 16:18:54 2013 maxime dulin
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

int	my_put_nbr_base(long nb, char *base)
{
  int	ct_base;
  int	res;

  ct_base = my_strlen(base);
  if (nb == 0)
    return (0);
  res = nb - my_put_nbr_base(nb / ct_base, base) * ct_base;
  my_putchar(base[res]);
  return (nb);
}

void		my_put_uns(unsigned int nb)
{
  unsigned int	ct;

  ct = 1;
  while ((nb / ct) >= 9)
    ct = ct * 10;
  while (nb > 9)
    {
      my_putchar((nb / ct) + 48);
      nb = nb % ct;
      ct = ct / 10;
    }
  my_putchar(nb + 48);
}

int	check_before(const char *format, int *i)
{
  if (format[*i] != '%' && format[*i] != 'd' && format[*i - 1] != '%')
    my_putchar(format[*i]);
  else if (format[*i] != '%' && format[*i] != 'c' && format[*i - 1] != '%')
    my_putchar(format[*i]);
  else if (format[*i] != '%' && format[*i] != 's' && format[*i - 1] != '%')
    my_putchar(format[*i]);
  else if (format[*i] != '%' && format[*i] != 'p' && format[*i - 1] != '%')
    my_putchar(format[*i]);
  else if (format[*i] != '%' && format[*i] != 'i' && format[*i - 1] != '%')
    my_putchar(format[*i]);
  else if (format[*i] != '%' && format[*i] != 'o' && format[*i - 1] != '%')
    my_putchar(format[*i]);
  else if (format[*i] != '%' && format[*i] != 'x' && format[*i - 1] != '%')
    my_putchar(format[*i]);
  else if (format[*i] != '%' && format[*i] != 'X' && format[*i - 1] != '%')
    my_putchar(format[*i]);
  else if (format[*i] != '%' && format[*i] != 'u' && format[*i - 1] != '%')
    my_putchar(format[*i]);
  else if (format[*i] != '%' && format[*i] != 'b' && format[*i - 1] != '%')
    my_putchar(format[*i]);
  else if (format[*i - 1] == '%' && format[*i] == '%')
    my_putchar('\n');
}

int	my_printf_bis(const char *format, va_list args, int i)
{
  if (format[i] == '%' && format[i + 1] == 'd')
    my_put_nbr(va_arg(args, int));
  if (format[i] == '%' && format[i + 1] == 'i')
    my_put_nbr(va_arg(args, int));
  if (format[i] == '%' && format[i + 1] == 'c')
    my_putchar(va_arg(args, int));
  if (format[i] == '%' && format[i + 1] == 's')
    my_putstr(va_arg(args, char *));
  if (format[i] == '%' && format[i + 1] == 'p')
    {
      my_putstr("0x");
      my_put_nbr_base(va_arg(args, long), "0123456789abcdef");
    }
  if (format[i] == '%' && format[i + 1] == 'u')
    my_put_uns(va_arg(args, unsigned int));
  if (format[i] == '%' && format[i + 1] == 'S')
    {
    }
}

int		my_printf(const char *format, ...)
{
  va_list	args;
  int		i;

  i = 0;
  va_start(args, format);
  while (format[i] != '\0')
    {
      check_before(format, &i);
      my_printf_bis(format, args, i);
      if (format[i] == '%' && format[i + 1] == '%')
	my_putchar('%');
      if (format[i] == '%' && format[i + 1] == 'o')
	my_put_nbr_base(va_arg(args, unsigned int), "01234567");
      if (format[i] == '%' && format[i + 1] == 'x')
	my_put_nbr_base(va_arg(args, unsigned int), "0123456789abcdef");
      if (format[i] == '%' && format[i + 1] == 'X')
	my_put_nbr_base(va_arg(args, unsigned int), "0123456789ABCDEF");
      if (format[i] == '%' && format[i + 1] == 'h' && format[i + 2] == 'h')
	my_put_nbr(va_arg(args, int));
      if (format[i] == '%' && format[i + 1] == 'b')
	my_put_nbr_base(va_arg(args, unsigned int), "01");
      i++;
    }
  va_end(args);
}
