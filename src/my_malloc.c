/*
** my_malloc.c for my_malloc in /home/plasko_a/rendu/Piscine-C-lib/my
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Fri Nov 29 17:01:00 2013 Antoine Plaskowski
** Last update Sun Jan 12 07:32:22 2014 Antoine PLASKOWSKI
*/

#include	<stdlib.h>
#include	"my_str.h"

void		*my_malloc(size_t size_octet)
{
  void		*pt;

  if (size_octet == 0)
    {
      my_putstr("Warning malloc of 0\n", 2);
      exit(1);
    }
  if ((pt = malloc(size_octet)) == NULL)
    {
      my_putstr("Insufficient memory\n", 2);
      exit(1);
    }
  return (pt);
}
