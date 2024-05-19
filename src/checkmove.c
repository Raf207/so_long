/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafnasci <rafnasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:34:14 by rafnasci          #+#    #+#             */
/*   Updated: 2024/05/20 00:36:57 by rafnasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_move_ok(t_map *map, int y, int x, t_game *game)
{
	if (map->plan[x][y] == '1')
		return (0);
	else if (map->plan[x][y] == 'C')
		game->state.collected += 1;
	else if (map->plan[x][y] == 'E' && game->state.collected)
		ft_exit(game);
	else if (map->plan[x][y] == 'M')
		ft_exit(game);
	if (game->state.collected == map->collectible)
		game->state.completed = 1;
	game->state.moves += 1;
	ft_printf("moves : %d \n", game->state.moves);
	return (1);
}

void	ft_swap(t_map *map, int *pos, int keycode, t_sprites *sprites)
{
	map->plan[map->p_pos[1]][map->p_pos[0]] = '0';
	map->plan[map->e_pos[1]][map->e_pos[0]] = 'E';
	if (keycode == 2)
	{
		*pos += 1;
		sprites->player = sprites->p_angle.p_right;
	}
	if (keycode == 0)
	{
		*pos += -1;
		sprites->player = sprites->p_angle.p_left;
	}
	if (keycode == 13)
	{
		*pos += -1;
		sprites->player = sprites->p_angle.p_back;
	}
	if (keycode == 1)
	{
		*pos += 1;
		sprites->player = sprites->p_angle.p_front;
	}
	map->plan[map->p_pos[1]][map->p_pos[0]] = 'P';
}
