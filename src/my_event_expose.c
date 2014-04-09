/*
** my_event_expose.c for my_event_expose in /home/plasko_a/rendu/MUL_2013_wolf3d
** 
** Made by Antoine PLASKOWSKI
** Login   <plasko_a@epitech.net>
** 
** Started on  Sat Jan 11 22:37:35 2014 Antoine PLASKOWSKI
** Last update Sat Jan 11 22:56:07 2014 Antoine PLASKOWSKI
*/

#include	<X11/Xlib.h>
#include	"my_x.h"

void		my_event_expose(t_xvar *xvar, XImage *img)
{
  XPutImage(xvar->dpy, xvar->win, xvar->gc, img, 0, 0, 0, 0,
	    img->width, img->height);
}
