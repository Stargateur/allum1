/*
** my_termcaps.h for my_termcaps in /home/plasko_a/rendu/Allum1
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed Feb  5 13:21:49 2014 Antoine Plaskowski
** Last update Wed Feb 12 13:20:54 2014 Antoine Plaskowski
*/

#ifndef		MY_TERMCAPS_H_
# define	MY_TERMCAPS_H_

/*
**		<sys/ioctl.h> for struct winsize
**		<term.h> for struct termios
*/

# include	<sys/ioctl.h>
# include	<term.h>

/*
**		my_term.c
*/

char		*my_term(char **env);

/*
**		my_tgetent.c
*/

long		my_tgetent(const char *name);

/*
**		my_tgetstr.c
*/

char		*my_tgetstr(const char *str);

/*
**		my_get_size.c
*/

long		my_get_size(struct winsize *w);

/*
**		my_putint.c
*/

int		my_putint(const int nb);

/*
**		my_tcgetattr.c
*/

long		my_tcgetattr(struct termios *t);

/*
**		my_tcsetattr.c
*/

long		my_tcsetattr(struct termios *t);

/*
**		my_raw_mode.c
*/

long		my_raw_mode(struct termios *t);

/*
**		my_echo.c
*/

long		my_echo_off(struct termios *t);

/*
**		my_clear.c
*/

long		my_clear(void);

#endif		/* !MY_TERMCAPS_H_ */
