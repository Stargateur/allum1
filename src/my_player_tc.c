/*
** my_player_tc.c for my_player_tc in /home/plasko_a/rendu/Allum1
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed Feb 12 16:02:22 2014 Antoine Plaskowski
** Last update Wed Feb 12 16:38:09 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my_allum1.h"

static long	my_set_zero_buf(char *buf)
{
  if (buf == NULL)
    return (0);
  buf[0] = 0;
  buf[1] = 0;
  buf[2] = 0;
  return (1);
}

long		my_player_tc(t_game *game)
{
  char		buf[3];

  if (game == NULL)
    return (1);
  while (my_set_zero_buf(buf) && read(0, buf, 3))
    {
      if (buf[0] == 4 || (buf[0] == 27 && buf[1] == 0 && buf[2] == 0))
        return (1);
      else if (buf[0] == 32)
        {
          my_change_all(game);
          my_aff_game(game);
        }
      else if (buf[0] == 10)
        {
          if (my_remove_all(game) == 0)
            return (0);
        }
      else
        my_move(game, buf);
    }
  return (1);
}

