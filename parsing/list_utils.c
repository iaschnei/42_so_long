/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaschnei <iaschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:47:17 by iaschnei          #+#    #+#             */
/*   Updated: 2023/02/06 12:35:44 by iaschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_list	*ft_lstnew(void *line)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
	{
		free (line);
		return (NULL);
	}
	new->line = line;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_list **lst, t_list *newlst)
{
	if (newlst == NULL)
		return ;
	if (*lst == NULL)
		*lst = newlst;
	else
		ft_lstlast(*lst)->next = newlst;
}

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;

	if (*lst == NULL)
		return ;
	tmp = *lst;
	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		free((*lst)->line);
		free(*lst);
		*lst = tmp;
	}
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

int	ft_lstsize(t_list *lst)
{
	int	count;

	if (lst == NULL)
		return (0);
	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
