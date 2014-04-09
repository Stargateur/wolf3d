/*
** my_map.h for my_map in /home/plasko_a/rendu/MUL_2013_wolf3d
** 
** Made by Antoine PLASKOWSKI
** Login   <plasko_a@epitech.net>
** 
** Started on  Tue Jan  7 13:53:40 2014 Antoine PLASKOWSKI
** Last update Sun Jan 12 20:42:19 2014 Antoine PLASKOWSKI
*/

#ifndef		MY_MAP_H_
# define	MY_MAP_H_

# define	VOID		0
# define	WALL		1
# define	PLAYER		2

# define	MAX		100

typedef struct	s_map
{
  int		**tab;
  char		*next;
  int		x;
  int		y;
}		t_map;

t_map		*my_load_map(const char *str, int bool);
int		my_init_map(t_map *map);
void		my_free_map(t_map *map);
int		my_save_map(t_map *map, const char *str);
int		my_check_map(t_map *map);

#endif		/* !MY_MAP_H_ */
