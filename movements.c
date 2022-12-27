/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 23:12:54 by zjaddad           #+#    #+#             */
/*   Updated: 2022/12/26 23:40:16 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	to_up(t_vars *vars)
{
	if (vars->map.main_map[vars->player.y - 1][vars->player.x] == 'C')
	{
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, (vars->img).image1,
			vars->player.x * CUB, vars->player.y * CUB - CUB);
		(vars->player.count_coin)--;
		vars->map.main_map[vars->player.y - 1][vars->player.x] = '0';
	}
	if (vars->map.main_map[vars->player.y - 1][vars->player.x] == 'E'
		&& vars->player.count_coin == 0)
		exit_win();
	if (vars->map.main_map[vars->player.y - 1][vars->player.x] == 'N')
		death(vars, vars->player.x * CUB, vars->player.y * CUB - CUB);
	else if (vars->map.main_map[vars->player.y - 1][vars->player.x] != '1'
		&& vars->map.main_map[vars->player.y - 1][vars->player.x] != 'E')
	{
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, (vars->img).image1,
			vars->player.x * CUB, vars->player.y * CUB);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, (vars->img).image2,
			vars->player.x * CUB, (vars->player.y * CUB - CUB));
		(vars->player.y) -= 1;
		return (1);
	}
	return (0);
}

int	to_down(t_vars *vars)
{
	if (vars->map.main_map[vars->player.y + 1][vars->player.x] == 'C')
	{
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, (vars->img).image1,
			vars->player.x * CUB, vars->player.y * CUB + CUB);
		(vars->player.count_coin)--;
		vars->map.main_map[vars->player.y + 1][vars->player.x] = '0';
	}
	if (vars->map.main_map[vars->player.y + 1][vars->player.x] == 'E'
		&& vars->player.count_coin == 0)
		exit_win();
	if (vars->map.main_map[vars->player.y + 1][vars->player.x] == 'N')
		death(vars, vars->player.x * CUB, vars->player.y * CUB + CUB);
	else if (vars->map.main_map[vars->player.y + 1][vars->player.x] != '1'
		&& vars->map.main_map[vars->player.y + 1][vars->player.x] != 'E')
	{
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, (vars->img).image1,
			vars->player.x * CUB, vars->player.y * CUB);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, (vars->img).image2,
			vars->player.x * CUB, (vars->player.y * CUB + CUB));
		(vars->player.y) += 1;
		return (1);
	}
	return (0);
}

int	to_left(t_vars *vars)
{
	if (vars->map.main_map[vars->player.y][vars->player.x - 1] == 'C')
	{
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, (vars->img).image1,
			vars->player.x * CUB - CUB, vars->player.y * CUB);
		(vars->player.count_coin)--;
		vars->map.main_map[vars->player.y][vars->player.x - 1] = '0';
	}
	if (vars->map.main_map[vars->player.y][vars->player.x - 1] == 'E'
		&& vars->player.count_coin == 0)
		exit_win();
	if (vars->map.main_map[vars->player.y][vars->player.x - 1] == 'N')
		death(vars, vars->player.x * CUB - CUB, vars->player.y * CUB);
	else if (vars->map.main_map[vars->player.y][vars->player.x - 1] != '1'
		&& vars->map.main_map[vars->player.y][vars->player.x - 1] != 'E')
	{
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, (vars->img).image1,
			vars->player.x * CUB, vars->player.y * CUB);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			(vars->img).left_player,
			(vars->player.x * CUB - CUB), (vars->player.y * CUB));
		(vars->player.x) -= 1;
		return (1);
	}
	return (0);
}

int	to_right(t_vars *vars)
{
	if (vars->map.main_map[vars->player.y][vars->player.x + 1] == 'C')
	{
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, (vars->img).image1,
			vars->player.x * CUB + CUB, vars->player.y * CUB);
		(vars->player.count_coin)--;
		vars->map.main_map[vars->player.y][vars->player.x + 1] = '0';
	}
	if (vars->map.main_map[vars->player.y][vars->player.x + 1] == 'E'
		&& vars->player.count_coin == 0)
		exit_win();
	if (vars->map.main_map[vars->player.y][vars->player.x + 1] == 'N')
		death(vars, vars->player.x * CUB + CUB, vars->player.y * CUB);
	else if (vars->map.main_map[vars->player.y][vars->player.x + 1] != '1'
		&& vars->map.main_map[vars->player.y][vars->player.x + 1] != 'E')
	{
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, (vars->img).image1,
			vars->player.x * CUB, vars->player.y * CUB);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, (vars->img).image2,
			(vars->player.x * CUB + CUB), (vars->player.y * CUB));
		(vars->player.x) += 1;
		return (1);
	}
	return (0);
}

void	prints_moves(t_vars *vars, int count)
{
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img.image,
		0, 0);
	mlx_string_put(vars->mlx, vars->mlx_win, 25, 25, 0xffffff, ft_itoa(count));
}
