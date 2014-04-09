/*
** my_strcpy.c for my_strcpy in /home/plasko_a/rendu/Piscine-C-Jour_06/ex_01
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Mon Oct  7 09:22:05 2013 Antoine Plaskowski
** Last update Fri Jan 10 01:15:34 2014 Antoine PLASKOWSKI
*/

#include	<stdlib.h>

int		my_strcpy(char *dest, const char *src)
{
  if (dest == NULL || src == NULL)
    return (1);
  while (*src)
    *dest++ = *src++;
  *dest = '\0';
  return (0);
}
