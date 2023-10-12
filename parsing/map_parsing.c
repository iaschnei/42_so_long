/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaschnei <iaschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:45:14 by iaschnei          #+#    #+#             */
/*   Updated: 2023/02/06 12:26:21 by iaschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
|	Parse the map and turn it into a linked list with one line per element
|	Check that the map is correct (a rectangle surrounded by walls, with at
|	least one exit, one starting point and some collectibles, and that 
|	everything is reachable. Otherwise, print an error.
*/

t_list	*map_parsing(int fd)
{
	t_list	*map;
	t_list	*first;

	map = ft_lstnew(get_next_line(fd));
	if (!map)
		return (NULL);
	first = map;
	while (map->line != NULL)
	{
		ft_lstadd_back(&map, ft_lstnew(get_next_line(fd)));
		if (map == NULL)
		{
			ft_lstclear(&first);
			return (NULL);
		}
		map = map->next;
	}
	return (first);
}

int	map_check(t_list *map)
{
	int	exit;
	int	start;
	int	coll;
	int	len;

	exit = 0;
	start = 0;
	coll = 0;
	if (map == NULL)
		return (1);
	len = ft_strlen(map->line);
	if (first_and_last_line(map->line) == 1)
		return (1);
	while (map->next != NULL)
	{
		if (valid_map(map->line, &exit, &start, &coll) == 1
			|| ft_strlen(map->line) != len)
			return (1);
		map = map->next;
	}
	if (first_and_last_line(map->line) == 1)
		return (1);
	if (exit != 1 || start != 1 || coll == 0)
		return (1);
	return (0);
}

int	is_exit_reachable(char **map)
{
	int		x;
	int		y;
	int		after;

	if (!map)
		return (0);
	x = get_start_x(map);
	y = get_start_y(map);
	fill_two(x, y, map);
	after = after_num(map);
	arr_free(map);
	free(map);
	if (after != 0)
		return (0);
	return (1);
}

int	fill_two(int x, int y, char **map)
{
	map[x][y] = '2';
	if (map[x + 1][y] != '1' && map[x + 1][y] != '2')
		fill_two(x + 1, y, map);
	if (map[x - 1][y] != '1' && map[x - 1][y] != '2')
		fill_two(x - 1, y, map);
	if (map[x][y - 1] != '1' && map[x][y - 1] != '2')
		fill_two(x, y - 1, map);
	if (map[x][y + 1] != '1' && map[x][y + 1] != '2')
		fill_two(x, y + 1, map);
	return (0);
}

int	valid_map(char *s, int *exit, int *start, int *coll)
{
	int	iter;
	int	len;

	iter = 0;
	len = ft_strlen(s);
	if (len < 3)
		return (1);
	while (iter < len)
	{
		if (s[iter] != '0' && s[iter] != '1' && s[iter] != 'C'
			&& s[iter] != 'E' && s[iter] != 'P' && s[iter] != '2')
			return (1);
		if (s[iter] == 'E')
			*exit = *exit + 1;
		else if (s[iter] == 'P')
			*start = *start + 1;
		else if (s[iter] == 'C')
			*coll = *coll + 1;
		iter ++;
	}
	if (s[0] != '1' || s[iter - 1] != '1')
		return (1);
	return (0);
}
