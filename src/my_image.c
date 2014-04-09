/*
** my_image.c for my_image in /home/plasko_a/rendu/MUL_2013_wolf3d
** 
** Made by Antoine PLASKOWSKI
** Login   <plasko_a@epitech.net>
** 
** Started on  Fri Jan  3 13:01:02 2014 Antoine PLASKOWSKI
** Last update Sun Jan 12 18:55:02 2014 Antoine PLASKOWSKI
*/

#include	<X11/Xlib.h>
#include	"my_struct_color.h"
#include	"my_struct_coord.h"
#include	"my_put_pixel_to_img.h"
#include	"my_bmp.h"

int		my_set_image_to_zero(XImage *img)
{
  int		i;
  int		j;
  int		y;
  int		x;

  i = 0;
  while (i < img->height)
    {
      j = 0;
      y = i * img->width;
      while (j < img->width)
	{
	  x = (y + j++) * 4;
	  img->data[x++] = 0;
	  img->data[x++] = 0;
	  img->data[x++] = 0;
	  img->data[x] = 0;
	}
      i++;
    }
  return (0);
}

int		my_put_image_to_image(t_coord *pos_0, t_coord *pos_1,
				      t_bmp *bmp, XImage *img)
{
  t_color       color;
  double	tmp_x;
  double	tmp_y;
  int		i;
  int		j;
  int		pixel;

  i = pos_0->x;
  while (i < pos_1->x)
    {
      tmp_x = (i - pos_0->x) * bmp->h_img->x / (pos_1->x - pos_0->x);
      j = pos_0->y;
      while (j < pos_1->y)
	{
	  tmp_y = (j - pos_0->y) * bmp->h_img->y / (pos_1->y - pos_0->y);
	  pixel = (tmp_y * bmp->h_img->x + tmp_x) * 4;
	  my_get_color(&color, bmp, pixel);
	  my_put_pixel_to_img(img, &color, (j++ * img->width + i) * 4);
	}
      i++;
    }
  return (0);
}
