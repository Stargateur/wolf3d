/*
** my_save_map.c for my_save_map in /home/plasko_a/rendu/MUL_2013_wolf3d
** 
** Made by Antoine PLASKOWSKI
** Login   <plasko_a@epitech.net>
** 
** Started on  Tue Jan  7 14:51:42 2014 Antoine PLASKOWSKI
** Last update Sun Jan 12 21:00:20 2014 Antoine PLASKOWSKI
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my_map.h"
#include	"my_open.h"
#include	"my_str.h"

static int	my_write_map(t_map *map, const int fd)
{
  int		i;
  int		j;

  i = map->y - 1;
  while (i > -1)
    {
      j = 0;
      while (j < map->x)
	{
	  my_putnbr(map->tab[i][j++], fd);
	  if (j != map->x)
	    my_putchar(' ', fd);
	}
      i--;
      my_putchar('\n', fd);
    }
  return (0);
}

int		my_save_map(t_map *map, const char *str)
{
  int		fd;

  if (map == NULL || map->tab == NULL || (fd = my_open_wr(str)) == -1)
    return (1);
  my_putnbr(map->x, fd);
  my_putchar(' ', fd);
  my_putnbr(map->y, fd);
  my_putchar('\n', fd);
  my_write_map(map, fd);
  my_putstr(map->next, fd);
  my_putstr("Map save !\n", 1);
  close(fd);
  return (0);
}
