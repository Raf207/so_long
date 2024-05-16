/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafnasci <rafnasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:13:46 by rafnasci          #+#    #+#             */
/*   Updated: 2024/05/16 17:03:22 by rafnasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_display_background(t_map *map, t_sprites *sprites, t_ptr *ptr)
{
	int	nb_y;
	int	nb_x;

	nb_y = -1;
	while (++nb_y < map->height)
	{
		nb_x = -1;
		while (++nb_x < map->width)
		{
			mlx_put_image_to_window(ptr->mlx, ptr->win, sprites->grass, 
				nb_x * 64, nb_y * 64);
		}
	}
}

void	ft_display_map(t_game *game)
{
	int	nb_y;
	int	nb_x;

	nb_y = -1;
	while (++nb_y < game->map.height)
	{
		nb_x = -1;
		while (++nb_x < game->map.width)
		{
			if (game->map.plan[nb_y][nb_x] == 'C')
				mlx_put_image_to_window(game->ptr.mlx, game->ptr.win,
					game->sprites.collectibe, nb_x * 64, nb_y * 64 - 10);
			else if (game->map.plan[nb_y][nb_x] == '1')
				mlx_put_image_to_window(game->ptr.mlx, game->ptr.win,
					game->sprites.tree, nb_x * 64, nb_y * 64);
			else if (game->map.plan[nb_y][nb_x] == 'M')
				mlx_put_image_to_window(game->ptr.mlx, game->ptr.win,
					game->sprites.miaous, nb_x * 64, nb_y * 64);
		}
	}
}

void	ft_display_player(t_game *game)
{
	int	nb_y;
	int	nb_x;

	nb_y = -1;
	while (++nb_y < game->map.height)
	{
		nb_x = -1;
		while (++nb_x < game->map.width)
		{
			if ((nb_y == game->map.e_pos[1] && nb_x == game->map.e_pos[0])
				&& game->state.completed == 1)
				mlx_put_image_to_window(game->ptr.mlx, game->ptr.win,
					game->sprites.exit, nb_x * 64, nb_y * 64);
			if (nb_y == game->map.p_pos[1] && nb_x == game->map.p_pos[0])
				mlx_put_image_to_window(game->ptr.mlx, game->ptr.win,
					game->sprites.player, nb_x * 64, nb_y * 64);
		}
	}
}

int	ft_displayall(t_game *game)
{
	ft_display_background(&game->map, &game->sprites, &game->ptr);
	ft_loop_player(game);
	ft_display_map(game);
	ft_display_player(game);
	ft_display_num(game);
	return (0);
}
