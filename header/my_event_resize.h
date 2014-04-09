/*
** my_event_resize.h for my_event_resize in /home/plasko_a/rendu/MUL_2013_wolf3d
** 
** Made by Antoine PLASKOWSKI
** Login   <plasko_a@epitech.net>
** 
** Started on  Fri Jan  3 17:15:00 2014 Antoine PLASKOWSKI
** Last update Sun Jan 12 19:38:34 2014 Antoine PLASKOWSKI
*/

#ifndef		MY_EVENT_RESIZE_H_
# define	MY_EVENT_RESIZE_H_

# include	<X11/Xlib.h>
# include	"my_x.h"

XImage		*my_event_resize(t_xvar *xvar, XEvent *event,
				 XImage *img);

#endif		/* !MY_EVENT_RESIZE_H_ */
