/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 22:50:03 by mapandel          #+#    #+#             */
/*   Updated: 2017/09/12 06:20:45 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "get_next_line.h"

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

static void		lem_in_parsing_rooms(t_lem_in *li)
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

static void		lem_in_parsing_nb_ant(t_lem_in *li)
{
	li->nb_ant = ft_atoi_spacesless(li->line);
	li->p_nb_ant = 0;
	if (li->start_boo || li->end_boo || li->nb_ant <= 0
		|| !(ft_isdigit(li->line[0])) || ft_strlen(li->line) > 10
		|| (ft_strlen(li->line) == 10 && ft_strcmp(li->line, "2147483647") > 0))
		return ;
	li->p_rooms = 1;
}

static int		lem_in_parsing2(t_lem_in *li)
{
	if (li->p_nb_ant)
		lem_in_parsing_nb_ant(li);
	else if (li->p_rooms)
	{
		lem_in_parsing_rooms(li);
		if (!li->p_rooms)
			lem_in_parsing_pipes(li);
	}
	else if (li->p_pipes)
		lem_in_parsing_pipes(li);
	else
	{
		ft_putendl(li->line);
		return (1);
	}
	ft_putendl(li->line);
	ft_strdel(&li->line);
	return (0);
}

void			lem_in_parsing(t_lem_in *li)
{
	while ((li->p_nb_ant || li->p_rooms || li->p_pipes)
		&& get_next_line(0, &li->line) > 0)
	{
		if (li->line[0] == '#')
		{
			if (ft_strinc(li->line, "##start") && ft_strlen(li->line) == 7
				&& !li->start_boo)
				li->start_boo = 1;
			else if (ft_strinc(li->line, "##end") && ft_strlen(li->line) == 5
				&& !li->end_boo)
				li->end_boo = 1;
			else if (li->line[1] == '#')
			{
				ft_putendl(li->line);
				break ;
			}
		}
		else if (lem_in_parsing2(li))
			break ;
	}
	ft_strdel(&li->line);
}
