/*
** my_struct_color.c for my_struct_color in /home/plasko_a/Documents/PROJET/tp2
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Tue Nov 12 15:27:20 2013 Antoine Plaskowski
** Last update Sun Jan 12 18:29:46 2014 Antoine PLASKOWSKI
*/

#include	<stdlib.h>
#include	"my_struct_color.h"
#include	"my_bmp.h"
#include	"my_str.h"

int		my_set_color(t_color *color, unsigned char r,
			     unsigned char v, unsigned char b)
{
  if (color == NULL)
    return (1);
  color->r = r;
  color->v = v;
  color->b = b;
  color->opacity = 255;
  return (0);
}

int		my_get_color(t_color *color, t_bmp *bmp, int x)
{
  if (color == NULL || bmp == NULL || x < 0 ||
      x > bmp->h_img->x * bmp->h_img->y * 4)
    return (1);
  color->r = bmp->img[x++];
  color->v = bmp->img[x++];
  color->b = bmp->img[x++];
  color->opacity = bmp->img[x];
  return (1);
}
