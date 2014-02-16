/*
** my_raw_mode.c for my_raw_mode in /home/plasko_a/rendu/PSU_2013_my_select
** 
** Made by Antoine PLASKOWSKI
** Login   <plasko_a@epitech.net>
** 
** Started on  Tue Jan 14 15:05:37 2014 Antoine PLASKOWSKI
** Last update Thu Feb  6 15:28:07 2014 Antoine Plaskowski
*/

#include	<termios.h>
#include	"my_str.h"

long		my_raw_mode(struct termios *t)
{
  t->c_lflag &= ~ICANON;
  t->c_cc[VMIN] = 1;
  t->c_cc[VTIME] = 0;
  if (tcsetattr(0, TCSANOW, t))
    {
      my_putstr("setattr raw fail\n", 2);
      return (1);
    }
  return (0);
}
