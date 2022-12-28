/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:37:58 by zjaddad           #+#    #+#             */
/*   Updated: 2022/12/27 18:38:44 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	floodfill_e(t_map *mp, int y, int x)
{
	if (x < 0 || x >= mp->x || y < 0 || y >= mp->y)
		return ;
	if (mp->fk_map_e[y][x] == '1')
		return ;
	if (mp->fk_map_e[y][x] == 'E')
		mp->fake_ext += 1;
	mp->fk_map_e[y][x] = '1';
	floodfill_e(mp, y, x - 1);
	floodfill_e(mp, y, x + 1);
	floodfill_e(mp, y - 1, x);
	floodfill_e(mp, y + 1, x);
}

void	floodfill(t_map *mp, int y, int x)
{
	if (x < 0 || x >= mp->x || y < 0 || y >= mp->y)
		return ;
	if (mp->fk_map_c[y][x] == '1' || mp->fk_map_c[y][x] == 'E')
		return ;
	if (mp->fk_map_c[y][x] == 'C')
		mp->fake_coin += 1;
	mp->fk_map_c[y][x] = '1';
	floodfill(mp, y, x - 1);
	floodfill(mp, y, x + 1);
	floodfill(mp, y - 1, x);
	floodfill(mp, y + 1, x);
}

void	check_path(t_map *mp)
{
	mp->fake_coin = 0;
	mp->fake_ext = 0;
	mp->fk_map_c = ft_split(mp->part, '\n');
	mp->fk_map_e = ft_split(mp->part, '\n');
	floodfill(mp, mp->plyr.y, mp->plyr.x);
	floodfill_e(mp, mp->plyr.y, mp->plyr.x);
	if ((mp->fake_coin != mp->plyr.count_coin) || mp->fake_ext != 1)
	{
		ft_printf("ERROR !\nPath Problem.");
		exit(1);
	}
}
