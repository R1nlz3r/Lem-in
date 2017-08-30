/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in_pathfinder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 14:18:59 by mapandel          #+#    #+#             */
/*   Updated: 2017/08/30 23:00:33 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static void		lem_in_search_paths_backtrack(t_lem_in *li, t_lem_in_path *li_p,
	t_lem_in_room *cur)
{
	int		cur_next;

	cur_next = 0;
	if ((!li->travel_dir && li_p->room == li->end_pos)
		|| (li->travel_dir && li_p->room == li->start_pos))
		return ;
	while (cur_next < cur->nb_nexts)
	{
		while (cur_next < cur->nb_nexts
			&& lem_in_is_banned(li, cur->next[cur_next]))
			++cur_next;
		if (cur_next == cur->nb_nexts)
			break ;
		li_p->next = init_t_lem_in_path(li, li_p->next, li_p, cur->next[cur_next]);
		li_p->next->previous = li_p;
		li_p = li_p->next;
		li->used_rooms = add_banned_room(li->used_rooms, lem_in_find_pos(li, cur->next[cur_next]));
		lem_in_search_paths_backtrack(li, li_p, cur->next[cur_next]);
		if ((!li->travel_dir && li_p->room == li->end_pos)
			|| (li->travel_dir && li_p->room == li->start_pos))
			return ;
		++cur_next;
	}
	del_t_lem_in_path_chain(li_p);
	del_banned_room(li->used_rooms, lem_in_find_pos(li, cur));
}

void			lem_in_search_paths(t_lem_in *li)
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
	while ((!li->travel_dir && li->nb_paths < li->anthill[li->start_pos]->nb_nexts)
		|| (li->travel_dir && li->nb_paths < li->anthill[li->end_pos]->nb_nexts))
	{
		if (!li->travel_dir && (li->paths[li->nb_paths] = init_t_lem_in_path(li,
			li->paths[li->nb_paths], NULL, li->anthill[li->start_pos])))
			lem_in_search_paths_backtrack(li, li->paths[li->nb_paths], li->anthill[li->start_pos]);
		else if ((li->paths[li->nb_paths] = init_t_lem_in_path(li,
			li->paths[li->nb_paths], NULL, li->anthill[li->end_pos])))
			lem_in_search_paths_backtrack(li, li->paths[li->nb_paths], li->anthill[li->end_pos]);
		if (!li->paths[li->nb_paths])
			break ;
		else
			++li->nb_paths;
	}
	if (!li->paths[0])
		lem_in_display_error(li);
}
