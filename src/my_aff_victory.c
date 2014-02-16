/*
** my_aff_victory.c for my_aff_victory in /home/plasko_a/rendu/Allum1
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Tue Feb 11 05:00:46 2014 Antoine Plaskowski
** Last update Sun Feb 16 23:00:58 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my_termcaps.h"
#include	"my_allum1.h"
#include	"my_str.h"

long		my_aff_victory(t_game *game)
{
  char		*cm;
  char		tmp[3];

  if (game == NULL)
    return (1);
  if (game->termcaps)
    {
      if ((cm = my_tgetstr("cm")) == NULL)
	return (1);
      my_clear();
      tputs(tgoto(cm, 1, 1), 0, &my_putint);
      my_putstr("The player ", 0);
      my_putnbr(game->who_play + 1, 0);
      my_putstr(" win !!!", 0);
      tputs(tgoto(cm, 1, 3), 0, &my_putint);
      my_putstr("Press any key to continue", 0);
      read(0, &tmp, 3);
    }
  else
    {
      my_putstr("The player ", 1);
      my_putnbr(game->who_play + 1, 1);
      my_putstr(" win !!!\n", 1);
    }
  return (0);
}
