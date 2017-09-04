/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in_move_ants.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 04:22:27 by mapandel          #+#    #+#             */
/*   Updated: 2017/09/04 07:25:48 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	lem_in_move_ants(t_lem_in *li)
{
	int		i;

	i = 0;
	while (i < li->nb_paths)
	{
		li->paths[i] = lem_in_path_end(li->paths[i]);
		++i;
	}
	ft_putchar('\n');
	lem_in_sort_paths(li);
/*
**	for (int j = 0; j < li->nb_paths; ++j)
**		lem_in_display_path(li, li->paths[j]);
**	del_t_lem_in(li);
*/
	exit (0);
}
