/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 19:58:13 by mapandel          #+#    #+#             */
/*   Updated: 2017/08/23 23:49:55 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int			main(void)
{
	t_lem_in	*li;

	li = NULL;
	li = init_t_lem_in(li);
	lem_in_parsing(li);
	lem_in_search_paths(li);
	del_t_lem_in(li);
	return (0);
}
