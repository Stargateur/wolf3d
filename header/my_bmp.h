/*
** my_bmp.h for my__bmp in /home/plasko_a/rendu/MUL_2013_wolf3d/src/
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Thu Oct 24 16:06:07 2013 Antoine Plaskowski
** Last update Thu Jan  9 18:38:50 2014 Antoine PLASKOWSKI
*/

#ifndef			MY_BMP_H_
# define		MY_BMP_H_

# pragma		pack(1)

typedef struct		s_hbmp
{
  char			type[2];
  int			size;
  int			reserved;
  int			offset;
}			t_hbmp;

typedef struct		s_himg
{
  int			size_header;
  int			x;
  int			y;
  short			plane;
  short			color;
  int			compress;
  int			size_img;
  int			nbr_x;
  int			nbr_y;
  int			nbr_color;
  int			nbr_imp_color;
}			t_himg;

typedef struct		s_bmp
{
  t_hbmp		*h_bmp;
  t_himg		*h_img;
  char			*img;
}			t_bmp;

t_bmp			*my_open_bmp(const char *str);
void			my_free_bmp(t_bmp *bmp);

# pragma		pack()

#endif			/* !MY_BMP_H_ */
