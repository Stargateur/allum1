/*
** my_tgetent.c for my_tgetent in /home/plasko_a/rendu/PSU_2013_my_select
** 
** Made by Antoine PLASKOWSKI
** Login   <plasko_a@epitech.net>
** 
** Started on  Tue Jan 14 14:48:30 2014 Antoine PLASKOWSKI
** Last update Wed Feb 12 13:21:05 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<term.h>
#include	"my_str.h"

long		my_tgetent(const char *name)
{
  long		status;

  status = tgetent(NULL, name);
  if (status == -1)
    {
      my_putstr("data terminal not found\n", 2);
      return (1);
    }
  else if (status == 0)
    {
      my_putstr(name, 2);
      my_putstr(" is not valid !\n", 2);
      return (1);
    }
  return (0);
}
