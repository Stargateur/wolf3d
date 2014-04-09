/*
** my_game.c for my_game in /home/plasko_a/rendu/MUL_2013_wolf3d
** 
** Made by Antoine PLASKOWSKI
** Login   <plasko_a@epitech.net>
** 
** Started on  Tue Jan  7 16:49:10 2014 Antoine PLASKOWSKI
** Last update Sun Jan 12 22:53:00 2014 Antoine PLASKOWSKI
*/

#include	<stdlib.h>
#include	<math.h>
#include	<X11/Xutil.h>
#include	"my_event_resize.h"
#include	"my_event_expose.h"
#include	"my_load_texture.h"
#include	"my_game.h"
#include	"my_map.h"
#include	"my_x.h"
#include	"my_str.h"

static int	my_check_game(t_xvar *xvar, t_game *game, XEvent *event)
{
  if (event->type == KeyPress)
    return (my_set_key(game, event));
  if (event->type == KeyRelease)
    return (my_unset_key(game, event));
  else if (event->type == ResizeRequest)
    {
      if ((game->img = my_event_resize(xvar, event, game->img)) == NULL)
	return (1);
      free(game->coord);
      if ((game->coord = my_init_coord(xvar)) == NULL)
	return (1);
    }
  return (0);
}

static int	my_event_game(t_xvar *xvar, t_game *game)
{
  XEvent	event;

  while (42)
    {
      my_control_player(game);
      if (my_img_game(xvar, game))
	return (1);
      my_event_expose(xvar, game->img);
      while (XPending(xvar->dpy))
	{
	  XNextEvent(xvar->dpy, &event);
	  if (my_check_game(xvar, game, &event))
	    return (0);
	}
    }
}

int		my_game(t_xvar *xvar, char *name_map)
{
  t_game	game;

  if ((game.map = my_load_map(name_map, 1)) == NULL)
    return (1);
  if ((game.tex = my_load_texture()) == NULL)
    return (1);
  if ((game.key = my_init_key()) == NULL)
    return (1);
  if (!(game.player = my_init_player(game.map)))
    return (1);
  if (!(game.coord = my_init_coord(xvar)))
    return (1);
  if (!(game.img = my_create_image(xvar, NULL, xvar->x, xvar->y)))
    return (1);
  my_event_game(xvar, &game);
  free(game.player);
  free(game.key);
  free(game.coord);
  my_free_texture(game.tex);
  XDestroyImage(game.img);
  my_free_map(game.map);
  return (1);
}
