/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafnasci <rafnasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:34:14 by rafnasci          #+#    #+#             */
/*   Updated: 2024/02/21 22:26:10 by rafnasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_move_ok(t_map *map, int y, int x)
{
	if (map->plan[x][y] == '1')
		return (0);
	return (1);
}

void	ft_swap(t_map *map, int keycode)
{
	if (keycode == 2)
	{
		map->plan[map->p_pos[1]][map->pos[0]] = '0';
		map->pos[0] += 1;
		map->plan[map->pos[1]][map->pos[0]] = 'P';
	}
	if (keycode == 1)
	{
		map->plan[map->pos[1]][map->pos[0]] = '0';
		map->pos[1] += 1;
		map->plan[map->pos[1]][map->pos[0]] = 'P';
	}
	if (keycode == 0)
	{
		map->plan[map->pos[1]][map->pos[0]] = '0';
		map->pos[0] -= 1;
		map->plan[map->pos[1]][map->pos[0]] = 'P';	
	}
	if (keycode == 13)
	{
		map->plan[map->pos[1]][map->pos[0]] = '0';
		map->pos[1] -= 1;
		map->plan[map->pos[1]][map->pos[0]] = 'P';
	}
}
