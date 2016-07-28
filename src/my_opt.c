/*
** my_opt.c for my_opt in /home/plasko_a/rendu/Allum1
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed Feb 12 13:55:25 2014 Antoine Plaskowski
** Last update Tue Feb 24 22:54:35 2015 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<term.h>
#include	<time.h>
#include	"my_termcaps.h"
#include	"my_allum1.h"
#include	"my_str.h"

char		*my_found_str(char **argv, const char *str)
{
  long		len;

  if (argv == NULL)
    return (NULL);
  len = my_strlen(str);
  while (*argv)
    {
      if (!my_strncmp(*argv, str, len))
	return (*argv + len);
      argv++;
    }
  return (NULL);
}

long		my_help(char **argv)
{
  if (argv == NULL)
    return (1);
  if (my_found_str(argv, "--help") != NULL)
    {
      my_putstr("--size=4(1-42)\n", 2);
      my_putstr("--player=1(0-2)\n", 2);
      my_putstr("--map=None(path)\n", 2);
      my_putstr("--tc=1(0-1)\n", 2);
      my_putstr("--mode=0(0-1)\n", 2);
      my_putstr("--level=2(0-2)\n", 2);
      return (1);
    }
  return (0);
}

long		my_nbr_col(char **argv)
{
  char		*str;
  long		size;

  if ((str = my_found_str(argv, "--size=")) != NULL)
    {
      size = my_getnbr(str);
      if (size > 0 && size <= 42)
	return (size);
    }
  return (0);
}

long		my_define_player(char **argv, t_game *game)
{
  char		*str;
  long		nbr_player;

  if (game == NULL)
    return (1);
  game->type_player[0] = 1;
  game->type_player[1] = 0;
  if ((str = my_found_str(argv, "--player=")) != NULL)
    {
      nbr_player = my_getnbr(str);
      if (nbr_player >= 0 && nbr_player <= 2)
	{
	  game->type_player[0] = nbr_player;
	  if (nbr_player)
	    nbr_player--;
	  game->type_player[1] = nbr_player;
	}
    }
  return (0);
}

long		my_level_ia(char **argv, t_game *game)
{
  char		*str;
  long		level;

  if (game == NULL)
    return (1);
  game->level_ia = 2;
  if ((str = my_found_str(argv, "--level=")) != NULL)
    {
      level = my_getnbr(str);
      if (level >= 0 && level <= 2)
	game->level_ia = level;
    }
  return (0);
}
