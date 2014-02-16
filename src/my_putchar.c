/*
** my_putchar.c for putchar in /home/plasko_a/rendu/Piscine-C-lib/my
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Mon Oct 21 10:46:02 2013 Antoine Plaskowski
** Last update Wed Feb 12 16:59:35 2014 Antoine Plaskowski
*/

#include	<unistd.h>

long		my_putchar(const char c, const long fd)
{
  return (write(fd, &c, 1) != 1);
}
