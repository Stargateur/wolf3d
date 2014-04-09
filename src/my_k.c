/*
** my_k.c for my_k in /home/plasko_a/rendu/MUL_2013_wolf3d
** 
** Made by Antoine PLASKOWSKI
** Login   <plasko_a@epitech.net>
** 
** Started on  Wed Jan  8 04:13:12 2014 Antoine PLASKOWSKI
** Last update Sat Jan 11 18:28:50 2014 Antoine PLASKOWSKI
*/

#include	"my_x.h"
#include	"my_k.h"
#include	"my_map.h"
#include	"my_game.h"
#include	"my_str.h"
#include	"my_coord.h"

double		my_k_x(t_map *map, t_kvar *kvar, t_player *player)
{
  double	k;
  int		x;
  int		y;

  x = kvar->player_x;
  k = 0;
  while (x + kvar->deca_x > -1 && x + kvar->deca_x < map->x)
    {
      k = (x - player->x) / kvar->v_x;
      if (k > 0)
	{
	  y = player->y + k * kvar->v_y;
	  if (y < 0)
	    y = 0;
	  else if (y >= map->y)
	    y = map->y - 1;
	  if (map->tab[y][x + kvar->deca_x] == WALL)
	    return (k);
	}
      x += kvar->slope_x;
    }
  return (map->x * map->y);
}

double		my_k_y(t_map *map, t_kvar *kvar, t_player *player)
{
  double	k;
  int		x;
  int		y;

  y = kvar->player_y;
  k = 0;
  while (y + kvar->deca_y > -1 && y + kvar->deca_y < map->y)
    {
      k = (y - player->y) / kvar->v_y;
      if (k > 0)
	{
	  x = player->x + k * kvar->v_x;
	  if (x < 0)
	    x = 0;
	  else if (x >= map->x)
	    x = map->x - 1;
	  if (map->tab[y + kvar->deca_y][x] == WALL)
	    return (k);
	}
      y += kvar->slope_y;
    }
  return (map->x * map->y);
}

static int	my_init_k(t_kvar *kvar, t_player *player, double *coord)
{
  kvar->v_x = coord[0] - player->x;
  kvar->v_y = coord[1] - player->y;
  kvar->slope_x = 1;
  kvar->player_x = player->x + 1;
  kvar->deca_x = 0;
  kvar->slope_y = 1;
  kvar->player_y = player->y + 1;
  kvar->deca_y = 0;
  if (kvar->v_x < 0)
    {
      kvar->slope_x = -1;
      kvar->player_x = player->x;
      kvar->deca_x = -1;
    }
  if (kvar->v_y < 0)
    {
      kvar->slope_y = -1;
      kvar->player_y = player->y;
      kvar->deca_y = -1;
    }
  return (0);
}

int		my_k(t_map *map, t_player *player,
		     t_kvar *kvar, double *coord)
{
  my_init_k(kvar, player, coord);
  kvar->k_x = my_k_x(map, kvar, player);
  kvar->k_y = my_k_y(map, kvar, player);
  if (kvar->k_y < kvar->k_x && kvar->k_y != 0)
    kvar->k = kvar->k_y;
  else if (kvar->k_x != 0)
    kvar->k = kvar->k_x;
  else
    kvar->k = 1;
  return (0);
}
