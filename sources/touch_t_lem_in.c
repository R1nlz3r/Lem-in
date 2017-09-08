/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   touch_t_lem_in.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 13:49:35 by mapandel          #+#    #+#             */
/*   Updated: 2017/09/08 05:48:11 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

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
		exit (-1);
	ft_memcpy(tmp, r1->next, sizeof(t_lem_in_room) * ((size_t)r1->nb_nexts));
	ft_memdel((void**)&r1->next);
	r1->next = tmp;
	r1->next[r1->nb_nexts++] = r2;
	if (!(tmp = ft_memalloc(sizeof(t_lem_in_room) * ((size_t)r2->nb_nexts
		+ 1))))
		exit (-1);
	ft_memcpy(tmp, r2->next, sizeof(t_lem_in_room) * ((size_t)r2->nb_nexts));
	ft_memdel((void**)&r2->next);
	r2->next = tmp;
	r2->next[r2->nb_nexts++] = r1;
	return (0);
}

void			lem_in_add_room(t_lem_in *li)
{
	void	*tmp;

	if (!(tmp = ft_memalloc(sizeof(t_lem_in_room) * ((size_t)li->nb_rooms
		+ 1))))
		exit (-1);
	ft_memcpy(tmp, li->anthill, sizeof(t_lem_in_room) * ((size_t)li->nb_rooms));
	ft_memdel((void**)&li->anthill);
	li->anthill = tmp;
	li->anthill[li->nb_rooms] = init_t_lem_in_room(li->anthill[li->nb_rooms]);
}

void			del_t_lem_in_room(t_lem_in_room *li_r)
{
	ft_strdel(&li_r->name);
	ft_memdel((void**)&li_r->next);
	ft_memdel((void**)&li_r);
}

t_lem_in_room	*init_t_lem_in_room(t_lem_in_room *li_r)
{
	if (!(li_r = ft_memalloc(sizeof(t_lem_in_room))))
		exit (-1);
	if (!(li_r->next = ft_memalloc(sizeof(t_lem_in_room*))))
		exit (-1);
	li_r->name = NULL;
	li_r->x_coor = 0;
	li_r->y_coor = 0;
	li_r->start = 0;
	li_r->end = 0;
	li_r->nb_nexts = 0;
	return (li_r);
}

void			del_t_lem_in(t_lem_in *li)
{
	ft_strdel(&li->line);
	while (li->nb_rooms-- > 0)
		del_t_lem_in_room(li->anthill[li->nb_rooms]);
	ft_memdel((void**)&li->anthill);
	while (li->nb_paths-- > 0)
		del_t_lem_in_path(li->paths[li->nb_paths]);
	ft_memdel((void**)&li->paths);
	ft_tabdel(&li->used_rooms);
	ft_memdel((void**)&li);
}

t_lem_in		*init_t_lem_in(t_lem_in *li)
{
	if (!(li = ft_memalloc(sizeof(t_lem_in)))
		|| !(li->anthill = ft_memalloc(sizeof(t_lem_in_room*)))
		|| !(li->used_rooms = ft_tabnew(0)))
		exit (-1);
	li->line = NULL;
	li->paths = NULL;
	li->start_boo = 0;
	li->end_boo = 0;
	li->nb_ant = 0;
	li->nb_ant_backup = 0;
	li->nb_rooms = 0;
	li->nb_paths = 0;
	li->p_nb_ant = 1;
	li->p_rooms = 0;
	li->p_pipes = 0;
	li->start_pos = 0;
	li->end_pos = 0;
	li->travel_dir = 0;
	li->cur_path = 0;
	li->b_littlepath = 0;
	li->b_endmoveants = 0;
	return (li);
}
