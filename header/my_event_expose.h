/*
** my_event_expose.h for my_event_expose in /home/plasko_a/rendu/MUL_2013_wolf3d
** 
** Made by Antoine PLASKOWSKI
** Login   <plasko_a@epitech.net>
** 
** Started on  Sat Jan 11 22:50:14 2014 Antoine PLASKOWSKI
** Last update Sat Jan 11 22:53:40 2014 Antoine PLASKOWSKI
*/

#ifndef		MY_EVENT_EXPOSE_H_
# define	MY_EVENT_EXPOSE_H_

# include	<X11/Xlib.h>
# include	"my_x.h"

void		my_event_expose(t_xvar *xvar, XImage *img);

#endif		/* !MY_EVENT_EXPOSE_H_ */
