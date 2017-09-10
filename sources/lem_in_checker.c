/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 22:04:08 by mapandel          #+#    #+#             */
/*   Updated: 2017/09/10 13:39:58 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		lem_in_checker_ants(t_lem_in *li)
{
	t_lem_in_path	*tmp;
	int				i;

	i = 0;
	if (li->nb_ant != li->nb_ant_backup)
		return (1);
	while (i < li->nb_paths)
	{
		tmp = lem_in_path_start(li->paths[i]);
		while (tmp)
		{
			if (tmp->ant)
				return (1);
			tmp = tmp->next;
		}
		++i;
	}
	return (0);
}

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
