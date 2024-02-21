/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafnasci <rafnasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:34:14 by rafnasci          #+#    #+#             */
/*   Updated: 2024/02/21 20:44:52 by rafnasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_move_ok(t_map *map, int x, int y)
{
	printf("x : %d | y : %d \n", x, y);
	if (map->plan[x][y] == '1')
		return (0);
	return (1);
}
