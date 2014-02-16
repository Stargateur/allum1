/*
** my_move_more.c for my_move_more in /home/plasko_a/rendu/Allum1
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed Feb 12 19:55:21 2014 Antoine Plaskowski
** Last update Thu Feb 13 21:28:16 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_allum1.h"
#include	"my_termcaps.h"

static long	my_save_data(t_game *game, t_data **tmp_data,
			     long *tmp_all, long *tmp)
{
  if (!game || !tmp || !tmp_all || !tmp_data)
    return (1);
  *tmp = game->pos_col;
  *tmp_all = game->pos_all;
  *tmp_data = game->cur_data;
  return (0);
}

static long	my_restore_data(t_game *game, t_data **tmp_data,
				long *tmp_all, long *tmp)
{
  if (!game || !tmp || !tmp_all || !tmp_data)
    return (1);
  game->pos_col = *tmp;
  game->pos_all = *tmp_all;
  game->cur_data = *tmp_data;
  return (0);
}

static long	my_replace_cur(t_game *game)
{
  if (game == NULL || game->cur_data == NULL || game->cur_data->allum == NULL)
    return (1);
  if (game->pos_all >= 0 && game->pos_all < game->cur_data->nbr_all
      && game->cur_data->allum[game->pos_all])
    return (0);
  my_move_left(game);
  if (game->pos_all >= 0 && game->pos_all < game->cur_data->nbr_all
      && game->cur_data->allum[game->pos_all])
    return (0);
  my_move_right(game);
  if (game->pos_all >= 0 && game->pos_all < game->cur_data->nbr_all
      && game->cur_data->allum[game->pos_all])
    return (0);
  return (1);
}

long		my_move_up(t_game *game)
{
  long		tmp;
  long		tmp_all;
  t_data	*tmp_data;

  if (game == NULL || game->cur_data == NULL ||
      my_save_data(game, &tmp_data, &tmp_all, &tmp))
    return (1);
  game->cur_data = game->cur_data->prev;
  game->pos_col--;
  if (game->pos_all != 0)
    game->pos_all--;
  if (game->cur_data != NULL && game->pos_all >= game->cur_data->nbr_all)
    game->pos_all--;
  while (game->cur_data != NULL && my_replace_cur(game))
    {
      game->cur_data = game->cur_data->prev;
      if (game->pos_all != 0)
	game->pos_all--;
      game->pos_col--;
    }
  if (my_replace_cur(game))
    my_restore_data(game, &tmp_data, &tmp_all, &tmp);
  return (0);
}

long		my_move_down(t_game *game)
{
  long		tmp;
  long		tmp_all;
  t_data	*tmp_data;

  if (game == NULL || game->cur_data == NULL ||
      my_save_data(game, &tmp_data, &tmp_all, &tmp))
    return (1);
  game->cur_data = game->cur_data->next;
  game->pos_col++;
  game->pos_all++;
  while (game->cur_data != NULL && my_replace_cur(game))
    {
      game->cur_data = game->cur_data->next;
      game->pos_all++;
      game->pos_col++;
    }
  if (my_replace_cur(game))
    my_restore_data(game, &tmp_data, &tmp_all, &tmp);
  return (0);
}
