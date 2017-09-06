/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   touch_t_lem_in_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 22:46:37 by mapandel          #+#    #+#             */
/*   Updated: 2017/09/06 03:10:45 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void				lem_in_sort_rooms(t_lem_in *li)
{
	t_lem_in_path	*end;
	int				tmp;
	int				i;

	i = 0;
	if (!li->travel_dir)
		return ;
	while (i < li->nb_paths)
	{
		end = lem_in_path_end(li->paths[i]);
		li->paths[i] = lem_in_path_start(li->paths[i]);
		while (li->paths[i] != end && li->paths[i]->previous != end)
		{
			tmp = li->paths[i]->room;
			li->paths[i]->room = end->room;
			end->room = tmp;
			end = end->previous;
			li->paths[i] = li->paths[i]->next;
		}
		++i;
		li->paths[i] = lem_in_path_start(li->paths[i]);
	}
}

void				lem_in_sort_paths(t_lem_in *li)
{
	t_lem_in_path	*tmp;
	int				tmppos;
	int				i;
	int				j;

	i = 0;
	while (i < li->nb_paths && (li->paths[i] = lem_in_path_end(li->paths[i])))
		++i;
	i = 0;
	while (i < li->nb_paths - 1)
	{
		tmppos = i;
		j = i + 1;
		while (j < li->nb_paths)
		{
			if (li->paths[tmppos]->len > li->paths[j]->len)
				tmppos = j;
			++j;
		}
		tmp = li->paths[i];
		li->paths[i] = li->paths[tmppos];
		li->paths[tmppos] = tmp;
		++i;
	}
}

t_lem_in_path		*lem_in_path_end(t_lem_in_path *li_p)
{
	t_lem_in_path	*tmp;

	tmp = li_p;
	while (tmp && tmp->next)
		tmp = tmp->next;
	return (tmp);
}

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
