/*
** my_bmp.c for my_bmp in /home/plasko_a/rendu/MUL_2013_wof3d/src/
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Thu Oct 24 16:05:36 2013 Antoine Plaskowski
** Last update Sun Jan 12 22:03:08 2014 Antoine PLASKOWSKI
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<fcntl.h>
#include	"my_bmp.h"
#include	"my_struct_color.h"
#include	"my_open.h"
#include	"my_str.h"

void		my_free_bmp(t_bmp *bmp)
{
  if (bmp != NULL)
    {
      free(bmp->h_bmp);
      free(bmp->h_img);
      free(bmp->img);
      free(bmp);
    }
}

static int	my_read_header(t_bmp *bmp, const int fd)
{
  if ((bmp->h_bmp = my_malloc(sizeof(t_hbmp))) == NULL)
    return (1);
  if ((bmp->h_img = my_malloc(sizeof(t_himg))) == NULL)
    return (2);
  if (read(fd, bmp->h_bmp, sizeof(t_hbmp)) != 14)
    return (3);
  if (bmp->h_bmp->type[0] != 'B' || bmp->h_bmp->type[1] != 'M')
    return (4);
  if (read(fd, bmp->h_img, sizeof(t_himg)) != 40 || bmp->h_img->color != 24)
    return (6);
  if (bmp->h_img->compress)
    return (5);
  return (0);
}

static int	my_read_img(t_bmp *bmp, const int fd)
{
  int		i;
  int		j;

  if (!(bmp->img = my_malloc(4 * bmp->h_img->x * bmp->h_img->y)))
    return (1);
  j = bmp->h_img->y;
  while (j--)
    {
      i = 0;
      while (i < bmp->h_img->x)
	{
	  if (read(fd, bmp->img + (j * bmp->h_img->x + i++) * 4 , 3) != 3)
	    return (1);
	  *(bmp->img + 3) = 0;
	}
      if (i % 4 != read(fd, &i, i % 4))
	return (1);
    }
  if (read(fd, &i, 4))
    return (1);
  return (0);
}

t_bmp		*my_open_bmp(const char *str)
{
  t_bmp		*bmp;
  int		fd;

  if ((bmp = my_malloc(sizeof(t_bmp))) == NULL)
    return (NULL);
  bmp->h_bmp = NULL;
  bmp->h_img = NULL;
  bmp->img = NULL;
  if ((fd = my_open_rdonly(str)) == -1)
    return (NULL);
  if (my_read_header(bmp, fd) || my_read_img(bmp, fd))
    {
      my_putstr("wrong bmp\n", 2);
      close(fd);
      my_free_bmp(bmp);
      return (NULL);
    }
  return (bmp);
}
