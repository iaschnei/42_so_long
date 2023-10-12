/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaschnei <iaschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:24:17 by iaschnei          #+#    #+#             */
/*   Updated: 2023/02/06 11:57:47 by iaschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	error_print(int errnum)
{
	if (errnum == 10)
		write(2, "Error.\nInvalid number of arguments.\n", 36);
	else if (errnum == 11)
		write(2, "Error.\nInvalid file name, please use a '.ber' file.\n", 52);
	else if (errnum == 12)
		write(2, "Error.\nCouldn't open file.\n", 27);
	else if (errnum == 13)
		write(2, "Error.\nThe argument is not a file.\n", 35);
	else if (errnum == 14)
		write(2, "Error.\nError while allocating.\n", 31);
	return (errnum);
}

int	map_error(int err, t_list *map)
{
	ft_lstclear(&map);
	if (err == 1)
		write(1, "Error.\nInvalid map, please refer to subject.\n", 45);
	else if (err == 2)
		write(1, "Error.\nExit or collectible unreachable.\n", 40);
	return (1);
}
