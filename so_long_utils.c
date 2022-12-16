/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:52:53 by zjaddad           #+#    #+#             */
/*   Updated: 2022/12/15 21:33:03 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	pressnbr(int key, void *param)
{
	static int y;

	if (key == 126)
		ft_printf("Key Up N° [%d] Moves [%d]\n", key, y);
	else if (key == 125)
		ft_printf("Key Down N° [%d] Moves [%d]\n", key, y);
	else if (key == 124)
		ft_printf("Key Right N° [%d] Moves [%d]\n", key, y);
	else if (key == 123)
		ft_printf("Key Left N° [%d] Moves [%d]\n", key, y);
	else if (key == 13)
		ft_printf("Key Up N° [%d] Moves [%d]\n", key, y);
	else if (key == 1)
		ft_printf("Key Down N° [%d] Moves [%d]\n", key, y);
	else if (key == 2)
		ft_printf("Key Right N° [%d] Moves [%d]\n", key, y);
	else if (key == 0)
		ft_printf("Key Left N° [%d] Moves [%d]\n", key, y);
	 else if (key == 53)
	 	exit(1);
	else
		return (0);
	++y;
	return (0);
}

int	X_panel(int key, void *param)
{
	exit(1);
	return (0);
}
