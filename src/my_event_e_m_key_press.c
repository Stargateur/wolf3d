/*
** my_event_e_m_key_press.c for my_event_e_m_key_press in /home/plasko_a/rendu/MUL_2013_wolf3d
** 
** Made by Antoine PLASKOWSKI
** Login   <plasko_a@epitech.net>
** 
** Started on  Sun Jan 12 03:57:00 2014 Antoine PLASKOWSKI
** Last update Sun Jan 12 19:52:37 2014 Antoine PLASKOWSKI
*/

#include	<X11/Xlib.h>
#include	"my_edit_map.h"
#include	"my_load_texture.h"
#include	"my_resize_map.h"

static int	my_select_tex(t_edit_map *e_m, XEvent *event)
{
  if (event->xkey.keycode == 86)
    e_m->cur_tex++;
  else if (event->xkey.keycode == 82)
    e_m->cur_tex--;
  if (e_m->cur_tex < 0)
    e_m->cur_tex = NBR_TEX - 1;
  else if (e_m->cur_tex >= NBR_TEX)
    e_m->cur_tex = 0;
  return (0);
}

static int	my_check_resize_map(t_edit_map *e_m, XEvent *event)
{
  if (event->xkey.keycode == 85)
    my_add_map_x(e_m, 1);
  else if (event->xkey.keycode == 83)
    my_add_map_x(e_m, 0);
  else if (event->xkey.keycode == 80)
    my_add_map_y(e_m, 0);
  else if (event->xkey.keycode == 88)
    my_add_map_y(e_m, 1);
  else if (event->xkey.keycode == 47)
    my_sup_map_x(e_m, 1);
  else if (event->xkey.keycode == 45)
    my_sup_map_x(e_m, 0);
  else if (event->xkey.keycode == 32)
    my_sup_map_y(e_m, 0);
  else if (event->xkey.keycode == 46)
    my_sup_map_y(e_m, 1);
  else if (event->xkey.keycode == 75)
    my_save_map(e_m->map, e_m->str);
  else
    return (0);
  e_m->nbr_aff_x = e_m->map->x;
  e_m->nbr_aff_y = e_m->map->y;
  e_m->start_x = 0;
  e_m->start_y = 0;
  return (0);
}

int		my_zoom_map(t_edit_map *e_m, XEvent *event)
{
  if (event->xkey.keycode == 25)
    e_m->nbr_aff_y--;
  else if (event->xkey.keycode == 38)
    e_m->nbr_aff_x--;
  else if (event->xkey.keycode == 39)
    e_m->nbr_aff_y++;
  else if (event->xkey.keycode == 40)
    e_m->nbr_aff_x++;
  if (e_m->nbr_aff_x > e_m->map->x)
    e_m->nbr_aff_x--;
  else if (e_m->nbr_aff_x <= 0)
    e_m->nbr_aff_x++;
  if (e_m->nbr_aff_y > e_m->map->y)
    e_m->nbr_aff_y--;
  if (e_m->nbr_aff_y <= 0)
    e_m->nbr_aff_y++;
  return (0);
}

int		my_move_map(t_edit_map *e_m, XEvent *event)
{
  if (event->xkey.keycode == 111)
    e_m->start_y++;
  else if (event->xkey.keycode == 113)
    e_m->start_x++;
  else if (event->xkey.keycode == 116)
    e_m->start_y--;
  else if (event->xkey.keycode == 114)
    e_m->start_x--;
  if (e_m->nbr_aff_x + e_m->start_x > e_m->map->x)
    e_m->start_x--;
  else if (e_m->start_x < 0)
    e_m->start_x = 0;
  if (e_m->nbr_aff_y + e_m->start_y > e_m->map->y)
    e_m->start_y--;
  else if (e_m->start_y < 0)
    e_m->start_y = 0;
  return (0);
}

int		my_event_e_m_key_press(t_edit_map *e_m, XEvent *event)
{
  my_select_tex(e_m, event);
  my_check_resize_map(e_m, event);
  my_zoom_map(e_m, event);
  my_move_map(e_m, event);
  return (0);
}
