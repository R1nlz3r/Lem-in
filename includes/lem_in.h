/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 17:20:29 by mapandel          #+#    #+#             */
/*   Updated: 2017/09/10 13:13:03 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"

typedef struct				s_lem_in_path
{
	int						room;
	int						len;
	int						ant;
	char					pad_2[4];
	struct s_lem_in_path	*next;
	struct s_lem_in_path	*previous;
}							t_lem_in_path;

typedef struct				s_lem_in_room
{
	char					*name;
	int						x_coor;
	int						y_coor;
	int						start;
	int						end;
	int						nb_nexts;
	char					pad_1[4];
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
	int						nb_ant;
	int						nb_ant_backup;
	int						nb_rooms;
	int						nb_paths;
	int						start_pos;
	int						end_pos;
	int						travel_dir;
	int						cur_path;
	int						b_littlepath;
	int						b_endmoveants;
	char					pad_0[4];
	t_tab					*used_rooms;
	t_lem_in_room			**anthill;
	t_lem_in_path			**paths;
}							t_lem_in;

t_lem_in					*init_t_lem_in(t_lem_in *li);
void						del_t_lem_in(t_lem_in *li);
t_lem_in_room				*init_t_lem_in_room(t_lem_in_room *li_r);
void						del_t_lem_in_room(t_lem_in_room *li_r);
void						lem_in_add_room(t_lem_in *li);
int							lem_in_link_rooms(t_lem_in_room *r1,
	t_lem_in_room *r2);
t_lem_in_path				*init_t_lem_in_path(t_lem_in *li,
	t_lem_in_path *li_p, t_lem_in_path *previous, t_lem_in_room *room);
void						lem_in_add_path(t_lem_in *li);
void						del_t_lem_in_path_chain(t_lem_in_path *li_p);
void						del_t_lem_in_path(t_lem_in_path *li_p);
t_lem_in_path				*lem_in_path_start(t_lem_in_path *li_p);
t_lem_in_path				*lem_in_path_end(t_lem_in_path *li_p);
t_tab						*add_banned_room(t_tab *used_rooms, int banned_pos);
void						del_banned_room(t_tab *used_rooms,
	int unbanned_pos);
int							lem_in_find_pos(t_lem_in *li, t_lem_in_room *room);
void						lem_in_parsing(t_lem_in *li);
int							lem_in_checker_doubles(t_lem_in *li, char *name,
	int x, int y);
int							lem_in_checker_ants(t_lem_in *li);
int							lem_in_is_banned(t_lem_in *li, t_lem_in_room *room);
void						lem_in_prepare_search_paths(t_lem_in *li);
void						lem_in_search_paths(t_lem_in *li)
	__attribute__ ((noreturn));
void						lem_in_move_ants(t_lem_in *li)
	__attribute__ ((noreturn));
void						lem_in_sort_paths(t_lem_in *li);
void						lem_in_sort_rooms(t_lem_in *li);
void						lem_in_display_error(t_lem_in *li)
	__attribute__ ((noreturn));
void						lem_in_display_path(t_lem_in *li,
	t_lem_in_path *li_p);
void						lem_in_display_banned_room(t_lem_in *li);
void						lem_in_display_move_ants(t_lem_in *li,
	t_lem_in_path *li_p);

#endif
