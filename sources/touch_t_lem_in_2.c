/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   touch_t_lem_in_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 12:50:06 by mapandel          #+#    #+#             */
/*   Updated: 2017/09/04 03:11:53 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void			del_banned_room(t_tab *used_rooms, int unbanned_pos)
{
	size_t		i;

	i = 0;
	while (i < used_rooms->len && used_rooms->tab[i] != unbanned_pos)
		++i;
	used_rooms->tab[i] = -1;
}

t_tab			*add_banned_room(t_tab *used_rooms, int banned_pos)
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
		exit (-1);
	ft_memcpy(tmp, li->paths, sizeof(t_lem_in_path) * ((size_t)li->nb_paths));
	ft_memdel((void**)&li->paths);
	li->paths = tmp;

}

t_lem_in_path	*init_t_lem_in_path(t_lem_in *li, t_lem_in_path *li_p,
	t_lem_in_path *previous, t_lem_in_room *room)
{
	if (!(li_p = ft_memalloc(sizeof(t_lem_in_path))))
		exit (-1);
	li_p->room = lem_in_find_pos(li, room);
	li_p->next = NULL;
	if (!previous)
		li_p->len = 0;
	else
		li_p->len = previous->len + 1;
	li_p->previous = NULL;
	return (li_p);
}
