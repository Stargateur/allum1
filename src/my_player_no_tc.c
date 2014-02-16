/*
** my_player_no_tc.c for my_player_no_tc in /home/plasko_a/rendu/Allum1
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed Feb 12 15:19:20 2014 Antoine Plaskowski
** Last update Thu Feb 13 21:30:21 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_allum1.h"
#include	"my_get_next_line.h"
#include	"my_str.h"

static long	my_verif_input(t_game *game, long line, long all)
{
  t_data	*data;
  long		i;

  if (game == NULL || all <= 0 || line <= 0)
    return (1);
  data = game->data;
  while (data != NULL && line-- > 1)
    data = data->next;
  if (data != NULL && data->cur_all >= all)
    {
      i = 0;
      while (i < data->nbr_all && all)
	{
	  if (data->allum[i])
	    {
	      data->allum[i] = 0;
	      all--;
	      data->cur_all--;
	    }
	  i++;
	}
      return (0);
    }
  return (1);
}

long		my_player_no_tc(t_game *game)
{
  char		*line;
  char		*all;
  long		bool;

  bool = 42;
  while (bool)
    {
      my_putstr("What line ?\n", 1);
      if ((line = my_get_next_line(0, 0)) == NULL)
	return (1);
      my_putstr("How many machtches ?\n", 1);
      if ((all = my_get_next_line(0, 0)) == NULL)
	{
	  free(all);
	  return (1);
	}
      my_putchar('\n', 1);
      if (my_verif_input(game, my_getnbr(line), my_getnbr(all)))
	my_aff_game(game);
      else
	bool = 0;
      free(line);
      free(all);
    }
  return (0);
}
