/*
** my_move_cur.c for my_move_cur in /home/plasko_a/rendu/Allum1
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Fri Feb  7 19:06:39 2014 Antoine Plaskowski
** Last update Thu Feb 13 19:15:07 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_allum1.h"
#include	"my_termcaps.h"

long		my_move_cur(t_game *game)
{
  char		*cm;
  long		tmp;

  if (game == NULL || game->cur_data == NULL)
    return (1);
  if ((cm = my_tgetstr("cm")) == NULL)
    return (1);
  if (game->map)
    tmp = 1;
  else
    tmp = (my_max_all(game->data) - game->cur_data->nbr_all) / 2 + 1;
  tputs(tgoto(cm, game->pos_all + tmp, game->pos_col + 3), 0, &my_putint);
  return (0);
}

long		my_move_right(t_game *game)
{
  long		tmp;

  if (game == NULL || game->cur_data == NULL || game->cur_data->allum == NULL)
    return (1);
  if (game->pos_all < 0 || game->pos_all >= game->cur_data->nbr_all)
    game->pos_all = 0;
  tmp = game->pos_all;
  tmp++;
  while (tmp < game->cur_data->nbr_all && game->cur_data->allum[tmp] == 0)
    tmp++;
  if (tmp < game->cur_data->nbr_all && game->cur_data->allum[tmp])
    game->pos_all = tmp;
  return (0);
}

long		my_move_left(t_game *game)
{
  long		tmp;

  if (game == NULL || game->cur_data == NULL || game->cur_data->allum == NULL)
    return (1);
  if (game->pos_all < 0 || game->pos_all >= game->cur_data->nbr_all)
    game->pos_all = game->cur_data->nbr_all - 1;
  tmp = game->pos_all;
  tmp--;
  while (tmp >= 0 && game->cur_data->allum[tmp] == 0)
    tmp--;
  if (tmp >= 0 && game->cur_data->allum[tmp])
    game->pos_all = tmp;
  return (0);
}

long		my_move(t_game *game, const char *buf)
{
  if (game == NULL)
    return (1);
  if (buf[0] == 27)
    {
      if (buf[2] == 68)
	my_move_left(game);
      else if (buf[2] == 67)
	my_move_right(game);
      else if (buf[2] == 66 && game->pos_col + 1 < game->nbr_col)
	my_move_down(game);
      else if (buf[2] == 65 && game->pos_col > 0)
	my_move_up(game);
      my_move_cur(game);
    }
  return (0);
}
