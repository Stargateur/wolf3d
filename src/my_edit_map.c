/*
** my_edit_map.c for my_edit_map in /home/plasko_a/rendu/MUL_2013_wolf3d
** 
** Made by Antoine PLASKOWSKI
** Login   <plasko_a@epitech.net>
** 
** Started on  Tue Jan  7 15:19:00 2014 Antoine PLASKOWSKI
** Last update Sun Jan 12 22:03:47 2014 Antoine PLASKOWSKI
*/

#include	<X11/Xlib.h>
#include	<X11/Xutil.h>
#include	<stdlib.h>
#include	"my_x.h"
#include	"my_bmp.h"
#include	"my_map.h"
#include	"my_edit_map.h"
#include	"my_load_texture.h"
#include	"my_event_resize.h"
#include	"my_event_expose.h"
#include	"my_event_e_m_motion_notify.h"
#include	"my_event_e_m_key_press.h"
#include	"my_struct_color.h"
#include	"my_put_pixel_to_img.h"
#include	"my_image.h"

static int	my_init_edit_map(t_edit_map *e_m, XEvent *event)
{
  if ((e_m->map = my_load_map(e_m->str, 0)) == NULL)
    return (1);
  if ((e_m->tex = my_load_texture()) == NULL)
    return (1);
  e_m->nbr_aff_x = e_m->map->x;
  e_m->nbr_aff_y = e_m->map->y;
  e_m->cur_tex = e_m->map->tab[0][0];
  event->xmotion.x = 0;
  event->xmotion.y = 0;
  e_m->button = 0;
  e_m->start_x = 0;
  e_m->start_y = 0;
  return (0);
}

static void	my_draw_image_in_image(t_xvar *xvar, t_edit_map *e_m, int t)
{
  t_color	color;
  int		tmp_x;
  int		tmp_y;
  int		i;
  int		j;
  int		pixel;
  int		x_deca;

  i = 0;
  while (i < e_m->pix_per_img_x)
    {
      x_deca = e_m->x_data + i;
      tmp_x = i * 100 / (e_m->pix_per_img_x) * e_m->tex[t]->h_img->x / 100;
      j = 0;
      while (j < e_m->pix_per_img_y)
	{
	  tmp_y = j * 100 / (e_m->pix_per_img_y) * e_m->tex[t]->h_img->y / 100;
	  pixel = (tmp_y * e_m->tex[t]->h_img->x + tmp_x) * 4;
	  my_get_color(&color, e_m->tex[t], pixel);
	  my_put_pixel_to_img(e_m->img, &color,
			      ((e_m->y_data + j) * xvar->x + x_deca) * 4);
	  j++;
	}
      i++;
    }
}

static int	my_img_edit_map(t_xvar *xvar, t_edit_map *e_m, XEvent *event)
{
  int		x_map;
  int		y_map;

  my_set_image_to_zero(e_m->img);
  e_m->pix_per_img_x = xvar->x / e_m->nbr_aff_x;
  e_m->pix_per_img_y = xvar->y / e_m->nbr_aff_y;
  e_m->x = 0;
  while (e_m->x < e_m->nbr_aff_x)
    {
      e_m->x_data = e_m->x * e_m->pix_per_img_x;
      e_m->y = 0;
      x_map = e_m->nbr_aff_x - e_m->x - 1 + e_m->start_x;
      while (e_m->y < e_m->nbr_aff_y)
  	{
  	  e_m->y_data = e_m->y * e_m->pix_per_img_y;
  	  y_map = e_m->nbr_aff_y - e_m->y - 1 + e_m->start_y;
  	  my_draw_image_in_image(xvar, e_m, e_m->map->tab[y_map][x_map]);
  	  e_m->y++;
  	}
      e_m->x++;
    }
  e_m->x_data = event->xmotion.x;
  e_m->y_data = event->xmotion.y;
  my_draw_image_in_image(xvar, e_m, e_m->cur_tex);
  return (0);
}

static int	my_event_edit_map(t_xvar *xvar, t_edit_map *e_m,
				  XEvent *event)
{
  if (event->type == KeyPress && event->xkey.keycode == 9)
    {
      XDestroyImage(e_m->img);
      return (1);
    }
  else if (event->type == ResizeRequest)
    {
      if ((e_m->img = my_event_resize(xvar, event, e_m->img)) == NULL)
	return (1);
    }
  else if (event->type == ButtonRelease)
    {
      e_m->button = 0;
      event->xmotion.x = event->xbutton.x;
      event->xmotion.y = event->xbutton.y;
    }
  else if (event->type == ButtonPress)
    e_m->button = 1;
  else if (event->type == KeyPress)
    my_event_e_m_key_press(e_m, event);
  return (0);
}

int		my_edit_map(t_xvar *xvar, char *str)
{
  XEvent	event;
  t_edit_map	e_m;

  e_m.str = str;
  if (my_init_edit_map(&e_m, &event))
    return (1);
  if ((e_m.img = my_create_image(xvar, NULL, xvar->x, xvar->y)) == NULL)
    return (1);
  while (42)
    {
      my_img_edit_map(xvar, &e_m, &event);
      my_event_expose(xvar, e_m.img);
      my_event_e_m_motion_notify(&e_m, &event);
      while (XPending(xvar->dpy))
	{
	  XNextEvent(xvar->dpy, &event);
	  if (my_event_edit_map(xvar, &e_m, &event))
	    {
	      my_free_texture(e_m.tex);
	      my_free_map(e_m.map);
	    return (0);
	    }
	}
    }
  return (0);
}
