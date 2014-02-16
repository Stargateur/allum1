/*
** my_get_next_line.h for my_get_next_line in /home/plasko_a/rendu/Allum1
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Wed Feb 12 15:22:45 2014 Antoine Plaskowski
** Last update Wed Feb 12 16:37:16 2014 Antoine Plaskowski
*/

#ifndef			MY_GET_NEXT_LINE_H_
# define		MY_GET_NEXT_LINE_H_

# define		BUF			4096

typedef struct		s_nline
{
  struct s_nline	*prev;
  char			*str;
  struct s_nline	*next;
}			t_nline;

char			*my_get_next_line(const int fd, const int reset);

#endif			/* MY_GET_NEXT_LINE_H_ */
