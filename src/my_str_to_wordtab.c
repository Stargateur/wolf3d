/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/plasko_a/rendu/Piscine-C-Jour_08/ex_04
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Wed Oct  9 23:29:57 2013 Antoine Plaskowski
** Last update Sat Dec 21 22:07:53 2013 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_str.h"

static int	my_len_tab(const char *str)
{
  int		i;

  i = 0;
  while (*str != '\0')
    {
      while (*str == ' ' || *str == '\t')
	str++;
      if (*str != '\0')
	i++;
      while (*str != ' ' && *str != '\t' && *str != '\0')
	str++;
    }
  return (i + 1);
}

static int	my_len_word(const char *str)
{
  int		i;

  i = 0;
  while (str[i] != ' ' && *str != '\t' && str[i] != '\0')
    i++;
  return (i + 1);
}

int		my_free_wordtab(char **tab)
{
  int		i;

  if (tab == NULL)
    return (1);
  i = 0;
  while (tab[i] != NULL)
    free(tab[i++]);
  free(tab);
  return (0);
}

char		**my_str_to_wordtab(const char *str)
{
  char		**tab;
  int		i;
  int		j;

  if (str == NULL)
    return (NULL);
  if ((tab = my_malloc(sizeof(char *) * my_len_tab(str))) == NULL)
    return (NULL);
  i = 0;
  while (*str != '\0')
    {
      while (*str == ' ' || *str == '\t')
	str++;
      if (*str != '\0')
	{
	  if ((tab[i] = my_malloc(sizeof(char) * my_len_word(str))) == NULL)
	    return (NULL);
	  j = 0;
	  while (*str != ' ' && *str != '\t' && *str != '\0')
	    tab[i][j++] = *str++;
	  tab[i++][j] = '\0';
	}
    }
  tab[i] = NULL;
  return (tab);
}

int		my_aff_wordtab(char **tab)
{
  int		i;

  if (tab == NULL)
    return (1);
  i = 0;
  while (tab[i] != NULL)
    {
      my_putstr(tab[i++], 1);
      my_putchar('\n', 1);
    }
  return (0);
}
