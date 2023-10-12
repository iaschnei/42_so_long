/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaschnei <iaschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:15:55 by iaschnei          #+#    #+#             */
/*   Updated: 2023/02/06 12:36:54 by iaschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	first_and_last_line(char *s)
{
	int	iter;
	int	len;

	iter = 0;
	len = ft_strlen(s);
	while (iter < len)
	{
		if (s[iter] != '1')
			return (1);
		iter ++;
	}
	return (0);
}

char	**list_to_arr(t_list *map)
{
	char	**ret;
	int		size;
	int		iter;

	size = ft_lstsize(map);
	if (size == 0)
		return (NULL);
	ret = malloc((size + 1) * sizeof(&size));
	if (!ret)
		return (NULL);
	iter = 0;
	while (map->next != NULL)
	{
		ret[iter] = ft_strdup(map->line);
		if (!ret[iter])
		{
			arr_free(ret);
			free (ret);
			return (NULL);
		}
		map = map->next;
		iter++;
	}
	ret[iter] = 0;
	return (ret);
}

char	*ft_strdup(char *s)
{
	int		iter;
	char	*ret;

	iter = 0;
	ret = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	while (iter < ft_strlen(s))
	{
		ret[iter] = s[iter];
		iter++;
	}
	ret[iter] = 0;
	return (ret);
}

void	arr_free(char **ret)
{
	int	iter;
	int	j;

	iter = 0;
	while (ret[iter])
		iter++;
	j = 0;
	while (j < iter)
	{
		free(ret[j]);
		j++;
	}
}

int	after_num(char **map)
{
	int	x;
	int	y;
	int	ret;

	x = 0;
	ret = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'C' || map[x][y] == 'E')
				ret++;
			y++;
		}
		x++;
	}
	return (ret);
}
