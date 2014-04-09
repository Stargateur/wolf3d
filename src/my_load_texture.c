/*
** my_load_texture.c for my_load_texture in /home/plasko_a/rendu/MUL_2013_wolf3d
** 
** Made by Antoine PLASKOWSKI
** Login   <plasko_a@epitech.net>
** 
** Started on  Fri Jan 10 00:40:48 2014 Antoine PLASKOWSKI
** Last update Sun Jan 12 10:10:19 2014 Antoine PLASKOWSKI
*/

#include	<stdlib.h>
#include	"my_str.h"
#include	"my_bmp.h"
#include	"my_load_texture.h"

static char	*my_create_name(int i)
{
  char		*name;
  int		tmp;
  int		len;

  len = 10;
  tmp = i;
  while (tmp / 10 != 0)
    {
      tmp /= 10;
      len++;
    }
  if ((name = my_malloc(sizeof(char) * len)) == NULL)
    return (NULL);
  name[len - 1] = '\0';
  len -= 5;
  my_strcpy(name, "bmp/");
  my_strcpy(name + len--, ".bmp");
  while (i / 10 != 0)
    {
      name[len--] = i % 10 + '0';
      i /= 10;
    }
  name[len] = i % 10 + '0';
  return (name);
}

t_bmp		**my_load_texture()
{
  t_bmp		**tex;
  char		*name;
  int		i;

  my_putstr("Load_Texture...\n", 1);
  if ((tex = my_malloc(sizeof(t_bmp *) * (NBR_TEX + 1))) == NULL)
    return (NULL);
  i = 0;
  while (i < NBR_TEX)
    {
      if ((name = my_create_name(i)) == NULL)
	return (NULL);
      if ((tex[i] = my_open_bmp(name)) == NULL)
	return (NULL);
      free(name);
      i++;
    }
  tex[i] = NULL;
  my_putstr("Finish !\n", 1);
  return (tex);
}

void		my_free_texture(t_bmp **tex)
{
  int		i;

  i = 0;
  while (tex[i])
    my_free_bmp(tex[i++]);
  free(tex);
}
