/*
** my_struct_coord.c for my_struct_coord in /home/plasko_a/rendu/MUL_2013_wolf3d
** 
** Made by Antoine PLASKOWSKI
** Login   <plasko_a@epitech.net>
** 
** Started on  Sun Jan 12 17:51:06 2014 Antoine PLASKOWSKI
** Last update Sun Jan 12 18:17:54 2014 Antoine PLASKOWSKI
*/

#include	<stdlib.h>
#include	"my_struct_coord.h"

int		my_set_coord(t_coord *coord, int x, int y)
{
  if (coord == NULL)
    return (1);
  coord->x = x;
  coord->y = y;
  return (0);
}
