/*
** my_echo.c for my_echo in /home/plasko_a/rendu/PSU_2013_my_select
** 
** Made by Antoine PLASKOWSKI
** Login   <plasko_a@epitech.net>
** 
** Started on  Tue Jan 14 15:07:40 2014 Antoine PLASKOWSKI
** Last update Thu Feb  6 15:29:04 2014 Antoine Plaskowski
*/

#include	<termios.h>
#include	"my_str.h"

long		my_echo_off(struct termios *t)
{
  t->c_lflag &= ~ECHO;
  if (tcsetattr(0, TCSANOW, t))
    {
      my_putstr("setattr echo fail\n", 2);
      return (1);
    }
  return (0);
}
