/*
** my_data.c for my_data in /home/plasko_a/rendu/Allum1
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Wed Feb  5 11:44:20 2014 Antoine Plaskowski
** Last update Thu Feb 13 18:40:17 2014 Antoine Plaskowski
*/

#include       	<stdlib.h>
#include	"my_allum1.h"
#include	"my_str.h"

static t_data	*my_put_data(t_data *data, long nbr_all)
{
  t_data	*new_data;

  if ((new_data = my_malloc(sizeof(t_data))) == NULL)
    return (NULL);
  if ((new_data->allum = my_malloc(sizeof(long) * nbr_all)) == NULL)
    return (NULL);
  new_data->nbr_all = nbr_all;
  new_data->cur_all = nbr_all;
  while (nbr_all--)
    new_data->allum[nbr_all] = 1;
  new_data->next = NULL;
  if (data == NULL)
    {
      new_data->prev = NULL;
      return (new_data);
    }
  while (data->next != NULL)
    data = data->next;
  new_data->prev = data;
  data->next = new_data;
  return (new_data);
}

long		my_init_data(t_game *game)
{
  long		i;

  if (game == NULL)
    return (1);
  game->data = NULL;
  i = 0;
  while (i < game->nbr_col)
    if (!(game->data = my_put_data(game->data, i++ * 2 + 1)))
      return (1);
  if (game->data == NULL)
    return (1);
  while (game->data->prev != NULL)
    game->data = game->data->prev;
  game->cur_data = game->data;
  return (0);
}

void		my_free_data(t_data *data)
{
  if (data)
    {
      while (data->prev != NULL)
	data = data->prev;
      while (data->next != NULL)
	{
	  data = data->next;
	  free(data->prev->allum);
	  free(data->prev);
	}
      free(data->allum);
      free(data);
    }
}

void		my_aff_data(t_data *data)
{
  int		i;

  while (data)
    {
      i = 0;
      while (i < data->nbr_all)
	my_putnbr(data->allum[i++], 1);
      data = data->next;
    }
}

long		my_max_all(t_data *data)
{
  long		max;

  max = 0;
  while (data != NULL)
    {
      if (max < data->nbr_all)
	max = data->nbr_all;
      data = data->next;
    }
  return (max);
}
