/*
** get_next_line.h for get_next_line in /home/plasko_a/rendu/PSU_2013_minishell1/header
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Sat Dec 14 22:54:53 2013 Antoine Plaskowski
** Last update Sat Dec 14 23:05:44 2013 Antoine Plaskowski
*/

#ifndef			GET_NEXT_LINE_H_
# define		GET_NEXT_LINE_H_

# define		BUF	4096

typedef struct		s_nline
{
  struct s_nline	*prev;
  char			*str;
  struct s_nline	*next;
}			t_nline;

char			*get_next_line(const int fd, const int reset);

#endif			/* GET_NEXT_LINE_H_ */
