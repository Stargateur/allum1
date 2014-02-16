/*
** my_load_map.c for my_load_map in /home/plasko_a/rendu/Allum1
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Thu Feb 13 18:10:33 2014 Antoine Plaskowski
** Last update Fri Feb 14 16:19:28 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my_allum1.h"
#include	"my_open.h"
#include	"my_str.h"
#include	"my_get_next_line.h"

static long	my_cur_all(long nbr_all, long *allum)
{
  long		i;
  long		j;

  i = 0;
  j = 0;
  while (i < nbr_all)
    if (allum[i++])
      j++;
  return (j);
}

static t_data	*my_map_to_data(t_data *data, long *allum, long nbr_all)
{
  t_data	*new_data;

  if ((new_data = my_malloc(sizeof(t_data))) == NULL)
    return (NULL);
  new_data->allum = allum;
  new_data->nbr_all = nbr_all;
  new_data->cur_all = my_cur_all(nbr_all, allum);
  new_data->next = NULL;
  if (data == NULL)
    {
      new_data->prev = NULL;
      return (new_data);
    }
  while (data->next != NULL)
    data = data->next;
  new_data->prev = data;
  data->next = new_data;
  return (new_data);
}

static long	my_put_all(long *allum, char *str)
{
  if (str == NULL)
    return (1);
  while (*str)
    if (*str++ != ' ')
      *allum++ = 1;
    else
      *allum++ = 0;
  return (0);
}

static long	my_load_map(t_game *game, char *map, const long fd)
{
  long		*allum;
  char		*str;

  if (game == NULL || map == NULL || fd == -1)
    return (1);
  game->nbr_col = 0;
  while (game->nbr_col < 43 && (str = my_get_next_line(fd, 0)) != NULL)
    {
      if ((allum = my_malloc(sizeof(long) * my_strlen(str))) == NULL)
	return (1);
      if (my_put_all(allum, str))
	return (1);
      if (!(game->data = my_map_to_data(game->data, allum, my_strlen(str))))
	return (1);
      free(str);
      game->nbr_col++;
    }
  if (game->data == NULL)
    return (1);
  while (game->data->prev != NULL)
    game->data = game->data->prev;
  game->cur_data = game->data;
  return (0);
}

long		my_map(char **argv, t_game *game)
{
  long		fd;
  char		*map;

  if (argv == NULL || game == NULL)
    return (1);
  game->data = NULL;
  if ((map = my_found_str(argv, "--map=")) == NULL)
    return (1);
  if ((fd = my_open_rdonly(map)) == -1)
    return (1);
  if (my_load_map(game, map, fd))
    {
      close(fd);
      return (1);
    }
  close(fd);
  game->map = 1;
  return (0);
}
