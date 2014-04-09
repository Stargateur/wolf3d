##
## Makefile for lol in /home/plasko_a/rendu/MUL_2013_wolf3d
## 
## Made by Antoine PLASKOWSKI
## Login   <plasko_a@epitech.net>
## 
## Started on  Fri Jan  3 12:53:41 2014 Antoine PLASKOWSKI
## Last update Sun Jan 12 22:29:18 2014 Antoine PLASKOWSKI
##

CC	=	gcc

RM	=	rm -f

CFLAGS	+=	-Wextra -Wall -O3
CFLAGS	+=	-ansi -pedantic
CFLAGS	+=	-I header/

LDFLAGS	+=	-l X11 -l m

NAME	=	wolf3d

SRC	+=	src/main.c
SRC	+=	src/my_put_pixel_to_img.c
SRC	+=	src/my_struct_color.c
SRC	+=	src/my_struct_coord.c
SRC	+=	src/my_x.c
SRC	+=	src/my_bmp.c
SRC	+=	src/my_event_resize.c
SRC	+=	src/my_event_expose.c
SRC	+=	src/my_event_e_m_motion_notify.c
SRC	+=	src/my_event_e_m_key_press.c
SRC	+=	src/my_resize_map.c
SRC	+=	src/my_image.c
SRC	+=	src/my_menu.c
SRC	+=	src/my_event_menu.c
SRC	+=	src/my_game.c
SRC	+=	src/my_img_game.c
SRC	+=	src/my_k.c
SRC	+=	src/my_key.c
SRC	+=	src/my_player.c
SRC	+=	src/my_edit_map.c
SRC	+=	src/my_load_map.c
SRC	+=	src/my_save_map.c
SRC	+=	src/my_tool_map.c
SRC	+=	src/my_load_texture.c
SRC	+=	src/my_tool.c
SRC	+=	src/my_char_in_str.c
SRC	+=	src/my_str_to_wordtab.c
SRC	+=	src/my_malloc.c
SRC	+=	src/my_putchar.c
SRC	+=	src/my_putstr.c
SRC	+=	src/my_getnbr.c
SRC	+=	src/my_putnbr.c
SRC	+=	src/my_strcpy.c
SRC	+=	src/my_strlen.c
SRC	+=	src/get_next_line.c
SRC	+=	src/my_open.c

OBJ	=	$(SRC:.c=.o)


all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
