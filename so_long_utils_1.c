/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:03:55 by zjaddad           #+#    #+#             */
/*   Updated: 2022/12/25 18:36:41 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_nwline(char *t)
{
	int	i;

	i = 0;
	while (t[i])
	{
		if (t[i] == '\n' && t[i + 1] == '\n')
		{
			ft_printf("Error !: Invalid map");
			exit(1);
		}
		i++;
	}
}

void	player_postion(t_map *mp, t_player *ps)
{	
	ps->y = -1;
	while (mp->main_map[++ps->y])
	{
		ps->x = 0;
		while (mp->main_map[ps->y][ps->x])
		{
			if (mp->main_map[ps->y][ps->x] == 'P')
				return ;
			ps->x++;
		}
	}
}

void	coin_postion(t_map *mp, t_player *ps)
{	
	ps->coin_y = -1;
	ps->count_coin = 0;
	while (mp->main_map[++ps->coin_y])
	{
		ps->coin_x = 0;
		while (mp->main_map[ps->coin_y][ps->coin_x])
		{
			if (mp->main_map[ps->coin_y][ps->coin_x] == 'C')
				ps->count_coin++;
			ps->coin_x++;
		}
	}
}

void	hight_wight_mp(t_map *mp)
{
	mp->y = 0;
	while (mp->main_map[mp->y])
	{
		mp->x = 0;
		while (mp->main_map[mp->y][mp->x])
			mp->x++;
		mp->y++;
	}
}

void	exit_win(void)
{
	ft_printf("\033[0;32m\n \
	██╗   ██╗ ██████╗ ██╗   ██╗    ██╗    ██╗██╗███╗   ██╗\n \
	╚██╗ ██╔╝██╔═══██╗██║   ██║    ██║    ██║██║████╗  ██║\n \
	 ╚████╔╝ ██║   ██║██║   ██║    ██║ █╗ ██║██║██╔██╗ ██║\n \
	  ╚██╔╝  ██║   ██║██║   ██║    ██║███╗██║██║██║╚██╗██║\n \
	   ██║   ╚██████╔╝╚██████╔╝    ╚███╔███╔╝██║██║ ╚████║\n \
	   ╚═╝    ╚═════╝  ╚═════╝      ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝");
	exit(0);
}
