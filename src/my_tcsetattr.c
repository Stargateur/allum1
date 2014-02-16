/*
** my_tcsetattr.c for my_tcsetattr in /home/plasko_a/rendu/PSU_2013_my_select
** 
** Made by Antoine PLASKOWSKI
** Login   <plasko_a@epitech.net>
** 
** Started on  Tue Jan 14 20:13:24 2014 Antoine PLASKOWSKI
** Last update Wed Jan 15 15:05:48 2014 Antoine PLASKOWSKI
*/

#include	<termios.h>
#include	"my_str.h"

int		my_tcsetattr(struct termios *t)
{
  if (tcsetattr(0, TCSANOW, t))
    {
      my_putstr("tcsetattr FAIL !\n", 2);
      return (1);
    }
  return (0);
}
