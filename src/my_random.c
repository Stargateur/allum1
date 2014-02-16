/*
** my_random.c for my_random in /home/plasko_a/rendu/Allum1
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Tue Feb 11 19:28:49 2014 Antoine Plaskowski
** Last update Thu Feb 13 21:26:44 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<time.h>
#include	"my_allum1.h"

static long	my_cpt(t_data *data)
{
  long		i;

  if (data == NULL)
    return (1);
  i = 0;
  while (data->prev != NULL)
    data = data->prev;
  while (data != NULL)
    {
      if (data->cur_all)
        i++;
      data = data->next;
    }
  if (i == 0)
    return (0);
  return (rand() % i);
}

t_data		*my_random_data(t_data *data)
{
  t_data	*data_tmp;
  long		rd;

  if (data == NULL)
    return (NULL);
  while (data->prev != NULL)
    data = data->prev;
  rd = my_cpt(data);
  data_tmp = data;
  while (data_tmp != NULL && rd)
    {
      if (data_tmp->cur_all)
        rd--;
      data_tmp = data_tmp->next;
    }
  while (data_tmp != NULL && data_tmp->cur_all == 0)
    data_tmp = data_tmp->next;
  if (data_tmp != NULL)
    return (data_tmp);
  return (data);
}

long		my_remove_random(t_game *game, t_data *data)
{
  long		nbr_remove_all;
  long		i;
  long		bool;

  if (game == NULL || !(data = my_random_data(data)) || data->cur_all == 0)
    return (1);
  if ((nbr_remove_all = rand() % data->cur_all + 1) <= 0)
    return (my_remove_one(game, data));
  bool = 1;
  i = 0;
  while (i < data->nbr_all && nbr_remove_all)
    {
      if (data->allum[i])
        {
          bool = 0;
          data->allum[i] = 0;
          data->cur_all--;
          nbr_remove_all--;
	  my_aff_move_ia(game);
        }
      i++;
    }
  return (bool);
}

