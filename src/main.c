/*
** main.c for tp1 in /home/plasko_a/Documents/PROJET/tp1minilib
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Tue Nov  5 14:11:49 2013 Antoine Plaskowski
** Last update Sun Feb 16 22:59:11 2014 Antoine Plaskowski
*/

#include		<stdlib.h>
#include		<term.h>
#include		<time.h>
#include		"my_termcaps.h"
#include		"my_allum1.h"
#include		"my_str.h"

static long		my_init_term(char **argv, char **env)
{
  char			*term;

  if ((term = my_found_str(argv, "--tc=")) != NULL && my_getnbr(term) == 0)
    return (1);
  if ((term = my_term(env)) == NULL)
    {
      my_putstr("NO TERM IN ENV\n", 2);
      return (1);
    }
  if (my_tgetent(term))
    return (1);
  return (0);
}

static long		my_init(char **argv, t_game *game)
{
  char			*str;

  if (game == NULL || argv == NULL)
    return (1);
  if (my_define_player(argv, game))
    return (1);
  if (my_level_ia(argv, game))
    return (1);
  game->mode = 0;
  if ((str = my_found_str(argv, "--mode=")) != NULL)
    game->mode = my_getnbr(str);
  if ((game->nbr_col = my_nbr_col(argv)) == 0 && game->mode == 0)
    game->nbr_col = 4;
  game->pos_col = 0;
  game->pos_all = 0;
  game->who_play = 0;
  game->data = NULL;
  game->map = 0;
  return (0);
}

int			main(int argc, char **argv, char **env)
{
  struct termios	save;
  struct termios	t;
  t_game		game;

  argv[argc] = NULL;
  if (my_help(argv) || my_init(argv, &game))
    return (1);
  srand(time(NULL));
  if (my_marinbad(&game) && my_map(argv, &game) && my_init_data(&game))
    return (1);
  if ((game.termcaps = 1 - my_init_term(argv, env)))
    {
      if (my_tcgetattr(&save) || my_tcgetattr(&t))
	return (1);
      if (my_echo_off(&t) || my_raw_mode(&t))
	return (1);
      my_allum1(&game);
      if (my_tcsetattr(&save))
	return (1);
    }
  else
    my_allum1(&game);
  return (0);
}
