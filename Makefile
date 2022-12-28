# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/13 18:38:22 by zjaddad           #+#    #+#              #
#    Updated: 2022/12/27 19:47:29 by zjaddad          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= cc
CFLAGS= -Wall -Wextra -Werror
AR= ar -rc
FRAMEWORK= -lmlx -framework OpenGL -framework AppKit

SRCS=	Libft/ft_substr.c Libft/ft_strncmp.c Libft/ft_split.c Libft/ft_itoa.c \
		Printf/ft_printf.c Printf/ft_printf_utils.c \
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
		so_long_utils.c so_long_utils_1.c map_hndl.c movements.c so_long_utils_2.c \
		flood_fill.c so_long.c

NAME= so_long

OBJS= $(SRCS:.c=.o)

all:$(NAME)

$(NAME):$(OBJS)
	$(CC) $(OBJS) $(FRAMEWORK) -o $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	
fclean:
	rm -f $(NAME) $(OBJS)
	
re: fclean all

.PHONY: clean fclean all re
