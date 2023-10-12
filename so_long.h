/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaschnei <iaschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:25:28 by iaschnei          #+#    #+#             */
/*   Updated: 2023/02/06 12:04:24 by iaschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// ------- LIBRARIES

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include "MLX/mlx.h"
# include <fcntl.h>
# include <X11/keysym.h>

// ------- STRUCTURES

typedef struct s_list
{
	char			*line;
	struct s_list	*next;
}				t_list;

typedef struct s_data
{
	char	**map;
	void	*mlx;
	void	*win;
	void	*img_c;
	void	*img_g;
	void	*img_w;
	void	*img_s;
	void	*img_e;
	int		x;
	int		y;
	int		suzy_x;
	int		suzy_y;
	int		start;
	int		width;
	int		height;
	int		max_coll;
	int		exit;
	int		moves;
	int		previous_exit;
	int		coll;
	char	c;
}				t_data;

// ------- PARSING

int		input_error_check(int ac, char **av);
int		error_print(int errnum);
int		map_error(int err, t_list *map);
t_list	*map_parsing(int fd);
int		map_check(t_list *map);
int		is_exit_reachable(char **map);
int		fill_two(int x, int y, char **map);
int		valid_map(char *s, int *exit, int *start, int *coll);
int		first_and_last_line(char *s);
char	**list_to_arr(t_list *map);
char	*ft_strdup(char *s);
void	arr_free(char **ret);
int		after_num(char **map);
int		get_start_y(char **map);
int		get_start_x(char **map);

// ------- LISTS

t_list	*ft_lstnew(void *line);
void	ft_lstadd_back(t_list **lst, t_list *newlst);
void	ft_lstclear(t_list **lst);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);

// -------- GNL

char	*get_next_line(int fd);
int		find_nl(char *mem);
char	*last_line(char **mem, char *buffer);
char	*extract_line(char *mem, char *buffer);
char	*new_memory(char *mem, int iter);
int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);

// ------- GAME STATE

int		special_tiles(t_data *d);
int		suzy_movement(int key, t_data *d);
int		refresh_map(t_data *d);
int		ft_printnum(int i);
void	game_start(t_data *data);
int		put_background(t_data *data);
int		put_tile(t_data *d);
int		put_suzy(t_data *d);
int		cross_exit(t_data *data);
void	clean_exit(int err, t_data *data);
void	mlx_failed(t_data *data);
int		get_h(char **map);
int		get_w(char **map);
int		input(int key, t_data *data);
int		no_event(t_data *data);
int		file_to_img(t_data *d);

#endif