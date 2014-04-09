/*
** my_player.c for my_player in /home/plasko_a/rendu/MUL_2013_wolf3d
** 
** Made by Antoine PLASKOWSKI
** Login   <plasko_a@epitech.net>
** 
** Started on  Wed Jan  8 00:50:44 2014 Antoine PLASKOWSKI
** Last update Sun Jan 12 22:51:46 2014 Antoine PLASKOWSKI
*/

#include	<stdlib.h>
#include	<math.h>
#include	"my_game.h"
#include	"my_str.h"

static void	my_define_player(t_player *player, int i, int j)
{
  player->ang = 0;
  player->y = i + 0.5;
  player->x = j + 0.5;
}

t_player	*my_init_player(t_map *map)
{
  t_player	*player;
  int		i;
  int		j;

  if (map == NULL || (player = my_malloc(sizeof(t_player))) == NULL)
    return (NULL);
  i = 0;
  while (i < map->y)
    {
      j = 0;
      while (j < map->x)
	{
	  if (map->tab[i][j] == PLAYER)
	    {
	      my_define_player(player, i, j);
	      return (player);
	    }
	  j++;
	}
      i++;
    }
  my_putstr("Can't find player...\n", 2);
  free(player);
  return (NULL);
}

static void	my_calcul_tmp_player(t_game *game, double *tmp_x,
				     double *tmp_y)
{
  *tmp_x = game->player->x;
  *tmp_y = game->player->y;
  if (game->key->z)
    {
      *tmp_x += cos(game->player->ang) * 0.1;
      *tmp_y += sin(game->player->ang) * 0.1;
    }
  if (game->key->s)
    {
      *tmp_x -= cos(game->player->ang) * 0.1;
      *tmp_y -= sin(game->player->ang) * 0.1;
    }
  if (game->key->d)
    {
      *tmp_x += sin(game->player->ang) * 0.1;
      *tmp_y -= cos(game->player->ang) * 0.1;
    }
  if (game->key->q)
    {
      *tmp_x -= sin(game->player->ang) * 0.1;
      *tmp_y += cos(game->player->ang) * 0.1;
    }
}

void		my_control_player(t_game *game)
{
  double	tmp_x;
  double	tmp_y;
  int		tmp;

  tmp = game->player->y;
  my_calcul_tmp_player(game, &tmp_x, &tmp_y);
  if (tmp_y >= 0 && tmp_y < game->map->y &&
      game->map->tab[(int) tmp_y][(int) game->player->x] != WALL)
    game->player->y = tmp_y;
  if (tmp_x >= 0 && tmp_x < game->map->x &&
      game->map->tab[tmp][(int) tmp_x] != WALL)
    game->player->x = tmp_x;
  if (game->key->a)
    game->player->ang += MY_PI / 45;
  if (game->key->e)
    game->player->ang -= MY_PI / 45;
}
