/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafnasci <rafnasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:37:33 by rafnasci          #+#    #+#             */
/*   Updated: 2023/11/22 14:27:11 by rafnasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_cleanlist(t_list **list, char *last)
{
	t_list	*new_node;
	t_list	*temp_node;

	if (!(*list))
		return ;
	while (*list)
	{
		temp_node = (*list)->next;
		free((*list)->content);
		free((*list));
		(*list) = temp_node;
	}
	*list = NULL;
	if (!last)
		return ;
	new_node = malloc (sizeof(t_list));
	if (!new_node)
		return (free(last));
	new_node->next = NULL;
	new_node->content = last;
	*list = new_node;
}

char	*ft_lastpart(t_list *list)
{
	int		i;
	int		len;
	char	*last_part;
	t_list	*last_node;

	last_node = ft_lastnode(list);
	i = 0;
	len = 0;
	last_part = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!last_part)
		return (NULL);
	while (last_node->content[i] && last_node->content[i] != '\n')
		i++;
	while (last_node->content[i] && last_node->content[++i])
		last_part[len++] = last_node->content[i];
	last_part[len] = '\0';
	if (last_part[0] == '\0')
		return (free(last_part), NULL);
	return (last_part);
}

t_list	*ft_lastnode(t_list *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

void	ft_addlist(t_list **list, char *str)
{
	t_list	*last_node;
	t_list	*new_node;

	new_node = (t_list *) malloc (sizeof(t_list));
	if (!new_node)
		return (free(str));
	last_node = ft_lastnode(*list);
	if (!last_node)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->content = str;
	new_node->next = NULL;
}

int	ft_countlen(t_list *list)
{
	int	tot_len;
	int	i;

	if (!list)
		return (0);
	tot_len = 0;
	while (list)
	{
		i = -1;
		while (list->content[++i])
		{
			tot_len++;
			if (list->content[i] == '\n')
				return (tot_len);
		}
		list = list->next;
	}
	return (tot_len);
}
