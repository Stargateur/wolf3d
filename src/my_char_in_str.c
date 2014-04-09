/*
** my_char_in_str.c for my_char_in_str in /home/plasko_a/rendu/Piscine-C-lib/my
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Fri Nov 15 05:46:34 2013 Antoine Plaskowski
** Last update Fri Nov 29 16:51:42 2013 Antoine Plaskowski
*/

#include	<stdlib.h>

int		my_char_in_str(const char c, const char *str)
{
  int		i;

  if (str == NULL)
    return (0);
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == c)
	return (i);
      i++;
    }
  return (-1);
}
