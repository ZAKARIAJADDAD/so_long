/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 23:12:54 by zjaddad           #+#    #+#             */
/*   Updated: 2022/12/24 01:45:19 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	up_move(t_vars *vars)
{
	if(vars->map.main_map[vars->player.y - 1][vars->player.x] != '1'
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

int	down_move(t_vars *vars)
{
	if(vars->map.main_map[vars->player.y + 1][vars->player.x] != '1'
		&& vars->map.main_map[vars->player.y + 1][vars->player.x] != 'E')
	{
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, (vars->img).image1,
				vars->player.x * CUB, vars->player.y * CUB);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, (vars->img).image2,
				vars->player.x * CUB, (vars->player.y * CUB +  CUB));
		(vars->player.y) += 1;
		return (1);
	}
	return (0);
}

int	left_move(t_vars *vars)
{
	if(vars->map.main_map[vars->player.y][vars->player.x - 1] != '1'
		&& vars->map.main_map[vars->player.y][vars->player.x - 1] != 'E')
	{
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, (vars->img).image1,
				vars->player.x * CUB, vars->player.y * CUB);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, (vars->img).image2,
				(vars->player.x * CUB - CUB) , (vars->player.y * CUB));
		(vars->player.x) -= 1;
		return (1);
	}
	return (0);
}

int	right_move(t_vars *vars)
{
	if(vars->map.main_map[vars->player.y][vars->player.x + 1] != '1'
		&& vars->map.main_map[vars->player.y][vars->player.x + 1] != 'E')
	{
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, (vars->img).image1,
				vars->player.x * CUB, vars->player.y * CUB);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, (vars->img).image2,
				(vars->player.x * CUB + CUB) , (vars->player.y * CUB));
		(vars->player.x) += 1;
		return (1);	
	}
	return (0);
}