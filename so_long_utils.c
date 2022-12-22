/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:52:53 by zjaddad           #+#    #+#             */
/*   Updated: 2022/12/22 16:58:50 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	pressnbr(int key, void *param)
{
	static int count;
	t_data		img;
	t_vars		vars;

	if (key == 126 || key == 13)
		ft_printf("Key Up N° [%d] Moves [%d]\n", key, ++count);
	else if (key == 125 || key == 1)
		ft_printf("Key Down N° [%d] Moves [%d]\n", key, ++count);
	else if (key == 124 || key == 2)
		ft_printf("Key Right N° [%d] Moves [%d]\n", key, ++count);
	else if (key == 123 || key == 0)
		ft_printf("Key Left N° [%d] Moves [%d]\n", key, ++count);
	 else if (key == 53)
	 	exit(0);
	return (0);
}

int	X_panel(int key, void *param)
{
	exit(0);
	return (0);
}

int	check_map(char *p)
{
	int		i;
	char	*v;

	i = ft_strlen(p);
	v = &p[i - 4];
	if (ft_strncmp(v, ".ber", 4) == 0)
		return (1);
	return (0);
}

void	printError(char *s)
{
	write(2, s, strlen(s));
	exit(1);
}
