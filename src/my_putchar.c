/*
** my_putchar.c for putchar in /home/plasko_a/rendu/Piscine-C-lib/my
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Mon Oct 21 10:46:02 2013 Antoine Plaskowski
** Last update Tue Jan  7 14:17:49 2014 Antoine PLASKOWSKI
*/

#include	<unistd.h>

int		my_putchar(const char c, const int fd)
{
  if (write(fd, &c, 1) != 1)
    return (0);
  return (1);
}
