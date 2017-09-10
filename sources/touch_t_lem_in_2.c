/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   touch_t_lem_in_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 12:50:06 by mapandel          #+#    #+#             */
/*   Updated: 2017/09/10 13:40:30 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			del_t_lem_in_path(t_lem_in_path *li_p)
{
	t_lem_in_path	*tmp;

	li_p = lem_in_path_start(li_p);
	while (li_p)
	{
		tmp = li_p->next;
		ft_memdel((void**)&li_p);
		li_p = tmp;
	}
}

void			del_t_lem_in_path_chain(t_lem_in_path *li_p)
{
	t_lem_in_path	*tmp;

	if ((tmp = li_p->previous))
		li_p->previous->next = NULL;
	ft_memdel((void**)&li_p);
	li_p = tmp;
}

void			lem_in_add_path(t_lem_in *li)
{
	void	*tmp;

	if (!(tmp = ft_memalloc(sizeof(t_lem_in_path) * ((size_t)li->nb_paths
		+ 1))))
		exit(-1);
	ft_memcpy(tmp, li->paths, sizeof(t_lem_in_path) * ((size_t)li->nb_paths));
	ft_memdel((void**)&li->paths);
	li->paths = tmp;
}

t_lem_in_path	*init_t_lem_in_path(t_lem_in *li, t_lem_in_path *li_p,
	t_lem_in_path *previous, t_lem_in_room *room)
{
	if (!(li_p = ft_memalloc(sizeof(t_lem_in_path))))
		exit(-1);
	li_p->room = lem_in_find_pos(li, room);
	li_p->next = NULL;
	if (!previous)
		li_p->len = 0;
	else
		li_p->len = previous->len + 1;
	li_p->ant = 0;
	li_p->previous = NULL;
	return (li_p);
}

int				lem_in_link_rooms(t_lem_in_room *r1, t_lem_in_room *r2)
{
	int		i;
	void	*tmp;

	i = 0;
	while (i < r1->nb_nexts)
	{
		if (r1->next[i] == r2)
			return (-1);
		++i;
	}
	if (!(tmp = ft_memalloc(sizeof(t_lem_in_room) * ((size_t)r1->nb_nexts
		+ 1))))
		exit(-1);
	ft_memcpy(tmp, r1->next, sizeof(t_lem_in_room) * ((size_t)r1->nb_nexts));
	ft_memdel((void**)&r1->next);
	r1->next = tmp;
	r1->next[r1->nb_nexts++] = r2;
	if (!(tmp = ft_memalloc(sizeof(t_lem_in_room) * ((size_t)r2->nb_nexts
		+ 1))))
		exit(-1);
	ft_memcpy(tmp, r2->next, sizeof(t_lem_in_room) * ((size_t)r2->nb_nexts));
	ft_memdel((void**)&r2->next);
	r2->next = tmp;
	r2->next[r2->nb_nexts++] = r1;
	return (0);
}
