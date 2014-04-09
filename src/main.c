/*
** main.c for tp1 in /home/plasko_a/Documents/PROJET/tp1minilib
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Tue Nov  5 14:11:49 2013 Antoine Plaskowski
** Last update Sun Jan 12 09:11:53 2014 Antoine PLASKOWSKI
*/

#include	<stdlib.h>
#include	"my_x.h"
#include	"my_menu.h"
#include	"my_str.h"

static char	*my_search_map(char **argv)
{
  while (*argv)
    {
      if (**argv == '-')
	{
	  if (my_char_in_str('m', *argv) != -1)
	    return (*(argv + 1));
	}
      argv++;
    }
  return ("campaign/map1.map");
}

int		main(int argc, char **argv)
{
  t_xvar	*xvar;
  if (!(xvar = my_init()))
    return (1);
  my_create_window(xvar);
  argv[argc] = NULL;
  my_menu(xvar, my_search_map(argv));
  XCloseDisplay(xvar->dpy);
  free(xvar);
  return (0);
}
