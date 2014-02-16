/*
** my_put_error_msg.c for my_put_error_msg in /home/plasko_a/rendu/Allum1
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Tue Feb 11 04:42:29 2014 Antoine Plaskowski
** Last update Thu Feb 13 17:21:05 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_allum1.h"
#include	"my_termcaps.h"
#include	"my_str.h"

long		my_error_select(t_game *game)
{
  char		*cm;

  if (game == NULL)
    return (1);
  if ((cm = my_tgetstr("cm")) == NULL)
    return (1);
  tputs(tgoto(cm, 1, 2), 0, &my_putint);
  my_putstr("You must select one or more mathches on only one lign", 0);
  my_move_cur(game);
  return (0);
}
