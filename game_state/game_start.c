/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaschnei <iaschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 13:16:33 by iaschnei          #+#    #+#             */
/*   Updated: 2023/02/08 16:52:05 by iaschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	game_start(t_data *data)
{
	int	err;

	data->width = get_w(data->map) * 64;
	data->height = get_h(data->map) * 64;
	data->start = 0;
	data->coll = 0;
	data->exit = 0;
	data->moves = 0;
	data->previous_exit = 0;
	data->max_coll = after_num(data->map) - 1;
	data->mlx = mlx_init();
	if (!data->mlx)
		return (mlx_failed(data));
	data->win = mlx_new_window(data->mlx, data->width, data->height, "so_long");
	if (!data->win)
		return (clean_exit(0, data));
	err = file_to_img(data);
	if (err != 0)
		return (clean_exit(err, data));
	put_background(data);
	put_suzy(data);
	mlx_key_hook(data->win, input, data);
	mlx_hook(data->win, 17, 0, cross_exit, data);
	mlx_loop_hook(data->mlx, no_event, data);
	mlx_loop(data->mlx);
}

int	put_background(t_data *data)
{
	data->x = 0;
	while (data->map[data->x])
	{
		data->y = 0;
		while (data->map[data->x][data->y])
		{
			put_tile(data);
			data->y++;
		}
		data->x++;
	}
	return (0);
}

int	put_tile(t_data *d)
{
	if (d->map[d->x][d->y] == '1')
		mlx_put_image_to_window(d->mlx, d->win, d->img_w, d->y * 64, d->x * 64);
	else if (d->map[d->x][d->y] == '0')
		mlx_put_image_to_window(d->mlx, d->win, d->img_g, d->y * 64, d->x * 64);
	else if (d->map[d->x][d->y] == 'E')
		mlx_put_image_to_window(d->mlx, d->win, d->img_e, d->y * 64, d->x * 64);
	else if (d->map[d->x][d->y] == 'C')
		mlx_put_image_to_window(d->mlx, d->win, d->img_s, d->y * 64, d->x * 64);
	else
	{
		if (d->start == 0)
		{
			d->suzy_x = d->x;
			d->suzy_y = d->y;
		}
	}
	return (0);
}

int	put_suzy(t_data *d)
{
	mlx_put_image_to_window(d->mlx, d->win, d->img_c,
		d->suzy_y * 64, d->suzy_x * 64);
	d->start = 1;
	return (0);
}
