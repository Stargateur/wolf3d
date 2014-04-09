/*
** my_put_pixel_to_img.c for my_put_pixel_to_img in /home/plasko_a/Documents/PROJET/tp2
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Tue Nov 12 17:39:21 2013 Antoine Plaskowski
** Last update Sun Jan 12 03:43:04 2014 Antoine PLASKOWSKI
*/

#include	<stdlib.h>
#include	<X11/Xlib.h>
#include	"my_struct_color.h"

int             my_put_pixel_to_img(XImage *img, t_color *color, int x)
{
  if (img == NULL || color == NULL || x < 0)
    return (1);
  if (x < 0 || x > img->height * img->width * 4 - 4)
    return (1);
  img->data[x] = color->r;
  img->data[x + 1] = color->v;
  img->data[x + 2] = color->b;
  img->data[x + 3] = color->opacity;
  return (0);
}
