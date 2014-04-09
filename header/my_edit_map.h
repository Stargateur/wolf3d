/*
** my_edit_map.h for my_edit_map in /home/plasko_a/rendu/MUL_2013_wolf3d
** 
** Made by Antoine PLASKOWSKI
** Login   <plasko_a@epitech.net>
** 
** Started on  Tue Jan  7 15:17:42 2014 Antoine PLASKOWSKI
** Last update Sun Jan 12 22:55:11 2014 Antoine PLASKOWSKI
*/

#ifndef		MY_EDIT_EDIT_H_
# define	MY_EDIT_EDIT_H_

# include	<X11/Xlib.h>
# include	"my_x.h"
# include	"my_bmp.h"
# include	"my_map.h"

typedef struct	s_edit_map
{
  XImage	*img;
  t_map		*map;
  t_bmp		**tex;
  char		*str;
  int		start_x;
  int		start_y;
  int		x;
  int		y;
  int		x_data;
  int		y_data;
  int		nbr_aff_x;
  int		nbr_aff_y;
  int		pix_per_img_x;
  int		pix_per_img_y;
  int		cur_tex;
  int		button;
}		t_edit_map;

int		my_edit_map(t_xvar *xvar, char *str);

#endif		/* !MY_EDIT_EDIT_H_ */
