/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:58:25 by zjaddad           #+#    #+#             */
/*   Updated: 2022/12/20 19:34:57 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strdup(const char *s1)
{
	char	*plloc;
	int		i;

	i = 0;
	plloc = malloc(ft_strlen(s1) + 1);
	if (!plloc)
		return (NULL);
	while (s1[i])
	{
		plloc[i] = s1[i];
		i++;
	}
	plloc[i] = '\0';
	return (plloc);
}
