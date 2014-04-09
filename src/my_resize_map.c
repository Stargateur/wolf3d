/*
** my_resize_map.c for my_resize_map in /home/plasko_a/rendu/MUL_2013_wolf3d
** 
** Made by Antoine PLASKOWSKI
** Login   <plasko_a@epitech.net>
** 
** Started on  Sun Jan 12 07:34:21 2014 Antoine PLASKOWSKI
** Last update Sun Jan 12 09:20:18 2014 Antoine PLASKOWSKI
*/

#include	<X11/Xlib.h>
#include	"my_edit_map.h"
#include	"my_map.h"
#include	"my_str.h"

int		my_add_map_x(t_edit_map *e_m, int bool)
{
  int		*tmp;
  int		i;
  int		j;

  if (e_m->map->x >= MAX)
    return (0);
  i = 0;
  while (i < e_m->map->y)
    {
      tmp = e_m->map->tab[i];
      if (!(e_m->map->tab[i] = my_malloc(sizeof(int) * (e_m->map->x + 1))))
	return (1);
      j = 0;
      while (j < e_m->map->x)
	{
	  e_m->map->tab[i][j + bool] = tmp[j];
	  j++;
	}
      if (bool)
	j = 0;
      e_m->map->tab[i++][j] = 1;
      free(tmp);
    }
  e_m->map->x++;
  return (0);
}

int		my_sup_map_x(t_edit_map *e_m, int bool)
{
  int		*tmp;
  int		i;
  int		j;

  if (e_m->map->x < 2)
    return (0);
  e_m->map->x--;
  i = 0;
  while (i < e_m->map->y)
    {
      tmp = e_m->map->tab[i];
      if ((e_m->map->tab[i] = my_malloc(sizeof(int) * (e_m->map->x))) == NULL)
	return (1);
      j = 0;
      while (j < e_m->map->x)
	{
	  e_m->map->tab[i][j] = tmp[j + bool];
	  j++;
	}
      free(tmp);
      i++;
    }
  return (0);
}

int		my_add_map_y(t_edit_map *e_m, int bool)
{
  int		**tab;
  int		i;
  int		j;

  if (e_m->map->y >= MAX)
    return (0);
  if ((tab = my_malloc(sizeof(int *) * (e_m->map->y + 1))) == NULL)
    return (0);
  i = 0;
  while (i < e_m->map->y)
    {
      tab[i + bool] = e_m->map->tab[i];
      i++;
    }
  if (bool)
    i = 0;
  if ((tab[i] = my_malloc(sizeof(int) * e_m->map->x)) == NULL)
    return (1);
  j = 0;
  while (j < e_m->map->x)
    tab[i][j++] = 1;
  free(e_m->map->tab);
  e_m->map->tab = tab;
  e_m->map->y++;
  return (0);
}

int		my_sup_map_y(t_edit_map *e_m, int bool)
{
  int		**tab;
  int		i;

  if (e_m->map->y < 2)
    return (1);
  e_m->map->y--;
  if ((tab = my_malloc(sizeof(int *) * e_m->map->y)) == NULL)
    return (1);
  i = 0;
  if (bool)
    free(e_m->map->tab[0]);
  else
    free(e_m->map->tab[e_m->map->y]);
  while (i < e_m->map->y)
    {
      tab[i] = e_m->map->tab[i + bool];
      i++;
    }
  free(e_m->map->tab);
  e_m->map->tab = tab;
  return (0);
}
