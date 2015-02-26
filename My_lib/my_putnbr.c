/*
** my_put_nbr.c for my_put_nbr in /home/dulin_m/rendu
** 
** Made by maxime dulin
** Login   <dulin_m@epitech.net>
** 
** Started on  Sun Oct 13 09:38:49 2013 maxime dulin
** Last update Sun Oct 13 09:38:52 2013 maxime dulin
*/

int     pow_10(long a)
{
  long  sto;
  long  i;

  sto = 1;
  i = 0;
  while (i < a)
    {
      sto = sto * 10;
      i = i + 1;
    }
  a = sto;
  return (sto);
}

int     counter(long nb)
{
  long  i;

  i = -1;
  while (nb >= 1)
    {
      nb = nb / 10;
      i = i + 1;
    }
  nb = i;
}

int     my_put_nbr(int n)
{
  long  i;
  long  fpart;
  long long     nb;

  nb = n;
  if (nb == 0)
    {
      my_putchar('0');
      return (0);
    }
  if (nb < 0)
    {
      nb = nb * -1;
      my_putchar('-');
    }
  i = counter(nb);
  while (i >= 0)
    {
      fpart = nb / pow_10(i);
      my_putchar(fpart + 48);
      nb = nb - (fpart * pow_10(i));
      i = i - 1;
    }
}
