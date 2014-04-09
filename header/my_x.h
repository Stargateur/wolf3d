/*
** my_x.h for my_x in /home/plasko_a/rendu/MUL_2013_wolf3d
** 
** Made by Antoine PLASKOWSKI
** Login   <plasko_a@epitech.net>
** 
** Started on  Fri Jan  3 10:09:09 2014 Antoine PLASKOWSKI
** Last update Fri Jan  3 10:09:10 2014 Antoine PLASKOWSKI
*/

#ifndef		MY_X_H_
# define	MY_X_H_

# include	<X11/Xlib.h>

typedef struct	s_xvar
{
  Display	*dpy;
  GC		gc;
  Window	win;
  int		x;
  int		y;
  int		scn;
}		t_xvar;

XImage		*my_create_image(t_xvar *xvar, char *img, int x, int y);
void		my_create_window(t_xvar *xvar);
t_xvar		*my_init();

#endif		/* !MY_X_H_ */
