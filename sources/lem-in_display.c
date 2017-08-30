/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 11:43:54 by mapandel          #+#    #+#             */
/*   Updated: 2017/08/28 19:03:24 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void		lem_in_display_path(t_lem_in_path *li_p)
{
	t_lem_in_path	*tmp;

	tmp = lem_in_path_start(li_p);
	while (tmp)
	{
		ft_putnbr(tmp->room);
		tmp = tmp->next;
		if (tmp)
			ft_putchar('-');
	}
	ft_putendl("");
}

void		lem_in_display_error(t_lem_in *li)
{
	del_t_lem_in(li);
	ft_putendl("\n\033[31mERROR\033[0m");
	exit (-1);
}
