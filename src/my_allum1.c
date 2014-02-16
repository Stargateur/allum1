/*
** my_allum1.c for my_allum1 in /home/plasko_a/rendu/Allum1
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Thu Feb  6 13:52:11 2014 Antoine Plaskowski
** Last update Thu Feb 13 21:27:51 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my_allum1.h"
#include	"my_termcaps.h"

static long	my_quit(t_game *game)
{
  if (game != NULL)
    my_free_data(game->data);
  if (game != NULL && game->termcaps)
    my_clear();
  return (0);
}

static long	my_player(t_game *game)
{
  if (game->termcaps)
    return (my_player_tc(game));
  return (my_player_no_tc(game));
}

long		my_allum1(t_game *game)
{
  if (game == NULL)
    return (my_quit(game));
  while (my_game_is_not_finish(game->data))
    {
      my_aff_game(game);
      if (game->type_player[game->who_play])
	{
	  if (my_player(game))
	    return (my_quit(game));
	}
      else
	{
	  if (my_ia(game))
	    return (my_quit(game));
	}
      game->who_play = 1 - game->who_play;
    }
  my_aff_game(game);
  my_aff_victory(game);
  return (my_quit(game));
}
