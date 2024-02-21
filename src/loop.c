/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafnasci <rafnasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:55:47 by rafnasci          #+#    #+#             */
/*   Updated: 2024/02/21 22:28:12 by rafnasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_key_handler(int keycode, t_game *game)
{
	if (keycode == 2)
	{
		if (ft_move_ok(&game->map, game->map.p_pos[0] + 1, game->map.p_pos[1]))
			ft_swap(&game->map, keycode);
	}
	if (keycode == 1)
	{
		if (ft_move_ok(&game->map, game->map.p_pos[0], game->map.p_pos[1] + 1))
			ft_swap(&game->map, keycode);
	}
	if (keycode == 0)
	{
		if (ft_move_ok(&game->map, game->map.p_pos[0] - 1, game->map.p_pos[1]))
			ft_swap(&game->map, keycode);
	}
	if (keycode == 13)
	{
		if (ft_move_ok(&game->map, game->map.p_pos[0], game->map.p_pos[1] - 1))
			ft_swap(&game->map, keycode);
		ft_displayall(game);
	}
	return (0);
}
