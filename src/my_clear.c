/*
** my_clear.c for my_clear in /home/plasko_a/rendu/Allum1
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Wed Feb 12 13:05:57 2014 Antoine Plaskowski
** Last update Wed Feb 12 13:08:20 2014 Antoine Plaskowski
*/

#include		<stdlib.h>
#include		<sys/ioctl.h>
#include		<term.h>
#include		"my_termcaps.h"
#include		"my_str.h"

long                     my_clear(void)
{
  struct winsize        w;
  char                  *cm;
  char                  *espace;
  long                   i;

  if (!(cm = my_tgetstr("cm")) || my_get_size(&w))
    return (1);
  if ((espace = my_malloc(sizeof(char) * (w.ws_col * w.ws_row + 1))) == NULL)
    return (1);
  i = 0;
  while (i < w.ws_col * w.ws_row)
    espace[i++] = ' ';
  espace[i] = '\0';
  tputs(tgoto(cm, 0, 0), 0, &my_putint);
  my_putstr(espace, 0);
  tputs(tgoto(cm, 0, 0), 0, &my_putint);
  free(espace);
  return (0);
}
