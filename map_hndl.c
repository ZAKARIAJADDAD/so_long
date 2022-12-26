/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_hndl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:03:44 by zjaddad           #+#    #+#             */
/*   Updated: 2022/12/25 18:27:24 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_p_e_c(char **sp, t_player *plyr)
{
	int	i;
	int	j;

	i = 0;
	plyr->p_check = 0;
	plyr->ext_check = 0;
	plyr->collect = 0;
	while (sp[i])
	{
		j = 0;
		while (sp[i][j])
		{
			if (sp[i][j] == 'P')
				plyr->p_check++;
			if (sp[i][j] == 'E')
				plyr->ext_check++;
			if (sp[i][j] == 'C')
				plyr->collect++;
			j++;
		}
		i++;
	}
	if (plyr->p_check != 1 || plyr->collect == 0 || plyr->ext_check != 1)
		return (0);
	return (1);
}

int	inside_square(char *isd)
{
	int	i;

	i = 0;
	while (isd[i])
	{
		if (isd[0] != '1' || isd[ft_strlen(isd) - 1] != '1')
			return (0);
		else if (isd[i] != '1' && isd[i] != '0'
			&& isd[i] != 'P' && isd[i] != 'E' && isd[i] != 'C'
			&& isd[i] != 'N')
			return (0);
		i++;
	}
	return (1);
}

int	check_square_map(char **one, t_map *mp)
{
	int	i;
	int	j;

	i = 0;
	while (one[i])
	{
		if (i == 0 || i == (mp->y - 1))
		{
			j = 0;
			while (one[i][j])
			{
				if (one[i][j] != '1')
					print_error("Error!\nMissing Wall or Foreign Character");
				j++;
			}	
		}
		if (i > 0 || i < (mp->y - 1))
		{
			if (inside_square(one[i]) == 0)
				print_error("Error!\nMissing Wall or Foreign Character");
		}
		i++;
	}
	return (1);
}

void	map_lent(char **s, t_map *mp)
{
	int	i;
	int	first_line;

	i = 1;
	if (check_square_map(s, mp))
	{
		first_line = ft_strlen(s[0]);
		while (s[i])
		{
			if (ft_strlen(s[i]) != first_line)
				print_error("Error\nMap Not Rectangle\n");
			i++;
		}
	}
}

int	map_hndl(t_map *mp, char **av)
{
	char		*s;
	t_player	plyr;

	mp->part = NULL;
	mp->fd = open(av[1], O_RDONLY);
	if (mp->fd == -1)
		return (0);
	s = get_next_line(mp->fd);
	while (s != NULL)
	{
		mp->part = ft_strjoin(mp->part, s);
		free(s);
		s = get_next_line(mp->fd);
	}
	check_nwline(mp->part);
	mp->main_map = ft_split(mp->part, '\n');
	hight_wight_mp(mp);
	map_lent(mp->main_map, mp);
	mp->check_lent = check_p_e_c(mp->main_map, &plyr);
	return (mp->check_lent);
}
