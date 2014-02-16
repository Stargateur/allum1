/*
** my_strlen.c for my_strlen in /home/plasko_a/rendu/Piscine-C-Jour_04
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Thu Oct  3 10:50:55 2013 Antoine Plaskowski
** Last update Wed Feb  5 10:55:06 2014 Antoine Plaskowski
*/

#include	<stdlib.h>

long		my_strlen(char *str)
{
  long		result;

  if (str == NULL)
    return (0);
  result = 0;
  while (*str++ != '\0')
    result++;
  return (result);
}
