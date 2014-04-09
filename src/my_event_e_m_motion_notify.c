/*
** my_event_e_m_motion_notify.c for my_event_e_m_motion_notify in /home/plasko_a/rendu/MUL_2013_wolf3d
** 
** Made by Antoine PLASKOWSKI
** Login   <plasko_a@epitech.net>
** 
** Started on  Sun Jan 12 06:19:49 2014 Antoine PLASKOWSKI
** Last update Sun Jan 12 10:15:32 2014 Antoine PLASKOWSKI
*/

#include	<X11/Xlib.h>
#include	"my_edit_map.h"

int		my_event_e_m_motion_notify(t_edit_map *e_m, XEvent *event)
{
  int		x;
  int		y;

  if (e_m->button)
    {
      x = e_m->nbr_aff_x - 1 + e_m->start_x - event->xmotion.x /
	e_m->pix_per_img_x;
      y = e_m->nbr_aff_y - 1 + e_m->start_y - event->xmotion.y /
	e_m->pix_per_img_y;
      if (x < 0)
	x = 0;
      else if (x >= e_m->map->x)
	x = e_m->map->x - 1;
      if (y < 0)
	y = 0;
      else if (y >= e_m->map->y)
	y = e_m->map->y - 1;
      e_m->map->tab[y][x] = e_m->cur_tex;
    }
  return (0);
}
