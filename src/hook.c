/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafnasci <rafnasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:55:47 by rafnasci          #+#    #+#             */
/*   Updated: 2024/02/25 12:59:49 by rafnasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_move(int keycode, t_game *game)
{
	if (keycode == 2)
	{
		if (ft_move_ok(&game->map, game->map.p_pos[0] + 1,
				game->map.p_pos[1], game))
			ft_swap(&game->map, keycode);
	}
	if (keycode == 1)
	{
		if (ft_move_ok(&game->map, game->map.p_pos[0],
				game->map.p_pos[1] + 1, game))
			ft_swap(&game->map, keycode);
	}
	if (keycode == 0)
	{
		if (ft_move_ok(&game->map, game->map.p_pos[0] - 1,
				game->map.p_pos[1], game))
			ft_swap(&game->map, keycode);
	}
	if (keycode == 13)
	{
		if (ft_move_ok(&game->map, game->map.p_pos[0],
				game->map.p_pos[1] - 1, game))
			ft_swap(&game->map, keycode);
	}
}

int	ft_key_handler(int keycode, t_game *game)
{
	if (keycode == 0 || keycode == 1 || keycode == 2 || keycode == 13)
		ft_move(keycode, game);
	if (keycode == 53)
		ft_exit(game);
	ft_displayall(game);
	return (0);
}
