/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:52:53 by zjaddad           #+#    #+#             */
/*   Updated: 2022/12/27 19:24:41 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	pressnbr(int key, t_vars *vars)
{
	static int	count;

	if ((key == 126 || key == 13) && !vars->playerlose)
	{
		if (to_up(vars))
			ft_printf("Key Up N° [%d] Moves [%d]\n", key, ++count);
	}
	else if ((key == 125 || key == 1) && !vars->playerlose)
	{
		if (to_down(vars))
			ft_printf("Key Down N° [%d] Moves [%d]\n", key, ++count);
	}
	else if ((key == 124 || key == 2) && !vars->playerlose)
	{
		if (to_right(vars))
			ft_printf("Key Right N° [%d] Moves [%d]\n", key, ++count);
	}
	else if ((key == 123 || key == 0) && !vars->playerlose)
	{
		if (to_left(vars))
			ft_printf("Key Left N° [%d] Moves [%d]\n", key, ++count);
	}
	else if (key == 53)
		exit(0);
	return (prints_moves(vars, count), 0);
}

int	x_panel(void)
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

void	print_error(char *s)
{
	write(2, s, strlen(s));
	exit(1);
}

void	check_ber_map_err(char **av, t_map *mp)
{
	if (check_map(av[1]) == 0)
	{
		ft_printf("Error !\nIncorrect Extention");
		exit(1);
	}
	if (map_hndl(mp, av) == 0)
	{
		ft_printf("Error !\nInvalid map || No Such File or Directory.");
		exit (1);
	}
}
