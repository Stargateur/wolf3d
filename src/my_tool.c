/*
** my_tool.c for my_tool in /home/plasko_a/rendu/MUL_2013_fdf
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Sun Nov 24 10:54:05 2013 Antoine Plaskowski
** Last update Tue Jan  7 14:06:15 2014 Antoine PLASKOWSKI
*/

#include	<stdlib.h>

int		my_len_tab(char **tab)
{
  int		i;

  if (tab == NULL)
    return (0);
  i = 0;
  while (tab[i])
    i++;
  return (i);
}
