/*
** my_aff_game.c for my_aff_game in /home/plasko_a/rendu/Allum1
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed Feb  5 14:01:57 2014 Antoine Plaskowski
** Last update Wed Feb 12 16:36:36 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_allum1.h"

long		my_aff_game(t_game *game)
{
  if (game->termcaps)
    return (my_aff_game_tc(game));
  return (my_aff_game_no_tc(game));
}
