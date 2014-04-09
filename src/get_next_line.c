/*
** get_next_line.c for get_next_line in /home/plasko_a/rendu/CPE_2013_getnextline
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Sat Nov 23 09:06:00 2013 Antoine Plaskowski
** Last update Mon Dec  2 20:08:17 2013 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"get_next_line.h"
#include	"my_str.h"

static int	my_put_new_line(t_nline **new_line, char *str)
{
  if (new_line == NULL)
    return (1);
  if (*new_line == NULL)
    {
      if ((*new_line = my_malloc(sizeof(t_nline))) == NULL)
	return (1);
      (*new_line)->prev = NULL;
    }
  else
    {
      if (((*new_line)->next = my_malloc(sizeof(t_nline))) == NULL)
	return (1);
      (*new_line)->next->prev = *new_line;
      *new_line = (*new_line)->next;
    }
  (*new_line)->str = str;
  (*new_line)->next = NULL;
  return (0);
}

static char	*my_str_new_line(t_nline **new_line)
{
  char		*str;
  int		len;
  int		i;

  if (new_line == NULL || *new_line == NULL)
    return (NULL);
  len = my_strlen((*new_line)->str);
  i = 0;
  while ((*new_line)->prev != NULL)
    {
      i++;
      *new_line = (*new_line)->prev;
    }
  if ((str = my_malloc(sizeof(char) * (i * BUF + len + 1))) == NULL)
    return (NULL);
  return (str);
}

static char	*my_cat_new_line(t_nline **new_line)
{
  t_nline	*tmp_nline;
  char		*str;
  char		*tmp;
  int		i;

  if (new_line == NULL)
    return (NULL);
  if ((str = my_str_new_line(new_line)) == NULL)
    return (NULL);
  tmp = str;
  while (*new_line != NULL)
    {
      i = 0;
      while ((*new_line)->str != NULL && (*new_line)->str[i] != '\0')
	*tmp++ = (*new_line)->str[i++];
      tmp_nline = *new_line;
      *new_line = (*new_line)->next;
      free(tmp_nline->str);
      free(tmp_nline);
    }
  *tmp = '\0';
  free(*new_line);
  *new_line = NULL;
  return (str);
}

static int	my_new_line(const char *buf, t_nline **new_line,
			    long *i, const long max)
{
  char		*str;
  long		j;

  if (buf == NULL || new_line == NULL || i == NULL)
    return (1);
  j = 0;
  while (buf[*i + j] != '\n' && *i + j < max)
    j++;
  if ((str = my_malloc(sizeof(char) * (j + 1))) == NULL)
    return (1);
  j = 0;
  while (buf[*i] != '\n' && *i < max)
    str[j++] = buf[(*i)++];
  str[j] = '\0';
  if (my_put_new_line(new_line, str))
    return (1);
  return (0);
}

char		*get_next_line(const int fd, int reset)
{
  static char	buf[BUF];
  static long	i = 0;
  static long	max = 0;
  t_nline	*new_line;

  if (reset)
    i = max;
  new_line = NULL;
  while (new_line == NULL || i >= max)
    {
      if (i >= max)
	{
	  i = 0;
	  if ((max = read(fd, buf, BUF)) <= 0)
	    return (my_cat_new_line(&new_line));
	}
      if (my_new_line(buf, &new_line, &i, max))
	return (my_cat_new_line(&new_line));
      if (buf[i++] == '\n')
	return (my_cat_new_line(&new_line));
    }
  return (my_cat_new_line(&new_line));
}
