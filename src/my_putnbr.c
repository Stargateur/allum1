/*
** my_put_nbr.c for my_put_nbr in /home/plasko_a/rendu/Piscine-C-Jour_03
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Wed Oct  2 13:24:35 2013 Antoine Plaskowski
** Last update Wed Feb  5 11:10:09 2014 Antoine Plaskowski
*/

#include	"my_str.h"

long		my_putnbr(long nb, const long fd)
{
  long		i;

  i = 0;
  if (nb / 10 != 0)
    i = my_putnbr(nb / 10, fd);
  else if (nb < 0)
    i += my_putchar('-', fd);
  if ((nb %= 10) < 0)
    nb *= -1;
  return (i + my_putchar(nb + '0', fd));
}
