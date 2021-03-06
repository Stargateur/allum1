##
## Makefile for allum1 in /home/plasko_a/rendu/Allum1
## 
## Made by Antoine Plaskowski
## Login   <plasko_a@epitech.net>
## 
## Started on  Tue Feb  4 14:46:24 2014 Antoine Plaskowski
## Last update Fri Feb 14 17:14:27 2014 Antoine Plaskowski
##

CC	=	gcc

RM	=	rm -f

CFLAGS	+=	-Wextra -Wall -O3 -g
CFLAGS	+=	-ansi -pedantic
CFLAGS	+=	-I include/

LDFLAGS	+=	-l ncurses

NAME	=	allum1

SRC	+=	src/main.c
SRC	+=	src/my_opt.c
SRC	+=	src/my_data.c
SRC	+=	src/my_aff_game.c
SRC	+=	src/my_aff_game_tc.c
SRC	+=	src/my_aff_game_no_tc.c
SRC	+=	src/my_allum1.c
SRC	+=	src/my_move_cur.c
SRC	+=	src/my_all.c
SRC	+=	src/my_ia.c
SRC	+=	src/my_aer_ia.c
SRC	+=	src/my_move_more.c
SRC	+=	src/my_hollande_ia.c
SRC	+=	src/my_chuck_norris_ia.c
SRC	+=	src/my_tool_ia.c
SRC	+=	src/my_put_error_msg.c
SRC	+=	src/my_aff_victory.c
SRC	+=	src/my_random.c
SRC	+=	src/my_player_no_tc.c
SRC	+=	src/my_player_tc.c
SRC	+=	src/my_load_map.c
SRC	+=	src/my_marinbad.c
SRC	+=	src/my_marinbad_ia.c

SRC	+=	src/my_putint.c
SRC	+=	src/my_tgetent.c
SRC	+=	src/my_tgetstr.c
SRC	+=	src/my_tcsetattr.c
SRC	+=	src/my_tcgetattr.c
SRC	+=	src/my_get_size.c
SRC	+=	src/my_term.c
SRC	+=	src/my_raw_mode.c
SRC	+=	src/my_echo.c
SRC	+=	src/my_clear.c

SRC	+=	src/my_putchar.c
SRC	+=	src/my_putstr.c
SRC	+=	src/my_putnbr.c
SRC	+=	src/my_strlen.c
SRC	+=	src/my_strncmp.c
SRC	+=	src/my_getnbr.c
SRC	+=	src/my_malloc.c
SRC	+=	src/my_get_next_line.c

SRC	+=	src/my_open.c

OBJ	=	$(SRC:.c=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
