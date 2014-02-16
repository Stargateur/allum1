/*
** my_term.c for my_term in /home/plasko_a/rendu/PSU_2013_my_select
** 
** Made by Antoine PLASKOWSKI
** Login   <plasko_a@epitech.net>
** 
** Started on  Tue Jan 14 16:45:47 2014 Antoine PLASKOWSKI
** Last update Wed Feb  5 13:27:49 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_str.h"

char		*my_term(char **env)
{
  if (env == NULL)
    return (NULL);
  while (*env)
    {
      if (my_strncmp("TERM=", *env, 5) == 0)
	return (*env + 5);
      env++;
    }
  return (NULL);
}
