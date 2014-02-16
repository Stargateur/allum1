/*
** my_marinbad.c for my_marinbad in /home/plasko_a/rendu/Allum1
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Fri Feb 14 15:07:23 2014 Antoine Plaskowski
** Last update Fri Feb 14 15:26:37 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_allum1.h"
#include	"my_str.h"

long		my_marinbad(t_game *game)
{
  long		i;

  if (game == NULL)
    return (1);
  if (game->mode == 0)
    return (1);
  if (game->nbr_col == 0)
    game->nbr_col = 21;
  game->map = 1;
  if ((game->data = my_malloc(sizeof(t_data))) == NULL)
    return (1);
  if ((game->data->allum = my_malloc(sizeof(long) * game->nbr_col)) == NULL)
    return (1);
  i = 0;
  while (i < game->nbr_col)
    game->data->allum[i++] = 1;
  game->data->cur_all = game->nbr_col;
  game->data->nbr_all = game->nbr_col;
  game->data->prev = NULL;
  game->data->next = NULL;
  game->cur_data = game->data;
  game->nbr_col = 1;
  return (0);
}
