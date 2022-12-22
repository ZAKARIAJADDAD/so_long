/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minilibx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 22:20:55 by zjaddad           #+#    #+#             */
/*   Updated: 2022/12/22 16:59:09 by zjaddad          ###   ########.fr       */
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
			mlx_put_image_to_window(vars->mlx, vars->mlx_win, img->image1, vars->x * CUB, vars->y * CUB);
			if (mp->main_map[vars->y][vars->x] == '1')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win, img->image, vars->x * CUB, vars->y * CUB);
			else if (mp->main_map[vars->y][vars->x] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win, img->image4, vars->x * CUB, vars->y * CUB);
			else if (mp->main_map[vars->y][vars->x] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win, img->image2, vars->x * CUB, vars->y * CUB);
			else if (mp->main_map[vars->y][vars->x] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win, img->image3, vars->x * CUB, vars->y * CUB);
		}
	}
}

void	images(t_vars *vars, t_data *img)
{
	img->image = mlx_xpm_file_to_image(vars->mlx, "./Images/WAALL.xpm",
			&img->width, &img->height);
	img->image1 = mlx_xpm_file_to_image(vars->mlx, "./Images/GROUND_NN.xpm",
			&img->width, &img->height);
	img->image2 = mlx_xpm_file_to_image(vars->mlx, "./Images/EVILLL.xpm",
			&img->width, &img->height);
	img->image3 = mlx_xpm_file_to_image(vars->mlx, "./Images/EXIT_DOOR.xpm",
			&img->width, &img->height);
	img->image4 = mlx_xpm_file_to_image(vars->mlx, "./Images/AnyConv.com__samurai (1).xpm",
				&img->width, &img->height);
}

int	main(int ac, char **av)
{
	t_data	img;
	t_vars	vars;
	t_map	mp;
	
	if (ac == 2)
	{
		if (check_map(av[1]) == 0)
		{
			ft_printf("Error !: Incorrect extention");
			return(0);
		}
		if (map_hndl(&mp) == 0)
		{
			ft_printf("Error !: Invalid map.");
			return (0);
		}
		vars.mlx = mlx_init();
		vars.mlx_win = mlx_new_window(vars.mlx, mp.x * CUB, mp.y * CUB, "2D_Game");
		images(&vars, &img);
		mapping(&vars, &img, &mp);
		mlx_key_hook(vars.mlx_win, pressnbr, (void *)0);
		mlx_string_put(vars.mlx, vars.mlx_win, 10, 10, 0xffffff,"Moves :");
		mlx_hook(vars.mlx_win, 17, 0, X_panel, (void *)0);
		mlx_loop(vars.mlx);
	}
	perror("Error !");
	return (0);
}
