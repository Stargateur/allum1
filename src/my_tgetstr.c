/*
** my_tgetstr.c for my_tgetstr in /home/plasko_a/rendu/PSU_2013_my_select
** 
** Made by Antoine PLASKOWSKI
** Login   <plasko_a@epitech.net>
** 
** Started on  Wed Jan 15 21:51:02 2014 Antoine PLASKOWSKI
** Last update Wed Feb 12 13:21:21 2014 Antoine Plaskowski
*/

#include	<term.h>
#include	<stdlib.h>
#include	"my_str.h"

char		*my_tgetstr(const char *str)
{
  char		*new_str;

  if ((new_str = tgetstr(str, NULL)) == NULL)
    {
      my_putstr(str, 2);
      my_putstr(" : no available\n", 2);
      return (NULL);
    }
  return (new_str);
}
