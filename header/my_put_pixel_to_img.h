/*
** my_put_pixel_to_img.h for my_put_pixel_to_img in /home/plasko_a/Documents/PROJET/tp2
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Tue Nov 12 17:44:10 2013 Antoine Plaskowski
** Last update Sun Jan 12 03:43:32 2014 Antoine PLASKOWSKI
*/

#ifndef		MY_PUT_PIXEL_TO_IMG_H_
# define	MY_PUT_PIXEL_TO_IMG_H_

# include	<X11/Xlib.h>
# include	"my_struct_color.h"

int		my_put_pixel_to_img(XImage *img, t_color *color, int x);

#endif		/* !MY_PUT_PIXEL_TO_IMG_H_ */
