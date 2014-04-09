/*
** my_menu.h for my_menu in /home/plasko_a/rendu/MUL_2013_wolf3d
** 
** Made by Antoine PLASKOWSKI
** Login   <plasko_a@epitech.net>
** 
** Started on  Fri Jan  3 17:23:56 2014 Antoine PLASKOWSKI
** Last update Sun Jan 12 22:54:33 2014 Antoine PLASKOWSKI
*/

#ifndef		MY_MENU_H_
# define	MY_MENU_H_

# define	RESIZE		8
# define	NBR_TEX_MENU	5

# include	<X11/Xlib.h>
# include	"my_bmp.h"
# include	"my_x.h"

typedef struct	s_menu
{
  XImage	*img;
  char		*name_map;
  t_bmp		**tex;
}		t_menu;

int		my_menu(t_xvar *xvar, char *name_map);
int		my_event_menu(t_xvar *xvar, t_menu *menu, XEvent *event);

#endif		/* !MY_MENU_H_ */
