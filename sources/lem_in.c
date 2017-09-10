/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 19:58:13 by mapandel          #+#    #+#             */
/*   Updated: 2017/09/10 13:40:23 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			main(void)
{
	t_lem_in	*li;

	li = NULL;
	li = init_t_lem_in(li);
	lem_in_parsing(li);
	lem_in_prepare_search_paths(li);
	lem_in_search_paths(li);
}
