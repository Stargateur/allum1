/*
** my_chuck_norris_ia.c for my_chuck_norris_ia in /home/plasko_a/rendu/Allum1
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed Feb 12 14:45:38 2014 Antoine Plaskowski
** Last update Thu Feb 13 21:27:42 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_allum1.h"

static long	my_remove_allum(t_game *game, t_data *data)
{
  long		i;
  long		tmp;

  if (data == NULL || game == NULL)
    return (1);
  tmp = data->cur_all;
  i = 0;
  while (my_verif(game->data) && i < data->nbr_all && my_end(game->data))
    {
      if (data->allum[i])
        {
          data->allum[i] = 0;
          data->cur_all--;
          my_aff_move_ia(game);
        }
      i++;
    }
  return (tmp == data->cur_all);
}

long		my_chuck_norris_ia(t_game *game)
{
  t_data	*data;

  if (game == NULL)
    return (1);
  if ((data = my_found_data(game)) == NULL)
    return (1);
  if (my_verif(game->data))
    {
      if (my_remove_allum(game, data))
	return (my_remove_one(game, data));
      if (my_end(game->data) == 0 && my_ctp(game->data) % 2 == 0)
	return (my_remove_one(game, data));
      return (0);
    }
  return (my_remove_random(game, data));
}
