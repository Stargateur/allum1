/*
** my_get_size.c for my_get_size in /home/plasko_a/rendu/PSU_2013_my_select
** 
** Made by Antoine PLASKOWSKI
** Login   <plasko_a@epitech.net>
** 
** Started on  Thu Jan 16 20:49:32 2014 Antoine PLASKOWSKI
** Last update Wed Feb  5 15:30:48 2014 Antoine Plaskowski
*/

#include	<sys/ioctl.h>
#include	"my_str.h"

long		my_get_size(struct winsize *w)
{
  if (ioctl(0, TIOCGWINSZ, w))
    {
      my_putstr("can't get size window\n", 2);
      return (1);
    }
  return (0);
}
