/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 13:43:08 by epham             #+#    #+#             */
/*   Updated: 2019/10/18 11:50:26 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

# define TABLE_SIZE 10007

/*
***		ROOM STRUCTURE
*/

typedef	struct		s_room
{
	char			*name;
	int				coord_x;
	int				coord_y;
	int				visited;
	int				inpath;
	int				inqueue;
	int				prev_flow;
	int				weight;
	struct s_link	*linked_rooms;
	struct s_link	*from;
	struct s_room	*prev;
	struct s_room	*next;
}					t_room;

/*
***		LINK STRUCTURE
*/

typedef struct		s_link
{
	t_room			*dest;
	t_room			*from;
	int				flow;
	struct s_link	*rev;
	struct s_link	*next;
}					t_link;

/*
***		SOLUTION STRUCTURE
*/

typedef struct		s_sol
{
	struct s_path	*path;
	long			ants;
	unsigned long	ants_sent;
	unsigned long	ants_arrived;
	unsigned long	pathlen;
	unsigned long	steps;
	struct s_sol	*next;
}					t_sol;

/*
***		PATH STRUCTURE WITHIN SOLUTION
*/

typedef struct		s_path
{
	t_room			*room;
	unsigned long	ant_index;
	struct s_path	*prev;
	struct s_path	*next;
}					t_path;

/*
***		QUEUE STRUCTURE FOR BFS
*/

typedef	struct		s_queue
{
	t_room			*room;
	int				prev_flow;
	struct s_queue	*next;
}					t_queue;

/*
***		LINE FOR READER
*/

typedef struct		s_line
{
	char			*line;
	struct s_line	*next;
}					t_line;

/*
***		ENVIRONMENT VARIABLE
*/

typedef struct		s_env
{
	char			*line;
	unsigned long	ant_nb;
	unsigned long	next_ant;
	int				flag_link;
	int				path_nb;
	unsigned long	total_len;
	unsigned long	ants_sent;
	unsigned long	steps;
	unsigned long	countsteps;
	t_line			*read;
	t_link			*links;
	t_room			**table;
	t_room			*start;
	t_room			*end;
	t_queue			*queue;
	t_queue			*end_queue;
	t_sol			*current_sol;
	t_sol			*optimal_sol;
	t_sol			*shortest_path;
	t_sol			*second_shortest;
}					t_env;

/*
***		BFS
*/

int					bfs(t_env *env);

/*
***		CHECK STEPS
*/

unsigned long		check_steps(t_env *env);

/*
***		EDMOND
*/

void				reset_inpath(t_sol *solution);
int					edmond(t_env *env);

/*
***		ERROR
*/

void				error_invalid_file(t_env *env);
void				invalid_ants(t_env *env);
void				room_problems(t_env *env, int i);
void				no_path(t_env *env);
void				link_to_itself(t_env *env);

/*
***		FREE
*/

void				free_path(t_path **path);
int					free_sol(t_sol **sol);
void				free_queue(t_env *env);
void				free_env(t_env *env);
void				ft_error(int error, t_env *env);

/*
***		HASH
*/

unsigned long long	hash_value(char *key);
void				insert_hash_table(t_room **table, t_room *room, t_env *e);
void				free_table(t_room **table);
void				free_rooms(t_room *rooms);
void				free_links(t_link *links);

/*
***		INIT
*/

t_env				*init_env(void);
void				init_hashtable(t_room **table);

/*
***		IS COMMANDS
*/

int					is_command(char *line);
int					is_comment(char *line);
int					command_type(char *line);

/*
***		IS LINK
*/

int					is_link(char *line);

/*
***		IS ROOM
*/

int					is_room(char *line);

/*
***		OPTI
*/

int					check_change_source(t_env *env, t_room *room, t_room *new);
void				change_source(t_env *e, t_room *r, t_link *l, t_room *new);
int					remontada(t_env *env, t_room *curr, t_link *curr_link);
void				depthfirst_queue(t_env *env, t_room *room);

/*
***		OPTIONS
*/

void				options(t_env *env, int ac, char **av);

/*
***		PARSE LINKS
*/

void				add_link(t_room *room, t_link *link);
t_room				*find_room(t_room **table, char *room_name);
void				*get_link(t_env *env, t_room **table, char *line);
void				parse_links(t_env *env);

/*
***		PARSE ROOMS
*/

t_room				*create_room(char *line);
void				parse_startend(t_env *env, t_room **table);

/*
***		PARSER
*/

void				parse(t_env *env);

/*
***		PATHS
*/

t_path				*create_pathlink(t_env *env, t_room *room);
t_path				*get_path(t_env *env, t_room *next, t_sol *sol);
int					remove_path(t_env *env, t_sol *sol);
t_path				*copy_path(t_env *env, t_sol *solution);

/*
***		PRINT MAP
*/

t_line				*create_line(char *content);
void				add_line(t_env *env, t_line	*line);
void				get_line(t_env *env);
void				print_map(t_env *env);
void				free_lines(t_line *line);

/*
***		PRINT SOL
*/

void				print_sol(t_env *env, t_sol *solution, unsigned long i);

/*
***		QUEUE
*/

void				append_queue(t_env *env, t_link *link, t_room *prev);
void				insert_after_queue(t_env *env, t_link *link, t_room *prev);
void				insert_before_queue(t_env *env, t_link *link, t_room *prev);
void				get_queue(t_env *env, t_room *room);

/*
***		SOLUTIONS
*/

t_sol				*create_solution(t_env *env, t_room *n, int c, t_sol *pth);
void				append_sol(t_env *env, t_sol *new, t_sol *to);
t_sol				*dispatch_ants(t_env *env, t_sol *head);
void				update_solution(t_env *env);

/*
***		UTILS
*/

void				print_paths(t_sol *current_sol);
void				print_path(t_path *head);
void				print_queue(t_env *env);
void				print_hash(t_room **table, size_t size);
void				print_links(t_room *room);
void				print_bfs(t_env *env);

#endif
