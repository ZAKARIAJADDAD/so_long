/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minilibx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 22:20:55 by zjaddad           #+#    #+#             */
/*   Updated: 2022/12/16 20:51:02 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_data	img;
	char	*p_str;
	int		i;
	
	i = 0;
	if (ac == 2)
	{
		img.mlx = mlx_init();
		img.mlx_win = mlx_new_window(img.mlx, 1080, 600, "2D_Game");
		img.image = mlx_xpm_file_to_image(img.mlx, "./Images/Back_S.xpm",
				&img.width, &img.height);
		mlx_put_image_to_window(img.mlx, img.mlx_win, img.image, 0, 0);
		mlx_key_hook(img.mlx_win, pressnbr, (void *)0);
		//mlx_string_put(img.mlx, img.mlx_win, 10, 10, 0xffffff,"Moves :");
		
		int	fd = open("./Map/map.ber", O_RDONLY);
		p_str = get_next_line(fd);
		while (p_str[i++])
		{
			if (p_str[i] == '1')
				mlx_string_put(img.mlx, img.mlx_win, 10, 10, 0xffffff,"Moves :");
			if (p_str[i] == '0')
				mlx_string_put(img.mlx, img.mlx_win, 10, 10, 0xffffff,"Stop:");
		}
		
		
		mlx_hook(img.mlx_win, 17, 0, X_panel, (void *)0);
		mlx_loop(img.mlx);
	}
	perror("Error !");
	return (0);
}
