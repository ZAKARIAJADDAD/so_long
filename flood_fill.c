/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:37:58 by zjaddad           #+#    #+#             */
/*   Updated: 2022/12/27 18:27:39 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	floodfill(t_map *mp, int y, int x)
{
	if (x < 0 || x >= mp->x || y < 0 || y >= mp->y)
		return ;
	if (mp->fk_map_c[y][x] == '1')
		return ;
	if (mp->fk_map_c[y][x] == 'C' || mp->fk_map_c[y][x] == 'E')
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
	mp->fk_map_c = ft_split(mp->part, '\n');
	floodfill(mp, mp->plyr.y, mp->plyr.x);
	if (mp->fake_coin != (mp->plyr.count_coin + 1))
	{
		ft_printf("ERROR !\nPath Problem.");
		exit(1);
	}
}
