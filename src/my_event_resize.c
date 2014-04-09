/*
** my_event_resize.c for my_event_resize in /home/plasko_a/rendu/MUL_2013_wolf3d/src
** 
** Made by Antoine PLASKOWSKI
** Login   <plasko_a@epitech.net>
** 
** Started on  Fri Jan  3 09:42:08 2014 Antoine PLASKOWSKI
** Last update Sun Jan 12 10:09:34 2014 Antoine PLASKOWSKI
*/

#include	<X11/Xlib.h>
#include	<X11/Xutil.h>
#include	"my_x.h"

XImage		*my_event_resize(t_xvar *xvar, XEvent *event, XImage *img)
{
  xvar->x = event->xresizerequest.width;
  xvar->y = event->xresizerequest.height;
  XDestroyWindow(xvar->dpy, xvar->win);
  XDestroyImage(img);
  my_create_window(xvar);
  if ((img = my_create_image(xvar, NULL, xvar->x, xvar->y)) == NULL)
    return (NULL);
  return (img);
}
