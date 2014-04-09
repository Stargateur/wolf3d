/*
** my_game.h for my_game in /home/plasko_a/rendu/MUL_2013_wolf3d
** 
** Made by Antoine PLASKOWSKI
** Login   <plasko_a@epitech.net>
** 
** Started on  Tue Jan  7 16:49:18 2014 Antoine PLASKOWSKI
** Last update Sun Jan 12 22:51:35 2014 Antoine PLASKOWSKI
*/

#ifndef		MY_GAME_H_
# define	MY_GAME_H_

# define	MY_PI		3.14159265359

# include	"my_x.h"
# include	"my_map.h"
# include	"my_bmp.h"

typedef struct	s_player
{
  double	x;
  double	y;
  double	ang;
}		t_player;

typedef struct	s_key
{
  int		a;
  int		e;
  int		z;
  int		s;
  int		q;
  int		d;
}		t_key;

typedef struct	timeval t_timeval;

typedef struct	s_game
{
  t_map		*map;
  t_player	*player;
  XImage	*img;
  double	*coord;
  t_bmp		**tex;
  t_key		*key;
}		t_game;

int		my_game(t_xvar *xvar, char *str);
int		my_img_game(t_xvar *xvar, t_game *game);
double		*my_init_coord(t_xvar *xvar);

t_key		*my_init_key();
int		my_set_key(t_game *game, XEvent *event);
int		my_unset_key(t_game *game, XEvent *event);

t_player	*my_init_player(t_map *map);
void		my_control_player(t_game *game);

#endif		/* !MY_GAME_H_ */
