/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 11:43:54 by mapandel          #+#    #+#             */
/*   Updated: 2017/10/14 22:38:45 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"

void		lem_in_display_move_ants(t_lem_in *li, t_lem_in_path *li_p)
{
	if (!li_p->ant)
		return ;
	ft_printf("L%d-%s ", li_p->ant, li->anthill[li_p->next->room]->name);
	if (li_p->next->next)
		li_p->next->ant = li_p->ant;
	li_p->ant = 0;
}

void		lem_in_display_banned_room(t_lem_in *li)
{
	size_t		i;

	i = 0;
	while (i < li->used_rooms->len)
	{
		ft_putnbr(li->used_rooms->tab[i]);
		++i;
		if (i != li->used_rooms->len)
			ft_putchar('-');
	}
	ft_putendl("");
}

void		lem_in_display_path(t_lem_in *li, t_lem_in_path *li_p)
{
	t_lem_in_path	*tmp;

	tmp = lem_in_path_start(li_p);
	while (tmp)
	{
		ft_putstr(li->anthill[tmp->room]->name);
		tmp = tmp->next;
		if (tmp)
			ft_putchar('-');
	}
	ft_putendl("");
}

void		lem_in_display_error(t_lem_in *li)
{
	del_t_lem_in(li);
	ft_putendl("\033[31mERROR\033[0m");
	exit(-1);
}
