/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 22:50:03 by mapandel          #+#    #+#             */
/*   Updated: 2017/10/14 22:36:50 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "get_next_line.h"

static int		lem_in_parsing3(t_lem_in *li)
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
		ft_putendl_buffer(li->line, 0);
		return (1);
	}
	return (0);
}

static int		lem_in_parsing2(t_lem_in *li)
{
	if (ft_strinc(li->line, "##start") && ft_strlen(li->line) == 7
		&& li->start_boo != 2)
		li->start_boo = 1;
	else if (ft_strinc(li->line, "##end") && ft_strlen(li->line) == 5
		&& li->end_boo != 2)
		li->end_boo = 1;
	else if ((ft_strinc(li->line, "##start") && ft_strlen(li->line) == 7)
		|| (ft_strinc(li->line, "##end") && ft_strlen(li->line) == 5))
	{
		ft_putendl_buffer(li->line, 0);
		return (1);
	}
	if (li->start_boo == 1 && li->end_boo == 1)
	{
		ft_putendl_buffer(li->line, 0);
		return (1);
	}
	return (0);
}

void			lem_in_parsing(t_lem_in *li)
{
	while ((li->p_nb_ant || li->p_rooms || li->p_pipes)
		&& get_next_line(0, &li->line) > 0)
	{
		if (li->line[0] == '#' && li->line[1] == '#')
		{
			if (lem_in_parsing2(li))
				break ;
		}
		else if (li->line[0] == '#')
			;
		else if (lem_in_parsing3(li))
			break ;
		ft_putendl_buffer(li->line, 0);
		ft_strdel(&li->line);
	}
	ft_strdel(&li->line);
}
