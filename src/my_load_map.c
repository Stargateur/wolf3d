/*
** my_load_map.c for my_load_map in /home/plasko_a/rendu/MUL_2013_wolf3d
** 
** Made by Antoine PLASKOWSKI
** Login   <plasko_a@epitech.net>
** 
** Started on  Tue Jan  7 09:56:33 2014 Antoine PLASKOWSKI
** Last update Sun Jan 12 20:58:29 2014 Antoine PLASKOWSKI
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my_open.h"
#include	"my_map.h"
#include	"my_str.h"
#include	"get_next_line.h"
#include	"my_tool.h"

static int	my_create_tab_anx(t_map *map)
{
  int		i;

  if ((map->tab = my_malloc(sizeof(int *) * map->y)) == NULL)
    return (1);
  if (my_init_map(map))
    return (1);
  i = 0;
  while (i < map->y)
    {
      if ((map->tab[i] = my_malloc(sizeof(int) * map->x)) == NULL)
	return (1);
      i++;
    }
  return (0);
}

static int	my_put_nbr_in_map(t_map *map, char **tab, int i)
{
  int		j;

  if (my_len_tab(tab) != map->x)
    {
      my_putstr("map invalide\n", 2);
      my_free_wordtab(tab);
      return (1);
    }
  j = 0;
  while (j < map->x)
    {
      map->tab[i][j] = my_getnbr(tab[j]);
      j++;
    }
  my_free_wordtab(tab);
  return (0);
}

static int	my_create_tab_plus(t_map *map, const int fd)
{
  char		**tab;
  char		*str;
  int		i;

  i = map->y - 1;
  while (i > -1 && (str = get_next_line(fd, 0)))
    {
      if ((tab = my_str_to_wordtab(str)) == NULL)
	return (1);
      free(str);
      if (my_put_nbr_in_map(map, tab, i--))
	return (1);
    }
  map->next = get_next_line(fd, 0);
  return (0);
}

static int	my_create_tab(t_map *map, const int fd)
{
  char		**tab;
  char		*str;

  if ((str = get_next_line(fd, 1)) == NULL)
    {
      my_putstr("Map empty\n", 2);
      return (1);
    }
  if ((tab = my_str_to_wordtab(str)) == NULL)
    return (1);
  free(str);
  if (my_len_tab(tab) != 2 || (map->x = my_getnbr(tab[0])) == 0 ||
      (map->y = my_getnbr(tab[1])) == 0 || map->x > MAX || map->y > MAX)
    {
      my_putstr("Map invalide\n", 2);
      my_free_wordtab(tab);
      return (1);
    }
  my_free_wordtab(tab);
  if (my_create_tab_anx(map) || my_create_tab_plus(map, fd))
    return (1);
  return (0);
}

t_map		*my_load_map(const char *str, int bool)
{
  t_map		*map;
  int		fd;

  my_putstr("Load_map...\n", 1);
  if (!(map = my_malloc(sizeof(t_map))) || (fd = my_open_rdonly(str)) == -1)
    {
      free(map);
      return (NULL);
    }
  map->tab = NULL;
  if (my_create_tab(map, fd))
    {
      close(fd);
      my_free_map(map);
      return (NULL);
    }
  close(fd);
  if (my_check_map(map) && bool)
    {
      my_free_map(map);
      return (NULL);
    }
  my_putstr("Finish !\n", 1);
  return (map);
}
