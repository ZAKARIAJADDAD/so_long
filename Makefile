# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/13 18:38:22 by zjaddad           #+#    #+#              #
#    Updated: 2022/12/15 21:38:06 by zjaddad          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= cc -I
CFLAGS= -Wall -Wextra -Werror
AR= ar -rc
FRAMEWORK= -lmlx -framework OpenGL -framework AppKit

SRCS= so_long_utils.c ft_printf.c ft_printf_utils.c

NAME= so_long.a

OBJS= $(SRCS:.c=.o)

all:$(NAME)

$(NAME):$(OBJS)
	$(AR) $(NAME) $(OBJS)

$(OBJS):$(SRCS)
	$(CC) /usr/local/include -c $(SRCS) -L /usr/local/lib $(FRAMEWORK)

clean:
	rm -f $(OBJS)
	
fclean:
	rm -f $(NAME) $(OBJS)
	
re: fclean all

.PHONY: clean fclean all re