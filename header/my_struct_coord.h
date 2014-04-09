/*
** my_struct_coord.h for my_struct_coord in /home/plasko_a/rendu/MUL_2013_wolf3d
** 
** Made by Antoine PLASKOWSKI
** Login   <plasko_a@epitech.net>
** 
** Started on  Sun Jan 12 17:37:05 2014 Antoine PLASKOWSKI
** Last update Sun Jan 12 18:18:49 2014 Antoine PLASKOWSKI
*/

#ifndef		MY_STRUCT_COORD_H_
# define	MY_STRUCT_COORD_H_

typedef struct	s_coord
{
  int		x;
  int		y;
}		t_coord;

int		my_set_coord(t_coord *coord, int x, int y);

#endif		/* !MY_STRUCT_COORD_H_ */
