/*
** my_key.c for my_key in /home/plasko_a/rendu/MUL_2013_wolf3d
** 
** Made by Antoine PLASKOWSKI
** Login   <plasko_a@epitech.net>
** 
** Started on  Sat Jan 11 11:31:50 2014 Antoine PLASKOWSKI
** Last update Sun Jan 12 19:53:43 2014 Antoine PLASKOWSKI
*/

#include	"my_game.h"
#include	"my_str.h"

t_key		*my_init_key()
{
  t_key		*key;

  if ((key = my_malloc(sizeof(t_key))) == NULL)
    return (NULL);
  key->a = 0;
  key->e = 0;
  key->z = 0;
  key->s = 0;
  key->q = 0;
  key->d = 0;
  return (key);
}

int		my_set_key(t_game *game, XEvent *event)
{
  if (event->xkey.keycode == 25)
    game->key->z = 1;
  else if (event->xkey.keycode == 39)
    game->key->s = 1;
  else if (event->xkey.keycode == 38)
    game->key->q = 1;
  else if (event->xkey.keycode == 40)
    game->key->d = 1;
  else if (event->xkey.keycode == 24)
    game->key->a = 1;
  else if (event->xkey.keycode == 26)
    game->key->e = 1;
  else if (event->xkey.keycode == 9)
    return (1);
  return (0);
}

int		my_unset_key(t_game *game, XEvent *event)
{
  if (event->xkey.keycode == 25)
    game->key->z = 0;
  else if (event->xkey.keycode == 39)
    game->key->s = 0;
  else if (event->xkey.keycode == 38)
    game->key->q = 0;
  else if (event->xkey.keycode == 40)
    game->key->d = 0;
  else if (event->xkey.keycode == 24)
    game->key->a = 0;
  else if (event->xkey.keycode == 26)
    game->key->e = 0;
  return (0);
}
