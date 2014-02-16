/*
** my_allum1.h for my_allum1 in /home/plasko_a/rendu/Allum1
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed Feb  5 11:24:40 2014 Antoine Plaskowski
** Last update Fri Feb 14 16:20:26 2014 Antoine Plaskowski
*/

#ifndef		MY_ALLUM1_H_
# define	MY_ALLUM1_H_

# define	SPEED_IA	100000

/*
**		contains data to matches
*/

typedef struct	s_data
{
  struct s_data	*prev;
  long		*allum;
  long		nbr_all;
  long		cur_all;
  struct s_data	*next;
}		t_data;

typedef struct	s_game
{
  struct s_data	*data;
  struct s_data *cur_data;
  long		nbr_col;
  long		pos_col;
  long		pos_all;
  long		who_play;
  long		level_ia;
  long		termcaps;
  long		map;
  long		mode;
  long		type_player[2];
}		t_game;

/*
**		my_opt.c
*/

char		*my_found_str(char **argv, const char *str);
long		my_help(char **argv);
long		my_nbr_col(char **argv);
long		my_define_player(char **argv, t_game *game);
long		my_level_ia(char **argc, t_game *game);

/*
**		my_data.c
*/

long		my_init_data(t_game *game);
void		my_free_data(t_data *data);
void		my_aff_data(t_data *data);
long		my_max_all(t_data *data);

/*
**		my_aff_game.c
*/

long		my_aff_game(t_game *game);

/*
**		my_aff_game_no_tc.c
*/

long		my_aff_game_no_tc(t_game *game);

/*
**		my_aff_game_tc.c
*/

long		my_aff_game_tc(t_game *game);

/*
**		my_allum1.c
*/

long		my_allum1(t_game *game);

/*
**		my_player_no_tc.c
*/

long		my_player_no_tc(t_game *game);

/*
**		my_player_tc.c
*/

long		my_player_tc(t_game *game);

/*
**		my_move_cur.c
*/

long		my_move_cur(t_game *game);
long		my_move(t_game *game, const char *buf);
long		my_move_left(t_game *game);
long		my_move_right(t_game *game);

/*
**		my_all.c
*/

long		my_change_all(t_game *game);
long		my_remove_all(t_game *game);
long		my_game_is_not_finish(t_data *data);

/*
**		my_move_more.c
*/

long		my_move_down(t_game *game);
long		my_move_up(t_game *game);

/*
**		my_ia.c
*/

long		my_ia(t_game *game);
long		my_remove_one(t_game *game, t_data *data);

/*
**		my_tool_ia.c
*/

t_data		*my_found_data(t_game *game);
long		my_verif(t_data *data);
long		my_end(t_data *data);
long		my_ctp(t_data *data);
long		my_aff_move_ia(t_game *game);

/*
**		my_aer_ia.c
*/

long		my_aer_ia(t_game *game);

/*
**		my_hollande_ia.c
*/

long		my_hollande_ia(t_game *game);

/*
**		my_chuck_norris_ia.c
*/

long		my_chuck_norris_ia(t_game *game);

/*
**		my_put_error_msg.c
*/

long		my_error_select(t_game *game);

/*
**		my_aff_victory.c
*/

long		my_aff_victory(t_game *game);

/*
**		my_random.c
*/

long		my_remove_random(t_game *game, t_data *data);
t_data		*my_random_data(t_data *data);

/*
**		my_load_map.c
*/

long		my_map(char **argv, t_game *game);

/*
**		my_marinbad_ia.c
*/

long		my_marinbad_ia(t_game *game);

/*
**		my_marinbad.c
*/

long		my_marinbad(t_game *game);

#endif		/* !MY_ALLUM1_H_ */
