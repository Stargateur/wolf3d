/*
** my_k.h for my_k in /home/plasko_a/rendu/MUL_2013_wolf3d
** 
** Made by Antoine PLASKOWSKI
** Login   <plasko_a@epitech.net>
** 
** Started on  Wed Jan  8 10:22:34 2014 Antoine PLASKOWSKI
** Last update Sun Jan 12 19:44:56 2014 Antoine PLASKOWSKI
*/

#ifndef		MY_K_H_
# define	MY_K_H_

# include	"my_map.h"
# include	"my_game.h"
# include	"my_struct_color.h"

typedef struct	s_kvar
{
  t_color	*sky;
  t_color	*ground;
  double	k;
  double	k_x;
  double	k_y;
  double	v_x;
  double	v_y;
  double	s_wall;
  double	pos_x;
  double	tmp_x;
  int		img_x;
  int		player_x;
  int		player_y;
  int		slope_x;
  int		slope_y;
  int		deca_x;
  int		deca_y;
  int		x;
  int		y;
}		t_kvar;

int		my_k(t_map *map, t_player *player,
		     t_kvar *kvar, double *coord);

#endif		/* !MY_K_H_ */
