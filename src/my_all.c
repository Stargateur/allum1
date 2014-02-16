/*
** my_all.c for my_all in /home/plasko_a/rendu/Allum1
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sat Feb  8 06:12:32 2014 Antoine Plaskowski
** Last update Sun Feb 16 23:02:08 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_allum1.h"

long		my_change_all(t_game *game)
{
  if (game == NULL || game->cur_data == NULL)
    return (1);
  if (game->pos_all >= 0 && game->pos_all < game->cur_data->nbr_all)
    {
      if (game->cur_data->allum[game->pos_all] == 1)
        game->cur_data->allum[game->pos_all] = 2;
      else if (game->cur_data->allum[game->pos_all] == 2)
        game->cur_data->allum[game->pos_all] = 1;
    }
  return (0);
}

static long	my_check_all_same_lign(t_game *game)
{
  t_data	*data;
  int		i;
  int		nbr_col_sel;

  if (game == NULL)
    return (1);
  data = game->data;
  nbr_col_sel = 0;
  while (data != NULL)
    {
      i = 0;
      while (i < data->nbr_all && data->allum[i] != 2)
	i++;
      if (i < data->nbr_all && data->allum[i] == 2)
	nbr_col_sel++;
      data = data->next;
    }
  if (nbr_col_sel != 1)
    {
      my_error_select(game);
      return (1);
    }
  return (0);
}

long		my_remove_all(t_game *game)
{
  t_data	*data;
  int		i;

  if (game == NULL || my_check_all_same_lign(game))
    return (1);
  data = game->data;
  while (data != NULL)
    {
      i = 0;
      while (i < data->nbr_all)
        {
          if (data->allum[i] == 2)
	    {
	      data->allum[i] = 0;
	      data->cur_all--;
           }
          i++;
        }
      data = data->next;
    }
  return (0);
}

long		my_game_is_not_finish(t_data *data)
{
  while (data != NULL)
    {
      if (data->cur_all)
	return (1);
      data = data->next;
    }
  return (0);
}
