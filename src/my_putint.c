/*
** my_putint.c for my_putint.c in /home/plasko_a/rendu/PSU_2013_my_select
** 
** Made by Antoine PLASKOWSKI
** Login   <plasko_a@epitech.net>
** 
** Started on  Wed Jan 15 14:46:08 2014 Antoine PLASKOWSKI
** Last update Wed Feb  5 15:36:57 2014 Antoine Plaskowski
*/

#include	<unistd.h>

long		my_putint(const int nb)
{
  if (write(0, &nb, 1) != 1)
    return (1);
  return (0);
}
