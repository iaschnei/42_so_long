/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_state.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaschnei <iaschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:40:34 by iaschnei          #+#    #+#             */
/*   Updated: 2023/02/06 11:47:46 by iaschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	special_tiles(t_data *d)
{
	d->moves++;
	write(1, "Moves: ", 7);
	ft_printnum(d->moves);
	write(1, "\n", 1);
	if (d->map[d->suzy_x][d->suzy_y] == 'C')
		d->coll++;
	if (d->coll == d->max_coll && d->map[d->suzy_x][d->suzy_y] == 'E')
		clean_exit(6, d);
	if (d->exit == 0 && d->map[d->suzy_x][d->suzy_y] == 'E')
		d->previous_exit = 1;
	return (0);
}

int	suzy_movement(int key, t_data *d)
{
	if (key == XK_Left && d->map[d->suzy_x][d->suzy_y - 1] != '1')
	{
		refresh_map(d);
		d->suzy_y -= 1;
		special_tiles(d);
	}
	else if (key == XK_Right && d->map[d->suzy_x][d->suzy_y + 1] != '1')
	{
		refresh_map(d);
		d->suzy_y += 1;
		special_tiles(d);
	}
	else if (key == XK_Up && d->map[d->suzy_x - 1][d->suzy_y] != '1')
	{
		refresh_map(d);
		d->suzy_x -= 1;
		special_tiles(d);
	}
	else if (key == XK_Down && d->map[d->suzy_x + 1][d->suzy_y] != '1')
	{
		refresh_map(d);
		d->suzy_x += 1;
		special_tiles(d);
	}
	return (0);
}

int	refresh_map(t_data *d)
{
	if (d->previous_exit == 0)
		d->map[d->suzy_x][d->suzy_y] = '0';
	else
	{
		d->map[d->suzy_x][d->suzy_y] = 'E';
		d->previous_exit = 0;
	}
	mlx_clear_window(d->mlx, d->win);
	put_background(d);
	return (0);
}

int	ft_printnum(int i)
{
	int		ret;
	char	c;

	ret = 0;
	if (i >= 10)
	{
		ret += ft_printnum(i / 10);
		ret += ft_printnum(i % 10);
	}
	else
	{
		c = i + '0';
		ret += write(1, &c, 1);
	}
	return (ret);
}
