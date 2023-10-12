/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaschnei <iaschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:40:47 by iaschnei          #+#    #+#             */
/*   Updated: 2023/02/06 12:38:05 by iaschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

char	*get_next_line(int fd)
{
	static char	*mem = NULL;
	char		*buffer;
	int			char_read;

	if (fd < 0)
		return (NULL);
	buffer = (char *)malloc((1 + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	buffer[0] = 0;
	char_read = 1;
	while (find_nl(mem) == -1)
	{
		char_read = read(fd, buffer, 1);
		if (char_read == 0)
			return (last_line(&mem, buffer));
		if (char_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[char_read] = 0;
		mem = ft_strjoin(mem, buffer);
	}
	return (extract_line(mem, buffer));
}

int	find_nl(char *mem)
{
	int	iter;
	int	len;

	iter = 0;
	if (!mem)
		return (-1);
	len = ft_strlen(mem);
	while (iter < len)
	{
		if (mem[iter] == '\n')
			return (iter);
		iter++;
	}
	return (-1);
}

char	*last_line(char **mem, char *buffer)
{
	char		*ret;

	free(buffer);
	if (!*mem || !**mem)
	{
		free(*mem);
		return (NULL);
	}
	ret = *mem;
	*mem = 0;
	return (ret);
}

char	*extract_line(char *mem, char *buffer)
{
	int		iter;
	char	*ret;
	int		nl_index;

	iter = 0;
	free(buffer);
	nl_index = find_nl(mem);
	ret = (char *)malloc((nl_index + 2) * sizeof(char));
	if (!ret)
		return (NULL);
	while (iter < nl_index)
	{
		ret[iter] = mem[iter];
		iter++;
	}
	ret[iter] = 0;
	mem = new_memory(mem, iter + 1);
	if (!mem)
	{
		free(ret);
		return (NULL);
	}
	return (ret);
}

char	*new_memory(char *mem, int iter)
{
	int		count;

	count = 0;
	while (mem && mem[iter + count])
	{
		mem[count] = mem[iter + count];
		count++;
	}
	mem[count] = 0;
	return (mem);
}
