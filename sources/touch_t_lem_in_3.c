/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   touch_t_lem_in_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 22:46:37 by mapandel          #+#    #+#             */
/*   Updated: 2017/09/10 13:44:52 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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

void				del_banned_room(t_tab *used_rooms, int unbanned_pos)
{
	size_t		i;

	i = 0;
	while (i < used_rooms->len && used_rooms->tab[i] != unbanned_pos)
		++i;
	used_rooms->tab[i] = -1;
}

t_tab				*add_banned_room(t_tab *used_rooms, int banned_pos)
{
	size_t		i;

	i = 0;
	while (i < used_rooms->len && used_rooms->tab[i] != -1)
		++i;
	if (i == used_rooms->len)
		used_rooms = ft_tabadd_leakless(used_rooms, banned_pos);
	else
		used_rooms->tab[i] = banned_pos;
	return (used_rooms);
}
