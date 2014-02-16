/*
** my_aff_game_tc.c for my_aff_game_tc in /home/plasko_a/rendu/Allum1
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Wed Feb 12 16:20:17 2014 Antoine Plaskowski
** Last update Thu Feb 13 19:14:21 2014 Antoine Plaskowski
*/

#include		<stdlib.h>
#include		<sys/ioctl.h>
#include		<term.h>
#include		"my_allum1.h"
#include		"my_termcaps.h"
#include		"my_str.h"

static long		my_put_all(long all)
{
  char			*str;

  if (all == 2)
    {
      if ((str = my_tgetstr("us")) == NULL)
	return (1);
      tputs(str, 0, &my_putint);
      my_putchar('|', 0);
      if ((str = my_tgetstr("me")) == NULL)
	return (1);
      tputs(str, 0, &my_putint);
    }
  else if (all == 1)
    my_putchar('|', 0);
  else
    my_putchar(' ', 0);
  return (0);
}

static long		my_aff_player(t_game *game, char *cm)
{
  if (game == NULL || cm == NULL)
    return (1);
  tputs(tgoto(cm, 1, 1), 0, &my_putint);
  my_putstr("Player ", 0);
  my_putnbr(game->who_play + 1, 0);
  return (0);
}

static long		my_define_deca(t_game *game, t_data *data)
{
  if (game == NULL || data == NULL)
    return (1);
  if (game->map)
    return (1);
  return ((my_max_all(game->data) - data->nbr_all) / 2 + 1);
}

long			my_aff_game_tc(t_game *game)
{
  struct winsize	w;
  char                  *cm;
  t_data		*data;
  long			i;
  long			j;

  my_clear();
  if (game == NULL || my_get_size(&w))
    return (1);
  if ((cm = my_tgetstr("cm")) == NULL)
    return (1);
  data = game->data;
  i = 3;
  while (data != NULL)
    {
      tputs(tgoto(cm, my_define_deca(game, data), i++), 0, &my_putint);
      j = 0;
      while (j < data->nbr_all)
	if (my_put_all(data->allum[j++]))
	  return (1);
      data = data->next;
    }
  my_aff_player(game, cm);
  my_move_cur(game);
  return (0);
}
