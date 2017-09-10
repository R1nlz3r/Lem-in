/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   touch_t_lem_in_4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 13:39:24 by mapandel          #+#    #+#             */
/*   Updated: 2017/09/10 13:41:18 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
