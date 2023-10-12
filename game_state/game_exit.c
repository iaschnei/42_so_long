/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaschnei <iaschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:44:53 by iaschnei          #+#    #+#             */
/*   Updated: 2023/02/08 16:52:22 by iaschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	cross_exit(t_data *data)
{
	clean_exit(6, data);
	return (0);
}

void	clean_exit(int err, t_data *data)
{
	if (err > 1)
		mlx_destroy_image(data->mlx, data->img_w);
	if (err > 2)
		mlx_destroy_image(data->mlx, data->img_g);
	if (err > 3)
		mlx_destroy_image(data->mlx, data->img_e);
	if (err > 4)
		mlx_destroy_image(data->mlx, data->img_s);
	if (err > 5)
		mlx_destroy_image(data->mlx, data->img_c);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	arr_free(data->map);
	free(data->map);
	free(data->mlx);
	free(data);
	exit(0);
}

void	mlx_failed(t_data *data)
{
	arr_free(data->map);
	free(data->map);
	free(data);
	write(2, "mlx_init failed :(\n", 19);
	exit(1);
}
