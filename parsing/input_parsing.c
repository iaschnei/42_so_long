/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaschnei <iaschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:17:34 by iaschnei          #+#    #+#             */
/*   Updated: 2023/02/06 12:06:19 by iaschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
|	Make sure that the user does input a .ber file and nothing else.
|	Else return a number conresponding to the error (called in main.c)
*/

int	input_error_check(int ac, char **av)
{
	int		chars;
	int		fd;
	char	buf[1];
	int		readed;

	if (ac != 2)
		return (10);
	chars = ft_strlen(av[1]);
	if (chars < 5)
		return (11);
	if (av[1][chars - 4] != '.' || av[1][chars - 3] != 'b' ||
		av[1][chars - 2] != 'e' || av[1][chars - 1] != 'r')
		return (11);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (12);
	readed = read(fd, buf, 0);
	close(fd);
	if (readed == -1)
		return (13);
	return (0);
}
