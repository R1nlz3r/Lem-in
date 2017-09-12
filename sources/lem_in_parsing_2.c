/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_parsing_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 06:20:47 by mapandel          #+#    #+#             */
/*   Updated: 2017/09/12 06:21:01 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	lem_in_parsing_pipes(t_lem_in *li)
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
