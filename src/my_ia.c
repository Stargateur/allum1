/*
** my_ia.c for my_ia in /home/plasko_a/rendu/Allum1
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sat Feb  8 06:31:50 2014 Antoine Plaskowski
** Last update Wed Feb 25 16:20:13 2015 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_allum1.h"

long		my_remove_one(t_game *game, t_data *data)
{
  long		i;

  if (data == NULL || game == NULL)
    return (1);
  i = 0;
  while (i < data->nbr_all && data->allum[i] == 0)
    i++;
  if (i < data->nbr_all)
    {
      data->allum[i] = 0;
      data->cur_all--;
      my_aff_move_ia(game);
    }
  else
    return (1);
  return (0);
}

long		my_ia(t_game *game)
{
  if (game == NULL)
    return (1);
  if (game->mode == 1)
    return (my_marinbad_ia(game));
  if (game->level_ia == 2)
    return (my_chuck_norris_ia(game));
  if (game->level_ia == 1)
    return (my_hollande_ia(game));
  if (game->level_ia == 0)
    return (my_aer_ia(game));
  return (1);
}
