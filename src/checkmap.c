/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafnasci <rafnasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:26:13 by rafnasci          #+#    #+#             */
/*   Updated: 2023/11/22 17:39:35 by rafnasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/include/libft.h"

int	ft_checkmap(char *file, t_map *map)
{
	int	fd;
	
	fd = opent(file, O_RDONLY);
	if (fd < 0)
		bug
}