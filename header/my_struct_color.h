/*
** my_struct_color.h for my_struct_color in /home/plasko_a/Documents/PROJET/tp2
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Tue Nov 12 15:29:10 2013 Antoine Plaskowski
** Last update Sun Jan 12 18:28:35 2014 Antoine PLASKOWSKI
*/

#ifndef		MY_STRUCT_COLOR_H_
# define	MY_STRUCT_COLOR_H_

#include	"my_struct_color.h"
#include	"my_bmp.h"

typedef struct	s_color
{
  unsigned char	r;
  unsigned char	v;
  unsigned char	b;
  unsigned char	opacity;
}		t_color;

int		my_set_color(t_color *color, unsigned char r,
			     unsigned char v, unsigned char b);
int		my_get_color(t_color *color, t_bmp *bmp, int x);

#endif		/* !MY_STRUCT_COLOR */

