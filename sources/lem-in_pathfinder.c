/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in_pathfinder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 14:18:59 by mapandel          #+#    #+#             */
/*   Updated: 2017/09/04 07:14:02 by mapandel         ###   ########.fr       */
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
	{
		++li->nb_paths;
		lem_in_search_paths(li);
	}
	while (cur_next < cur->nb_nexts)
	{
		while ((cur_next < cur->nb_nexts
			&& lem_in_is_banned(li, cur->next[cur_next]))
			|| (((li_p->room == li->start_pos || li_p->room == li->end_pos)
			&& (lem_in_find_pos(li, cur->next[cur_next]) == li->start_pos
			|| lem_in_find_pos(li, cur->next[cur_next]) == li->end_pos))
			&& (li->b_littlepath = 1)))
			++cur_next;
		if (cur_next == cur->nb_nexts)
			break ;
		li_p->next = init_t_lem_in_path(li, li_p->next, li_p, cur->next[cur_next]);
		li_p->next->previous = li_p;
		li_p = li_p->next;
		if ((!li->travel_dir && lem_in_find_pos(li, cur->next[cur_next]) != li->end_pos)
			|| (li->travel_dir && lem_in_find_pos(li, cur->next[cur_next]) != li->start_pos))
			li->used_rooms = add_banned_room(li->used_rooms, lem_in_find_pos(li, cur->next[cur_next]));
		lem_in_search_paths_backtrack(li, li_p, cur->next[cur_next]);
		++cur_next;
	}
	del_banned_room(li->used_rooms, lem_in_find_pos(li, cur));
}

void			lem_in_search_paths(t_lem_in *li)
{
	lem_in_add_path(li);
	if ((!li->travel_dir && li->nb_paths < li->anthill[li->start_pos]->nb_nexts)
		|| (li->travel_dir && li->nb_paths < li->anthill[li->end_pos]->nb_nexts))
	{
		if (!li->travel_dir && (li->paths[li->nb_paths] = init_t_lem_in_path(li,
			li->paths[li->nb_paths], NULL, li->anthill[li->start_pos])))
			lem_in_search_paths_backtrack(li, li->paths[li->nb_paths], li->anthill[li->start_pos]);
		else if ((li->paths[li->nb_paths] = init_t_lem_in_path(li,
			li->paths[li->nb_paths], NULL, li->anthill[li->end_pos])))
			lem_in_search_paths_backtrack(li, li->paths[li->nb_paths], li->anthill[li->end_pos]);
	}
	if (li->b_littlepath)
	{
		if (!li->travel_dir)
		{
			if (!li->paths[li->nb_paths]->next)
				li->paths[li->nb_paths]->next = init_t_lem_in_path(li,
				li->paths[li->nb_paths]->next, li->paths[li->nb_paths],
				li->anthill[li->end_pos]);
			li->paths[li->nb_paths]->next->room = lem_in_find_pos(li, li->anthill[li->end_pos]);
			li->paths[li->nb_paths]->next->previous = li->paths[li->nb_paths];
			li->paths[li->nb_paths] = li->paths[li->nb_paths]->next;
		}
		else
		{
			if (!li->paths[li->nb_paths]->next)
				li->paths[li->nb_paths]->next = init_t_lem_in_path(li,
				li->paths[li->nb_paths]->next, li->paths[li->nb_paths],
				li->anthill[li->start_pos]);
			li->paths[li->nb_paths]->next->room = lem_in_find_pos(li, li->anthill[li->start_pos]);
			li->paths[li->nb_paths]->next->previous = li->paths[li->nb_paths];
			li->paths[li->nb_paths] = li->paths[li->nb_paths]->next;
		}
		++li->nb_paths;
	}
	if (!li->nb_paths)
		lem_in_display_error(li);
	else
		lem_in_move_ants(li);
}
