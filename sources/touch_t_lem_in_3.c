/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   touch_t_lem_in_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 22:46:37 by mapandel          #+#    #+#             */
/*   Updated: 2017/08/31 07:28:29 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_lem_in_path		*lem_in_path_start(t_lem_in_path *li_p)
{
	t_lem_in_path	*tmp;

	tmp = li_p;
	while (tmp && tmp->previous)
		tmp = tmp->previous;
	return (tmp);
}

int					lem_in_find_pos(t_lem_in *li, t_lem_in_room *room)
{
	int		i;

	i = 0;
	while (i < li->nb_rooms && li->anthill[i] != room)
		++i;
	return (i);
}

void				lem_in_prepare_search_paths(t_lem_in *li)
{
	if (!(li->start_boo == 2 && li->end_boo == 2) || li->nb_rooms < 2
		|| !li->anthill[li->start_pos]->nb_nexts
		|| !li->anthill[li->end_pos]->nb_nexts)
		lem_in_display_error(li);
	if (li->anthill[li->end_pos]->nb_nexts <
		li->anthill[li->start_pos]->nb_nexts
		&& (li->used_rooms = add_banned_room(li->used_rooms, li->end_pos)))
		li->travel_dir = 1;
	else
		li->used_rooms = add_banned_room(li->used_rooms, li->start_pos);
}
