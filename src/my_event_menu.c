/*
** my_event_menu.c for my_event_menu in /home/plasko_a/rendu/MUL_2013_wolf3d/src
** 
** Made by Antoine PLASKOWSKI
** Login   <plasko_a@epitech.net>
** 
** Started on  Sun Jan 12 19:29:24 2014 Antoine PLASKOWSKI
** Last update Sun Jan 12 22:33:42 2014 Antoine PLASKOWSKI
*/

#include	<X11/Xutil.h>
#include	<stdlib.h>
#include	"my_x.h"
#include	"my_str.h"
#include	"my_menu.h"
#include	"my_game.h"
#include	"my_edit_map.h"
#include	"my_load_texture.h"
#include	"my_event_resize.h"

static int	my_check_button(t_xvar *xvar, XEvent *event, int i)
{
  int		min_x;
  int		max_x;
  int		min_y;
  int		max_y;

  min_x = xvar->x / 2 - xvar->x / (2 * RESIZE);
  max_x = xvar->x / 2 + xvar->x / (2 * RESIZE);
  min_y = i * xvar->y / 4 + xvar->y / 8 - xvar->y / (2 * RESIZE);
  max_y = i * xvar->y / 4 + xvar->y / 8 + xvar->y / (2 * RESIZE);
  return (event->xmotion.x >= min_x && event->xmotion.x < max_x &&
	  event->xmotion.y >= min_y && event->xmotion.y < max_y);
}

static int	my_check_mouse(t_xvar *xvar, t_menu *menu, XEvent *event)
{
  int		i;

  i = 0;
  while (i < 4)
    {
      if (my_check_button(xvar, event, i))
	{
	  if (i == 0)
	    my_game(xvar, menu->name_map);
	  else if (i == 1)
	    my_putstr("FEATURE INCOMING\n", 2);
	  else if (i == 2)
	    my_edit_map(xvar, menu->name_map);
	  else if (i == 3)
	    return (1);
	  XDestroyImage(menu->img);
	  if (!(menu->img = my_create_image(xvar, NULL, xvar->x, xvar->y)))
	    return (1);
	}
      i++;
    }
  return (0);
}

int		my_event_menu(t_xvar *xvar, t_menu *menu, XEvent *event)
{
  if ((event->type == KeyPress && event->xkey.keycode == 9) ||
      (event->type == ButtonPress && my_check_mouse(xvar, menu, event)))
    {
      XDestroyImage(menu->img);
      my_free_texture(menu->tex);
      return (1);
    }
  else if (event->type == ResizeRequest)
    {
      if ((menu->img = my_event_resize(xvar, event, menu->img)) == NULL)
	return (1);
    }
  return (0);
}
