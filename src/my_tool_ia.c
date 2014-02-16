/*
** my_ia.c for my_ia in /home/plasko_a/rendu/Allum1
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sat Feb  8 06:31:50 2014 Antoine Plaskowski
** Last update Thu Feb 13 21:27:14 2014 Antoine Plaskowski
*/

#define		_BSD_SOURCE
#include	<unistd.h>
#undef		_BSD_SOURCE

#include	<stdlib.h>
#include	"my_allum1.h"
#include	"my_str.h"

long		my_aff_move_ia(t_game *game)
{
  if (game->termcaps)
    {
      if (usleep(SPEED_IA / 2))
	return (1);
      my_aff_game(game);
      if (usleep(SPEED_IA / 2))
	return (1);
    }
  return (0);
}

t_data		*my_found_data(t_game *game)
{
  t_data	*data_return;
  long		tmp;

  if (game == NULL)
    return (NULL);
  data_return = game->data;
  tmp = data_return->cur_all;
  while (data_return != NULL)
    {
      if (my_verif(game->data) == 0)
	{
	  data_return->cur_all = tmp;
	  return (data_return);
	}
      if (data_return->cur_all == 0)
	{
	  data_return->cur_all = tmp;
	  data_return = data_return->next;
	  if (data_return != NULL)
	    tmp = data_return->cur_all;
	}
      else
	data_return->cur_all--;
    }
  return (my_random_data(game->data));
}

long		my_verif(t_data *data)
{
  long		result;

  result = 0;
  while (data != NULL)
    {
      result = result ^ data->cur_all;
      data = data->next;
    }
  return (result);
}

long		my_end(t_data *data)
{
  while (data != NULL)
    {
      if (data->cur_all > 1)
	return (1);
      data = data->next;
    }
  return (0);
}

long		my_ctp(t_data *data)
{
  long		result;

  result = 0;
  while (data != NULL)
    {
      if (data->cur_all == 1)
	result++;
      data = data->next;
    }
  return (result);
}
