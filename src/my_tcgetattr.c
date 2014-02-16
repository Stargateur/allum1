/*
** my_tcgetattr.c for my_tcgetattr in /home/plasko_a/rendu/PSU_2013_my_select
** 
** Made by Antoine PLASKOWSKI
** Login   <plasko_a@epitech.net>
** 
** Started on  Tue Jan 14 19:55:21 2014 Antoine PLASKOWSKI
** Last update Thu Feb  6 15:06:34 2014 Antoine Plaskowski
*/

#include	<termios.h>
#include	"my_str.h"

long		my_tcgetattr(struct termios *t)
{
  if (tcgetattr(0, t))
    {
      my_putstr("tcgectattr FAIL !\n", 1);
      return (1);
    }
  return (0);
}
