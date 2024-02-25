/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafnasci <rafnasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:51:36 by rafnasci          #+#    #+#             */
/*   Updated: 2024/02/25 13:09:52 by rafnasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		start = ft_strlen(s);
	if (len < ft_strlen(&s[start]))
	{
		dst = ft_calloc(len + 1, sizeof(char));
		if (!dst)
			return (NULL);
		if (start > ft_strlen(s))
			return (dst);
		ft_strlcpy(dst, &s[start], len + 1);
	}
	else
	{
		dst = ft_calloc(ft_strlen(&s[start]) + 1, sizeof(char));
		if (!dst)
			return (NULL);
		if (start > ft_strlen(s))
			return (dst);
		ft_strlcpy(dst, &s[start], ft_strlen(s) + 1);
	}
	return (dst);
}
