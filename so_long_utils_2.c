/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 18:51:18 by zjaddad           #+#    #+#             */
/*   Updated: 2022/12/26 16:12:56 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	death(t_vars *vars, int x, int y)
{
	mlx_destroy_image(vars->mlx, (vars->img).image2);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, (vars->img).image1,
		vars->player.x * CUB, vars->player.y * CUB);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, (vars->img).rip, x, y);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, (vars->img).game_over,
		(vars->map.x * CUB) / 2 - 100, (vars->map.y * CUB) / 2 - 100);
	vars->playerlose = 1;
}

void	exit_position(t_map *mp, t_player *p)
{
	p->exit_y = -1;
	while (mp->main_map[++p->exit_y])
	{
		p->exit_x = 0;
		while (mp->main_map[p->exit_y][p->exit_x])
		{
			if (mp->main_map[p->exit_y][p->exit_x] == 'E')
				return ;
			p->exit_x++;
		}
	}
}

void	render_coins(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (vars->map.main_map[y])
	{
		x = 0;
		while (vars->map.main_map[y][x])
		{
			if (vars->map.main_map[y][x] == 'C')
			{
				mlx_put_image_to_window(vars->mlx, vars->mlx_win, (vars->img).image1,
					x * CUB, y * CUB);
				mlx_put_image_to_window(vars->mlx, vars->mlx_win, 
					vars->img.coins[vars->index], x * CUB, y * CUB);
			}
			x++;
		}
		y++;
	}
}

void	render_enmy(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (vars->map.main_map[y])
	{
		x = 0;
		while (vars->map.main_map[y][x])
		{
			if (vars->map.main_map[y][x] == 'N')
			{
				mlx_put_image_to_window(vars->mlx, vars->mlx_win, (vars->img).image1,
					x * CUB, y * CUB);
				mlx_put_image_to_window(vars->mlx, vars->mlx_win, 
					vars->img.enmy[vars->idx], x * CUB, y * CUB);
			}
			x++;
		}
		y++;
	}
}

int	render(t_vars *vars)
{
	if (vars->timer > 1100)
	{
		vars->timer = 0;
		render_coins(vars);
		render_enmy(vars);
		vars->index++;
		vars->idx++;
		if (vars->index == 6)
			vars->index = 0;
		if (vars->idx == 8)
			vars->idx = 0;
	}
	vars->timer++;
	return (1);
}
