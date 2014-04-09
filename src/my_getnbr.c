/*
** my_getnbr.c for my_getnbr in /home/plasko_a/rendu/Piscine-C-Jour_04
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Thu Oct  3 13:27:41 2013 Antoine Plaskowski
** Last update Sun Dec  8 13:52:19 2013 Antoine Plaskowski
*/

#include	<stdlib.h>

static int	my_check_overflow(const char c, const int nbr, int *sign)
{
  if (*sign > 0)
    {
      if ((*sign)++ > 10 || (nbr > 214748364 && (c >= '8' && c <= '9')))
	return (1);
    }
  else
    {
      if ((*sign)++ > 10 || (nbr > 214748364 && c == '9'))
	return (1);
    }
  return (0);
}

int		my_getnbr(const char *str)
{
  int		sign;
  int		nbr;

  if (str == NULL)
    return (0);
  sign = 1;
  while (*str != '\0' && (*str == '-' || *str == '+'))
    if (*str++ == '-')
      sign *= -1;
  while (*str == '0')
    str++;
  nbr = 0;
  while (*str >= '0' && *str <= '9')
    {
      if (sign > 0)
	nbr = nbr * 10 + (*str++ - '0');
      else
	nbr = nbr * 10 - (*str++ - '0');
      if (my_check_overflow(*str, nbr, &sign))
	return (0);
    }
  return (nbr);
}
