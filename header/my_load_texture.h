/*
** my_load_texture.h for my_load_texture in /home/plasko_a/rendu/MUL_2013_wolf3d
** 
** Made by Antoine PLASKOWSKI
** Login   <plasko_a@epitech.net>
** 
** Started on  Fri Jan 10 00:42:24 2014 Antoine PLASKOWSKI
** Last update Sun Jan 12 19:12:08 2014 Antoine PLASKOWSKI
*/

#ifndef		MY_LOAD_TEXTURE_H_
# define	MY_LOAD_TEXTURE_H_

# define	NBR_TEX			3

# include	"my_bmp.h"

t_bmp		**my_load_texture();
void		my_free_texture(t_bmp **tex);

#endif		/* !MY_LOAD_TEXTURE_H_ */
