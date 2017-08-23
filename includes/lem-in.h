/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 17:20:29 by mapandel          #+#    #+#             */
/*   Updated: 2017/08/23 23:48:29 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

#include "libft.h"

typedef struct				s_lem_in_room
{
	char					*name;
	int						x_coor;
	int						y_coor;
	int						start;
	int						end;
	int						nb_nexts;
	char					pad_0[4];
	struct s_lem_in_room	**next;
}							t_lem_in_room;

typedef struct				s_lem_in
{
	char					*line;
	int						start_boo;
	int						end_boo;
	int						p_nb_ant;
	int						p_rooms;
	int						p_pipes;
	char					pad_1[4];
	int						nb_ant;
	int						nb_rooms;
	t_lem_in_room			**anthill;
}							t_lem_in;

t_lem_in					*init_t_lem_in(t_lem_in *li);
void						del_t_lem_in(t_lem_in *li);
t_lem_in_room				*init_t_lem_in_room(t_lem_in_room *li_r);
void						del_t_lem_in_room(t_lem_in_room *li_r);
void						lem_in_add_room(t_lem_in *li);
int							lem_in_link_rooms(t_lem_in_room *r1,
	t_lem_in_room *r2);
void						lem_in_parsing(t_lem_in *li);
int							lem_in_checker_doubles(t_lem_in *li, char *name,
	int x, int y);
void						lem_in_search_paths(t_lem_in *li);
void						lem_in_display_error(t_lem_in *li)
	__attribute__ ((noreturn));

#endif
