/*
** my_aff_game_no_tc.c for my_aff_game_no_tc in /home/plasko_a/rendu/Allum1
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed Feb 12 16:24:46 2014 Antoine Plaskowski
** Last update Fri Feb 14 18:18:50 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_allum1.h"
#include	"my_str.h"

static long	my_len_nb(long nb)
{
  if (nb / 10)
    return (my_len_nb(nb / 10) + 1);
  return (1);
}

static long	my_aff_begin(t_game *game, t_data *data, long j, long len)
{
  long		i;
  long		len_j;

  if (game == NULL || data == NULL)
    return (1);
  i = 0;
  while (game->map == 0 && i++ < game->nbr_col - data->nbr_all / 2 - 1)
    my_putchar(' ', 1);
  len_j = my_len_nb(j);
  while (len_j++ < len)
    my_putchar(' ', 1);
  my_putnbr(j, 1);
  my_putchar(' ', 1);
  return (0);
}

static long	my_aff_end(t_data *data)
{
  long		i;

  if (data == NULL)
    return (1);
  i = 0;
  while (i < data->nbr_all)
    if (data->allum[i++])
      my_putchar('|', 1);
    else
      my_putchar('_', 1);
  my_putchar(' ', 1);
  my_putnbr(data->cur_all, 1);
  my_putchar('\n', 1);
  return (0);
}

long		my_aff_game_no_tc(t_game *game)
{
  t_data	*data;
  long		i;
  long		len;

  if (game == NULL)
    return (1);
  my_putstr("Player ", 1);
  my_putnbr(game->who_play + 1, 1);
  my_putstr("\n\n", 1);
  len = my_len_nb(game->nbr_col + 1);
  i = 1;
  data = game->data;
  while (data != NULL)
    {
      my_aff_begin(game, data, i++, len);
      my_aff_end(data);
      data = data->next;
    }
  my_putchar('\n', 1);
  return (0);
}
