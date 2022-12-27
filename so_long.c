/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 22:20:55 by zjaddad           #+#    #+#             */
/*   Updated: 2022/12/27 14:56:08 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mapping(t_vars *vars, t_data *img, t_map *mp)
{
	vars->y = -1;
	while (mp->main_map[++vars->y])
	{
		vars->x = -1;
		while (mp->main_map[vars->y][++vars->x])
		{
			mlx_put_image_to_window(vars->mlx, vars->mlx_win, img->image1,
				vars->x * CUB, vars->y * CUB);
			if (mp->main_map[vars->y][vars->x] == '1')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win, img->image,
					vars->x * CUB, vars->y * CUB);
			else if (mp->main_map[vars->y][vars->x] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win, img->image2,
					vars->x * CUB, vars->y * CUB);
			else if (mp->main_map[vars->y][vars->x] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win, img->image3,
					vars->x * CUB, vars->y * CUB);
		}
	}
}

void	images(t_vars *vars)
{
	vars->img.image = mlx_xpm_file_to_image(vars->mlx, "./Images/WOL.xpm",
			&(vars->img.width), &(vars->img.height));
	vars->img.image1 = mlx_xpm_file_to_image(vars->mlx, "./Images/grb.xpm",
			&(vars->img.width), &(vars->img.height));
	vars->img.image2 = mlx_xpm_file_to_image(vars->mlx,
			"./Images/PLAYER.xpm", &(vars->img.width), &vars->img.height);
	vars->img.left_player = mlx_xpm_file_to_image(vars->mlx,
			"./Images/PLAYER_LEFT.xpm", &(vars->img.width), &vars->img.height);
	vars->img.image3 = mlx_xpm_file_to_image(vars->mlx,
			"./Images/EXITO_CLS.xpm", &(vars->img.width), &vars->img.height);
	vars->img.ext_opn = mlx_xpm_file_to_image(vars->mlx,
			"./Images/EXITO_OPN.xpm", &(vars->img.width), &vars->img.height);
	vars->img.rip = mlx_xpm_file_to_image(vars->mlx, "./Images/RIP.xpm",
			&(vars->img.width), &vars->img.height);
	vars->img.game_over = mlx_xpm_file_to_image(vars->mlx,
			"./Images/GAME_OVER.xpm", &(vars->img.width), &vars->img.height);
}

void	image_coin(t_vars *vars)
{
	vars->img.coins[0] = mlx_xpm_file_to_image(vars->mlx, "./Images/COINS.xpm",
			&(vars->img.width), &vars->img.height);
	vars->img.coins[1] = mlx_xpm_file_to_image(vars->mlx, "./Images/501.xpm",
			&(vars->img.width), &vars->img.height);
	vars->img.coins[2] = mlx_xpm_file_to_image(vars->mlx, "./Images/502.xpm",
			&(vars->img.width), &vars->img.height);
	vars->img.coins[3] = mlx_xpm_file_to_image(vars->mlx, "./Images/503.xpm",
			&(vars->img.width), &vars->img.height);
	vars->img.coins[4] = mlx_xpm_file_to_image(vars->mlx, "./Images/504.xpm",
			&(vars->img.width), &vars->img.height);
	vars->img.coins[5] = mlx_xpm_file_to_image(vars->mlx, "./Images/505.xpm",
			&(vars->img.width), &vars->img.height);
}

void	image_enmy(t_vars *vars)
{
	vars->img.enmy[0] = mlx_xpm_file_to_image(vars->mlx, "./Images/N1.xpm",
			&(vars->img.width), &vars->img.height);
	vars->img.enmy[1] = mlx_xpm_file_to_image(vars->mlx, "./Images/N2.xpm",
			&(vars->img.width), &vars->img.height);
	vars->img.enmy[2] = mlx_xpm_file_to_image(vars->mlx, "./Images/N3.xpm",
			&(vars->img.width), &vars->img.height);
	vars->img.enmy[3] = mlx_xpm_file_to_image(vars->mlx, "./Images/N4.xpm",
			&(vars->img.width), &vars->img.height);
	vars->img.enmy[4] = mlx_xpm_file_to_image(vars->mlx, "./Images/N5.xpm",
			&(vars->img.width), &vars->img.height);
	vars->img.enmy[5] = mlx_xpm_file_to_image(vars->mlx, "./Images/N6.xpm",
			&(vars->img.width), &vars->img.height);
	vars->img.enmy[6] = mlx_xpm_file_to_image(vars->mlx, "./Images/N7.xpm",
			&(vars->img.width), &vars->img.height);
	vars->img.enmy[7] = mlx_xpm_file_to_image(vars->mlx, "./Images/N8.xpm",
			&(vars->img.width), &vars->img.height);
}

int	main(int ac, char **av)
{
	t_vars		vars;

	vars.index = 0;
	vars.idx = 0;
	vars.timer = 0;
	vars.playerlose = 0;
	if (ac >= 1)
	{
		check_ber_map_err(av, &(vars.map));
		vars.mlx = mlx_init();
		vars.mlx_win = mlx_new_window(vars.mlx, vars.map.x * CUB,
				vars.map.y * CUB, "2D_Game");
		images(&vars);
		image_coin(&vars);
		image_enmy(&vars);
		mapping(&vars, &(vars.img), &(vars.map));
		player_postion(&(vars.map), &(vars.player));
		coin_postion(&(vars.map), &(vars.player));
		exit_position(&(vars.map), &(vars.player));
		mlx_hook(vars.mlx_win, 2, 0, pressnbr, &vars);
		mlx_hook(vars.mlx_win, 17, 0, x_panel, (void *)0);
		mlx_loop_hook(vars.mlx, render, &vars);
		mlx_loop(vars.mlx);
	}
	perror("Error !");
}
