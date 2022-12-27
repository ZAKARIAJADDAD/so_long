/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:53:22 by zjaddad           #+#    #+#             */
/*   Updated: 2022/12/27 15:38:14 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define CNT
// # define HIGHT
# define CUB 80

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

//Struct////////////////////////////////

typedef struct s_data {
	int		width;
	int		height;
	void	*image;
	void	*image1;
	void	*image2;
	void	*image3;
	void	*image4;
	void	*ext_opn;
	void	*coins[6];
	void	*enmy[8];
	void	*rip;
	void	*left_player;
	void	*game_over;

}	t_data;

typedef struct player {
	int	x;
	int	y;
	int	coin_x;
	int	coin_y;
	int	count_coin;
	int	p_check;
	int	ext_check;
	int	collect;
	int	exit_y;
	int	exit_x;
}	t_player;

typedef struct map {
	char		**main_map;
	char		*part;
	int			check_lent;
	int			y;
	int			x;
	char		**fk_map_e;
	char		**fk_map_c;
	int			fake_coin;
	int			fake_ext;
	int			fd;
	int			count_exit;
	int			count_collectibles;
	t_player	plyr;
}	t_map;

typedef struct t_init {
	void		*mlx;
	void		*mlx_win;
	int			x;
	int			y;
	int			fd;
	int			playerlose;
	int			timer;
	int			index;
	int			idx;
	t_data		img;
	t_player	player;
	t_map		map;
}	t_vars;

//Struct/////////////////////////////////

int		pressnbr(int key, t_vars *vars);
int		x_panel(void);
int		check_map(char *p);
int		map_hndl(t_map *mp, char **av);
void	map_lent(char **s, t_map *mp);
void	print_error(char *s);
void	check_ber_map_err(char **av, t_map *mp);
void	check_nwline(char *t);
void	player_postion(t_map *mp, t_player *ps);
void	check_keys(int key);
void	coin_postion(t_map *mp, t_player *ps);
void	exit_position(t_map *mp, t_player *ps);
int		to_up(t_vars *vars);
int		to_down(t_vars *vars);
int		to_left(t_vars *vars);
int		to_right(t_vars *vars);
int		render(t_vars *vars);
void	hight_wight_mp(t_map *mp);
void	prints_moves(t_vars *vars, int count);
void	exit_win(void);
void	death(t_vars *vars, int x, int y);
void	check_path(t_map *mp);

//printf functions///////////////////////////////
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(int nb);
int		ft_unsnbr(unsigned int nb);
int		ft_hexdecimal(unsigned long nb, char *base);
int		ft_printf(const char *arg, ...);
//End printf functions////////////////////////////

//get_next_line functions//////////////////////////
char	*get_next_line(int fd);
char	*ft_strchr(char *str, int c);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s1);
void	*ft_calloc(size_t n, size_t size);
void	ft_bzero(void *s, size_t n);
//End get_next_line functions/////////////////////

//Libft functions////////////////////////////////
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strncmp(char *s1, char *s2, size_t n);
char	*ft_itoa(int n);
//End Libft functions/////////////////////////////

#endif