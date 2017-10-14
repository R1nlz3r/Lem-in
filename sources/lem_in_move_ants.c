/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_move_ants.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 04:22:27 by mapandel          #+#    #+#             */
/*   Updated: 2017/10/14 23:12:59 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		lem_in_move_ants3(t_lem_in *li)
{
	t_lem_in_path	*tmp;
	int				i;

	i = 0;
	li->b_endmoveants = 0;
	while (i < li->nb_paths)
	{
		tmp = lem_in_path_end(li->paths[i++]);
		if (tmp->len <= li->nb_ant_backup - li->nb_ant)
		{
			++li->nb_ant;
			tmp = lem_in_path_start(tmp);
			tmp->ant = li->nb_ant;
			lem_in_display_move_ants(li, tmp);
			li->b_endmoveants = 1;
		}
	}
	if (!li->b_endmoveants && li->nb_ant != li->nb_ant_backup)
	{
		tmp = lem_in_path_end(li->paths[0]);
		++li->nb_ant;
		tmp = lem_in_path_start(tmp);
		tmp->ant = li->nb_ant;
		lem_in_display_move_ants(li, tmp);
	}
}

static void		lem_in_move_ants2(t_lem_in *li)
{
	t_lem_in_path	*tmp;
	int				i;

	i = 0;
	while (i < li->nb_paths)
	{
		tmp = lem_in_path_end(li->paths[i]);
		while (tmp)
		{
			lem_in_display_move_ants(li, tmp);
			tmp = tmp->previous;
		}
		++i;
	}
}

void			lem_in_move_ants(t_lem_in *li)
{
	ft_putstr_buffer("", 1);
	ft_putchar('\n');
	lem_in_sort_paths(li);
	lem_in_sort_rooms(li);
	li->nb_ant_backup = li->nb_ant;
	li->nb_ant = 0;
	while (lem_in_checker_ants(li))
	{
		lem_in_move_ants2(li);
		lem_in_move_ants3(li);
		ft_putendl("\033[1D\033[J");
	}
	del_t_lem_in(li);
	exit(0);
}
