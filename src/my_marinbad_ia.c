/*
** my_marinbad_ia.c for my_marinbad_ia in /home/plasko_a/rendu/Allum1
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Fri Feb 14 15:33:03 2014 Antoine Plaskowski
** Last update Fri Feb 14 15:47:44 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_allum1.h"

long		my_marinbad_ia(t_game *game)
{
  long		i;

  if (game == NULL || game->data == NULL || game->data->allum == NULL)
    return (1);
  if (my_remove_one(game, game->data))
    return (1);
  i = 1;
  while (i < 3 && game->data->cur_all % 4 != 1 && game->data->cur_all)
    {
      if (my_remove_one(game, game->data))
	return (1);
      i++;
    }
  return (0);
}
