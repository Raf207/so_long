/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafnasci <rafnasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:55:47 by rafnasci          #+#    #+#             */
/*   Updated: 2024/02/21 21:12:10 by rafnasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_key_handler(int keycode, t_game *game)
{
	if (keycode == 2)
	{
		if (ft_move_ok(&game->map, game->map.p_pos[0] + 1, game->map.p_pos[1]))
		{
			game->map.plan[game->map.p_pos[1]][game->map.p_pos[0]] = '0';
			game->map.p_pos[0] += 1;
			game->map.plan[game->map.p_pos[1]][game->map.p_pos[0]] = 'P';
		}
		ft_displayall(game);
	}
	return (0);
}
