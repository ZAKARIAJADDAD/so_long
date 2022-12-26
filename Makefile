# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/13 18:38:22 by zjaddad           #+#    #+#              #
#    Updated: 2022/12/26 15:36:34 by zjaddad          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= cc
CFLAGS= -Wall -Wextra -Werror
AR= ar -rc
FRAMEWORK= -lmlx -framework OpenGL -framework AppKit

SRCS=	Libft/ft_strdup.c Libft/ft_substr.c Libft/ft_strncmp.c Libft/ft_split.c Libft/ft_itoa.c \
		Printf/ft_printf.c Printf/ft_printf_utils.c \
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
		so_long_utils.c so_long_utils_1.c map_hndl.c movements.c so_long_utils_2.c

NAME= so_long.a

OBJS= $(SRCS:.c=.o)

all:$(NAME)

$(NAME):$(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o:%.c
	$(CC) -c $? -o $@

clean:
	rm -f $(OBJS)
	
fclean:
	rm -f $(NAME) $(OBJS)
	
re: fclean all

.PHONY: clean fclean all re

# CC= cc 
# CFLAGS= -Wall -Wextra -Werror
# AR= ar -rc

# SRCS=  ft_printf.c ft_printf_utils.c get_next_line_utils.c get_next_line.c ft_split.c \
# 	ft_strdup.c ft_substr.c 

# NAME= so_long.a

# OBJS= $(SRCS:.c=.o)

# all:$(NAME)

# $(NAME):$(OBJS)
# 	$(AR) $(NAME) $(OBJS)

# $(OBJS):$(SRCS)
# 	$(CC) $(CFLAGS) -c $(SRCS)

# clean:
# 	rm -f $(OBJS)
	
# fclean:
# 	rm -f $(NAME) $(OBJS)
	
# re: fclean all

# .PHONY: clean fclean all re

