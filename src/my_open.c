/*
** my_bmp.c for my_bmp in /home/plasko_a/rendu/MUL_2013_wof3d/src/
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Thu Oct 24 16:05:36 2013 Antoine Plaskowski
** Last update Thu Feb 13 18:19:14 2014 Antoine Plaskowski
*/

#include	<sys/stat.h>
#include	<fcntl.h>
#include	"my_str.h"

long		my_open_rdonly(const char *str)
{
  long		fd;

  if ((fd = open(str, O_RDONLY)) == -1)
    {
      my_putstr(str, 2);
      my_putstr(" : can't open\n", 2);
    }
  return (fd);
}

long		my_open_wr(const char *str)
{
  long		fd;

  if ((fd = open(str, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP
		 | S_IROTH)) == -1)
    {
      my_putstr(str, 2);
      my_putstr("can't open\n", 2);
    }
  return (fd);
}

