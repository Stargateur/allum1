/*
** my_aer_ia.c for my_aer_ia in /home/plasko_a/rendu/Allum1
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed Feb 12 14:41:03 2014 Antoine Plaskowski
** Last update Thu Feb 13 21:14:27 2014 Antoine Plaskowski
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
  while (my_verif(game->data) && i < data->nbr_all)
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

long		my_aer_ia(t_game *game)
{
  t_data	*data;

  if (game == NULL)
    return (1);
  if ((data = my_found_data(game)) == NULL)
    return (1);
  if (my_verif(game->data))
    {
      if (my_remove_allum(game, data))
        return (1);
      return (0);
    }
  return (my_remove_random(game, data));
}
