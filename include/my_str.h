/*
** my_str.h for my_str in /home/plasko_a/rendu/Allum1
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed Feb  5 10:50:36 2014 Antoine Plaskowski
** Last update Fri Feb 14 17:14:39 2014 Antoine Plaskowski
*/

#ifndef		MY_STR_H_
# define	MY_STR_H_

long		my_putchar(const char c, const long fd);
long		my_putstr(const char *str, const long fd);
long		my_putnbr(long nb, const long fd);
long		my_strlen(const char *str);
long		my_strncmp(const char *s1, const char *s2, const long n);
long		my_getnbr(const char *str);
void		*my_malloc(unsigned long nbr_octect);
void		*my_calloc(unsigned long nbr_octect);

#endif		/* !MY_STR_H_ */
