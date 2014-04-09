/*
** my_img_game.c for my_image_game in /home/plasko_a/rendu/MUL_2013_wolf3d
** 
** Made by Antoine PLASKOWSKI
** Login   <plasko_a@epitech.net>
** 
** Started on  Wed Jan  8 01:41:34 2014 Antoine PLASKOWSKI
** Last update Sun Jan 12 21:22:34 2014 Antoine PLASKOWSKI
*/

#include	"my_game.h"
#include	"my_k.h"
#include	"my_map.h"
#include	"my_game.h"
#include	"my_struct_color.h"
#include	"my_put_pixel_to_img.h"
#include	"my_str.h"
#include	"math.h"

double		*my_init_coord(t_xvar *xvar)
{
  double	*coord;
  int		i;

  if ((coord = my_malloc(sizeof(double) * xvar->x)) == NULL)
    return (NULL);
  i = 0;
  while (i < xvar->x)
    {
      coord[i] = (double) (xvar->x / 2 - i) / xvar->x;
      i++;
    }
  return (coord);
}

static double	**my_new_coord(t_xvar *xvar, t_player *ply, double *coord)
{
  double	**new_coord;
  int		i;

  if ((new_coord = my_malloc(sizeof(double *) * xvar->x)) == NULL)
    return (NULL);
  i = 0;
  while (i < xvar->x)
    {
      if ((new_coord[i] = my_malloc(sizeof(double) * 2)) == NULL)
	return (NULL);
      new_coord[i][0] = 0.5 * cos(ply->ang) - coord[i] * sin(ply->ang) + ply->x;
      new_coord[i][1] = 0.5 * sin(ply->ang) + coord[i] * cos(ply->ang) + ply->y;
      i++;
    }
  return (new_coord);
}

int		my_img_wall(t_xvar *xvar, t_game *game, t_kvar *kvar)
{
  t_color	wall;
  int		y_img;
  int		i;

  y_img = (kvar->y - xvar->y / 2 + kvar->s_wall) * 100 /
    (2 * kvar->s_wall) * game->tex[1]->h_img->y / 100;
  i = (y_img * game->tex[WALL]->h_img->x + kvar->img_x) * 4;
  if (i < 0 || i >= game->tex[WALL]->h_img->y *
      game->tex[WALL]->h_img->x * 4 - 4)
    return (1);
  wall.r = game->tex[WALL]->img[i++];
  wall.v = game->tex[WALL]->img[i++];
  wall.b = game->tex[WALL]->img[i++];
  wall.opacity = game->tex[WALL]->img[i];
  my_put_pixel_to_img(game->img, &wall, kvar->y * xvar->x * 4 + kvar->x * 4);
  return (0);
}

static int	my_loop(t_xvar *xvar, t_game *game,
			t_kvar *kvar, double **new_coord)
{
  my_k(game->map, game->player, kvar, new_coord[kvar->x]);
  if (kvar->k_x != kvar->k)
    kvar->pos_x = game->player->x + kvar->v_x * kvar->k_y;
  else
    kvar->pos_x = game->player->y + kvar->v_y * kvar->k_x;
  kvar->tmp_x = (kvar->pos_x - (int) kvar->pos_x) * 100;
  kvar->img_x = kvar->tmp_x * game->tex[1]->h_img->x / 100;
  if ((kvar->k_x != kvar->k && kvar->v_y < 0) || (kvar->k_x == kvar->k &&
						  kvar->v_x > 0))
    kvar->img_x = game->tex[1]->h_img->x - kvar->img_x - 1;
  kvar->y = 0;
  kvar->s_wall = xvar->y / (2 * kvar->k);
  while (kvar->y < xvar->y)
    {
      if (kvar->y < xvar->y / 2 - kvar->s_wall)
	my_put_pixel_to_img(game->img, kvar->sky, kvar->y *
			    xvar->x * 4 + kvar->x * 4);
      else if (kvar->y < xvar->y / 2 + kvar->s_wall)
	my_img_wall(xvar, game, kvar);
      else
	my_put_pixel_to_img(game->img, kvar->ground, kvar->y *
			    xvar->x * 4 + kvar->x * 4);
      kvar->y++;
    }
  return (0);
}

int		my_img_game(t_xvar *xvar, t_game *game)
{
  double	**new_coord;
  t_kvar	kvar;
  t_color	sky;
  t_color	ground;

  if ((new_coord = my_new_coord(xvar, game->player, game->coord)) == NULL)
    return (1);
  my_set_color(&sky, 255, 100, 100);
  my_set_color(&ground, 25, 25, 25);
  kvar.sky = &sky;
  kvar.ground = &ground;
  kvar.x = 0;
  while (kvar.x < xvar->x)
    {
      my_loop(xvar, game, &kvar, new_coord);
      free(new_coord[kvar.x]);
      kvar.x++;
    }
  free(new_coord);
  return (0);
}
