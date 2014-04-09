/*
** my_menu.c for my_menu in /home/plasko_a/rendu/MUL_2013_wolf3d
** 
** Made by Antoine PLASKOWSKI
** Login   <plasko_a@epitech.net>
** 
** Started on  Fri Jan  3 10:08:18 2014 Antoine PLASKOWSKI
** Last update Sun Jan 12 22:51:55 2014 Antoine PLASKOWSKI
*/

#include	<X11/Xlib.h>
#include	<X11/Xutil.h>
#include	<stdlib.h>
#include	"my_x.h"
#include	"my_bmp.h"
#include	"my_str.h"
#include	"my_menu.h"
#include	"my_game.h"
#include	"my_edit_map.h"
#include	"my_struct_coord.h"
#include	"my_struct_color.h"
#include	"my_event_resize.h"
#include	"my_event_expose.h"
#include	"my_image.h"

static int	my_img_menu(t_xvar *xvar, t_menu *menu)
{
  t_coord	pos_0;
  t_coord	pos_1;
  int		i;

  my_set_coord(&pos_0, 0, 0);
  my_set_coord(&pos_1, xvar->x, xvar->y);
  my_put_image_to_image(&pos_0, &pos_1, menu->tex[0], menu->img);
  i = 0;
  while (i < NBR_TEX_MENU - 1)
    {
      my_set_coord(&pos_0, xvar->x / 2 - xvar->x / (2 * RESIZE),
		   i * xvar->y / 4 + xvar->y / 8 - xvar->y / (2 * RESIZE));
      my_set_coord(&pos_1, xvar->x / 2 + xvar->x / (2 * RESIZE),
		   i * xvar->y / 4 + xvar->y / 8 + xvar->y / (2 * RESIZE));
      my_put_image_to_image(&pos_0, &pos_1, menu->tex[i + 1], menu->img);
      i++;
    }
  return (0);
}

static int	my_load_texture_menu(t_menu *menu)
{
  char		*tab[NBR_TEX_MENU];
  int		i;

  tab[0] = "bmp/wolfmenu.bmp";
  tab[1] = "bmp/new_game.bmp";
  tab[2] = "bmp/load_game.bmp";
  tab[3] = "bmp/edit_game.bmp";
  tab[4] = "bmp/exit.bmp";
  if (!(menu->tex = my_malloc(sizeof(t_bmp *) * (NBR_TEX_MENU + 1))))
    return (1);
  i = 0;
  while (i < NBR_TEX_MENU)
    {
      if ((menu->tex[i] = my_open_bmp(tab[i])) == NULL)
	return (1);
      i++;
    }
  menu->tex[i] = NULL;
  return (0);
}

int		my_menu(t_xvar *xvar, char *str)
{
  t_menu	menu;
  XEvent	event;

  if ((menu.img = my_create_image(xvar, NULL, xvar->x, xvar->y)) == NULL)
    return (1);
  menu.name_map = str;
  if (my_load_texture_menu(&menu))
    return (1);
  while (42)
    {
      my_img_menu(xvar, &menu);
      my_event_expose(xvar, menu.img);
      while (XPending(xvar->dpy))
	{
	  XNextEvent(xvar->dpy, &event);
	  if (my_event_menu(xvar, &menu, &event))
	    return (0);
	}
    }
  return (1);
}

/*
** XWarpPointer(xvar->dpy, None, xvar->win, 0, 0, 0, 0,
** xvar->x / 2, xvar->y / 2);
*/
