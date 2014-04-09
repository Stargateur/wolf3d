/*
** my_tool_map.c for my_tool_map in /home/plasko_a/rendu/MUL_2013_wolf3d
** 
** Made by Antoine PLASKOWSKI
** Login   <plasko_a@epitech.net>
** 
** Started on  Tue Jan  7 13:54:45 2014 Antoine PLASKOWSKI
** Last update Sun Jan 12 21:54:08 2014 Antoine PLASKOWSKI
*/

#include	<stdlib.h>
#include	"my_map.h"
#include	"my_str.h"
#include	"my_load_texture.h"

void		my_free_map(t_map *map)
{
  int		i;

  if (map)
    {
      if (map->tab)
	{
	  i = 0;
	  while (i < map->y)
	    free(map->tab[i++]);
	  free(map->tab);
	}
      free(map->next);
      free(map);
    }
}

int		my_init_map(t_map *map)
{
  int		i;

  if (map == NULL || map->tab == NULL)
    return (1);
  i = 0;
  while (i < map->y)
    map->tab[i++] = NULL;
  return (0);
}

static int	my_check_map_tex(t_map *map)
{
  int		i;
  int		j;

  i = 0;
  while (i < map->y)
    {
      j = 0;
      while (j < map->x)
	{
	  if (map->tab[i][j] < 0 || map->tab[i][j] >= NBR_TEX)
	    {
	      my_putstr("The map is not valide : wrong texture ! ", 2);
	      my_putnbr(map->tab[i][j], 2);
	      my_putchar('\n', 2);
	      return (1);
	    }
	  j++;
	}
      i++;
    }
  return (0);
}

static int	my_check_map_wall(t_map *map)
{
  int		i;
  int		j;

  i = 0;
  while (i < map->y && map->tab[i][0] == 1 && map->tab[i][map->x - 1] == 1)
    i++;
  j = 0;
  while (j < map->x && map->tab[0][j] == 1 && map->tab[map->y - 1][j] == 1)
    j++;
  if (i != map->y || j != map->x)
    my_putstr("The map has no wall on the border !\n", 2);
  return (0);
}

int		my_check_map(t_map *map)
{
  int		i;
  int		j;
  int		nbr_spawn;

  if (map == NULL || map->tab == NULL)
    return (1);
  nbr_spawn = 0;
  i = 0;
  while (i < map->y)
    {
      j = 0;
      while (j < map->x)
	if (map->tab[i][j++] == PLAYER)
	  nbr_spawn++;
      i++;
    }
  if (nbr_spawn != 1)
    {
      my_putnbr(nbr_spawn, 2);
      my_putstr(" : the map must have 1 player !\n", 2);
      return (1);
    }
  if (my_check_map_wall(map) || my_check_map_tex(map))
    return (1);
  return (0);
}
