/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   touch_t_lem_in_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 22:46:37 by mapandel          #+#    #+#             */
/*   Updated: 2017/08/28 15:49:40 by mapandel         ###   ########.fr       */
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
