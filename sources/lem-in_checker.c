/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 22:04:08 by mapandel          #+#    #+#             */
/*   Updated: 2017/08/26 21:32:02 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		lem_in_is_banned(t_lem_in *li, t_lem_in_room *room)
{
	if (ft_tabfindpos(li->used_rooms, lem_in_find_pos(li, room)))
		return (1);
	else if (li->used_rooms->len > 0
		&& li->used_rooms->tab[0] == lem_in_find_pos(li, room))
		return (1);
	return (0);
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
