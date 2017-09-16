/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_parsing_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 06:20:47 by mapandel          #+#    #+#             */
/*   Updated: 2017/09/16 09:46:42 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			lem_in_parsing_pipes(t_lem_in *li)
{
	int		i;
	int		j;

	if ((i = 0) || !li->nb_rooms || li->nb_rooms == 1 || li->start_boo != 2
		|| li->end_boo != 2 || ft_strclen(li->line, ' ') != ft_strlen(li->line))
		li->p_pipes = 0;
	while (i < li->nb_rooms)
	{
		if (!(j = 0) && ft_strinc(li->anthill[i]->name, li->line)
			&& li->line[ft_strlen(li->anthill[i]->name)] == '-')
		{
			while (j < li->nb_rooms)
			{
				if (i != j && ft_strinc(li->anthill[j]->name,
					&li->line[ft_strlen(li->anthill[i]->name) + 1])
					&& !li->line[ft_strlen(li->anthill[i]->name) + 1
					+ ft_strlen(li->anthill[j]->name)]
					&& !lem_in_link_rooms(li->anthill[i], li->anthill[j]))
					return ;
				++j;
			}
		}
		++i;
	}
	li->p_pipes = 0;
}

static void		lem_in_parsing_rooms2(t_lem_in *li, char **split)
{
	lem_in_add_room(li);
	li->anthill[li->nb_rooms]->name = ft_strdup(split[0]);
	li->anthill[li->nb_rooms]->x_coor = ft_atoi(split[1]);
	li->anthill[li->nb_rooms]->y_coor = ft_atoi(split[2]);
	if (li->start_boo == 1 && (li->start_boo = 2)
		&& (li->anthill[li->nb_rooms]->start = 1))
		li->start_pos = li->nb_rooms;
	else if (li->end_boo == 1 && (li->end_boo = 2)
		&& (li->anthill[li->nb_rooms]->end = 1))
		li->end_pos = li->nb_rooms;
	++li->nb_rooms;
}

void			lem_in_parsing_rooms(t_lem_in *li)
{
	char	**split;

	li->p_pipes = 1;
	split = ft_strsplit(li->line, ' ');
	if (ft_strmaplen_nullcrashless(split) == 3)
	{
		if (!split[0][0] || split[0][0] == 'L'
			|| ft_atoi_strict(split[1]) == 10000000000
			|| ft_atoi_strict(split[2]) == 10000000000
			|| lem_in_checker_doubles(li, split[0], ft_atoi(split[1]),
			ft_atoi(split[2])))
			li->p_rooms = 0;
		else
			lem_in_parsing_rooms2(li, split);
	}
	else
		li->p_rooms = 0;
	ft_strmapdel(&split);
}

void			lem_in_parsing_nb_ant(t_lem_in *li)
{
	li->p_nb_ant = 0;
	if (ft_atoi_strict(li->line) == 10000000000
		|| !(li->nb_ant = ft_atoi(li->line))
		|| li->start_boo || li->end_boo || li->nb_ant < 0)
		return ;
	li->p_rooms = 1;
}
