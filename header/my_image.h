/*
** my_image.h for my_image in /home/plasko_a/rendu/MUL_2013_wolf3d
** 
** Made by Antoine PLASKOWSKI
** Login   <plasko_a@epitech.net>
** 
** Started on  Fri Jan  3 13:17:24 2014 Antoine PLASKOWSKI
** Last update Sun Jan 12 18:20:15 2014 Antoine PLASKOWSKI
*/

#ifndef		MY_IMAGE_H_
# define	MY_IMAGE_H_

# include	<X11/Xlib.h>
# include	"my_bmp.h"
# include	"my_struct_coord.h"

int		my_set_image_to_zero(XImage *img);
int		my_put_image_to_image(t_coord *pos_0, t_coord *pos_1,
				      t_bmp *bmp, XImage *img);

#endif		/* MY_IMAGE_H_ */
