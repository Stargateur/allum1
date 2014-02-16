/*
** my_getnbr.c for my_getnbr in /home/plasko_a/rendu/Piscine-C-Jour_04
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Thu Oct  3 13:27:41 2013 Antoine Plaskowski
** Last update Sat Feb  8 05:50:59 2014 Antoine Plaskowski
*/

#include	<stdlib.h>

long		my_getnbr(const char *str)
{
  long		sign;
  long		nbr;

  if (str == NULL)
    return (0);
  sign = 1;
  while (*str == '-' || *str == '+')
    if (*str++ == '-')
      sign *= -1;
  while (*str == '0')
    str++;
  nbr = 0;
  if (sign > 0)
    while (*str >= '0' && *str <= '9')
      nbr = nbr * 10 + (*str++ - '0');
  else
    while (*str >= '0' && *str <= '9')
      nbr = nbr * 10 - (*str++ - '0');
  return (nbr);
}
