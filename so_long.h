/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:53:22 by zjaddad           #+#    #+#             */
/*   Updated: 2022/12/16 20:34:54 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <stdarg.h>
# include<fcntl.h>
# include<string.h>

int	pressnbr(int key, void *param);
int	X_panel(int key, void *param);
//printf functions
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int nb);
int	ft_unsnbr(unsigned int nb);
int	ft_hexdecimal(unsigned long nb, char *base);
int	ft_printf(const char *arg, ...);
//End printf functions


//get_next_line functions
char	*get_next_line(int fd);
char	*ft_strchr(char *str, int c);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s1);
void	*ft_calloc(size_t n, size_t size);
void	ft_bzero(void *s, size_t n);
//End get_next_line functions

typedef	struct	s_data {
	int		width;
	int		height;
	void	*mlx;
	void	*mlx_win;
	void	*image;

}	t_data;

#endif