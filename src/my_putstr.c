/*
** my_putstr.c for my_putstr in /home/plasko_a/rendu/Piscine-C-Jour_04
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Thu Oct  3 10:36:52 2013 Antoine Plaskowski
** Last update Sun Dec  8 13:46:35 2013 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my_str.h"

int		my_putstr(const char *str, int fd)
{
  int		len;

  if (str == NULL)
    return (1);
  len = my_strlen(str);
  if (write(fd, str, len) != len)
    return (1);
  return (0);
}
