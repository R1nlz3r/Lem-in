/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 22:04:08 by mapandel          #+#    #+#             */
/*   Updated: 2017/08/23 23:48:36 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	lem_in_search_paths(t_lem_in *li)
{
	(void)li;
}

int		lem_in_checker_doubles(t_lem_in *li, char *name, int x, int y)
{
	int		i;

	i = 0;
	while (i < li->nb_rooms)
	{
		if (!ft_strcmp(li->anthill[i]->name, name)
			|| (li->anthill[i]->x_coor == x && li->anthill[i]->y_coor == y))
			return (1);
		++i;
	}
	return (0);
}
