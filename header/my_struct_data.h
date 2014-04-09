/*
** my_struct_data.h for my_struct_data in /home/plasko_a/rendu/MUL_2013_fdf
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Sun Nov 24 10:29:21 2013 Antoine Plaskowski
** Last update Sun Dec  8 12:19:12 2013 Antoine Plaskowski
*/

#ifndef		MY_STRUCT_DATA_H_
# define	MY_STRUCT_DATA_H_

# include	"my_struct_coord.h"

struct		s_data
{
  struct s_data	*prev;
  t_coord	**coord;
  int		size;
  struct s_data	*next;
};

typedef		struct s_data t_data;

t_data		*my_create_data(const int fd);
int		my_aff_data(const t_data *data);
int		my_free_data(t_data *data);

#endif		/* !MY_STRUCT_DATA_H_ */
