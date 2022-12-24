/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 22:20:55 by zjaddad           #+#    #+#             */
/*   Updated: 2022/12/24 01:47:46 by zjaddad          ###   ########.fr       */
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
			else if (mp->main_map[vars->y][vars->x] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win, img->image4,
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
	vars->img.image = mlx_xpm_file_to_image(vars->mlx, "./Images/VOOOLKAN.xpm",
			&(vars->img.width), &(vars->img.height));
	vars->img.image1 = mlx_xpm_file_to_image(vars->mlx, "./Images/GRRRRRRR.xpm",
			&(vars->img.width), &(vars->img.height));
	vars->img.image2 = mlx_xpm_file_to_image(vars->mlx,
			"./Images/75_CHARACTER.xpm", &(vars->img.width), &vars->img.height);
	vars->img.image3 = mlx_xpm_file_to_image(vars->mlx, "./Images/exit.xpm",
			&(vars->img.width), &vars->img.height);
	vars->img.image4 = mlx_xpm_file_to_image(vars->mlx, "./Images/coin.xpm",
			&(vars->img.width), &vars->img.height);
}

int	main(int ac, char **av)
{
	t_vars		vars;

	if (ac == 2)
	{
		check_ber_map_err(av,&(vars.map));
		vars.mlx = mlx_init();
		vars.mlx_win = mlx_new_window(vars.mlx, vars.map.x * CUB,
				vars.map.y * CUB, "2D_Game");
		images(&vars);
		mapping(&vars, &(vars.img), &(vars.map));
		player_postion(&(vars.map), &(vars.player));
		coin_postion(&(vars.map), &(vars.player));
		mlx_key_hook(vars.mlx_win, pressnbr, &vars);
		mlx_string_put(vars.mlx, vars.mlx_win, 10, 10, 0xffffff, "Moves :");
		mlx_hook(vars.mlx_win, 17, 0, x_panel, (void *)0);
		mlx_loop(vars.mlx);
	}
	perror("Error !");
	return (0);
}
