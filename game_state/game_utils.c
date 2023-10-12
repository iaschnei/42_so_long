/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaschnei <iaschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:50:38 by iaschnei          #+#    #+#             */
/*   Updated: 2023/02/06 11:51:07 by iaschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	get_h(char **map)
{
	int	x;

	x = 0;
	while (map[x])
		x++;
	return (x);
}

int	get_w(char **map)
{
	int	y;

	y = 0;
	while (map[0][y])
		y++;
	return (y);
}

int	input(int key, t_data *data)
{
	if (key == XK_Escape)
	{
		clean_exit(6, data);
	}
	else if (key == XK_Left || key == XK_Up || key == XK_Down
		|| key == XK_Right)
	{
		suzy_movement(key, data);
		put_suzy(data);
	}
	return (0);
}

int	no_event(t_data *data)
{
	data->max_coll++;
	data->max_coll--;
	return (0);
}

int	file_to_img(t_data *d)
{
	int	w;
	int	h;

	w = 64;
	h = 64;
	d->img_w = mlx_xpm_file_to_image(d->mlx, "sprites/wall.xpm", &w, &h);
	if (!d->img_w)
		return (1);
	d->img_g = mlx_xpm_file_to_image(d->mlx, "sprites/grass.xpm", &w, &h);
	if (!d->img_g)
		return (2);
	d->img_e = mlx_xpm_file_to_image(d->mlx, "sprites/grave.xpm", &w, &h);
	if (!d->img_e)
		return (3);
	d->img_s = mlx_xpm_file_to_image(d->mlx, "sprites/skull.xpm", &w, &h);
	if (!d->img_s)
		return (4);
	d->img_c = mlx_xpm_file_to_image(d->mlx, "sprites/suzy.xpm", &w, &h);
	if (!d->img_c)
		return (5);
	return (0);
}
