/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaschnei <iaschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 16:15:02 by iaschnei          #+#    #+#             */
/*   Updated: 2023/02/06 12:33:25 by iaschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	int		fd;
	t_data	*data;
	t_list	*map;

	if (input_error_check(ac, av) > 0)
		return (error_print(input_error_check(ac, av)));
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (error_print(12));
	map = map_parsing(fd);
	if (map_check(map) == 1)
		return (map_error(1, map));
	if (is_exit_reachable(list_to_arr(map)) == 0)
		return (map_error(2, map));
	data = malloc(sizeof(t_data) * 2);
	if (!data)
		return (map_error(3, map));
	data->map = list_to_arr(map);
	ft_lstclear(&map);
	if (!data->map)
	{
		free(data);
		return (error_print(14));
	}
	return (game_start(data), 0);
}
