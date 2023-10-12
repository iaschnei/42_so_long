/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaschnei <iaschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:03:07 by iaschnei          #+#    #+#             */
/*   Updated: 2023/02/06 12:37:13 by iaschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	ft_strlen(char *s)
{
	int	count;

	count = 0;
	if (!s)
		return (0);
	while (s[count])
		count++;
	return (count);
}

char	*ft_strjoin(char *s1, char *s2)
{
	static char	*ret;
	int			iter;
	int			count;
	int			s_len;

	ret = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	iter = 0;
	count = 0;
	s_len = ft_strlen(s1);
	while (iter < s_len)
	{
		ret[iter] = s1[iter];
		iter++;
	}
	while (count < ft_strlen(s2))
	{
		ret[iter] = s2[count];
		iter++;
		count++;
	}
	free(s1);
	ret[iter] = 0;
	return (ret);
}
