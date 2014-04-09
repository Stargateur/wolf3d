/*
** my_put_nbr.c for my_put_nbr in /home/plasko_a/rendu/Piscine-C-Jour_03
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Wed Oct  2 13:24:35 2013 Antoine Plaskowski
** Last update Tue Jan  7 14:17:31 2014 Antoine PLASKOWSKI
*/

#include	"my_str.h"

int		my_putnbr(int nb, const int fd)
{
  int		i;

  i = 0;
  if (nb / 10 != 0)
    i = my_putnbr(nb / 10, fd);
  else if (nb < 0)
    i += my_putchar('-', fd);
  if ((nb %= 10) < 0)
    nb *= -1;
  return (i + my_putchar(nb + '0', fd));
}
