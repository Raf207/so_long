/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafnasci <rafnasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:13:46 by rafnasci          #+#    #+#             */
/*   Updated: 2024/02/21 18:33:49 by rafnasci         ###   ########.fr       */
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
				nb_x * 144, nb_y * 144);
		}
	}
}

void	ft_display_map(t_map *map, t_sprites *sprites, t_ptr *ptr)
{
	int	nb_y;
	int	nb_x;

	nb_y = -1;
	while (++nb_y < map->height)
	{
		nb_x = -1;
		while (++nb_x < map->width)
		{
			if (map->plan[nb_y][nb_x] == 'C')
				mlx_put_image_to_window(ptr->mlx, ptr->win,
					sprites->collectible1, nb_x * 144, nb_y * 144);
			else if (map->plan[nb_y][nb_x] == '1')
				mlx_put_image_to_window(ptr->mlx, ptr->win,
					sprites->tree, nb_x * 144, nb_y * 144);
		}
	}
}

void	ft_display_player(t_map *map, t_sprites *sprites, t_ptr *ptr)
{
	int	nb_y;
	int	nb_x;

	nb_y = -1;
	while (++nb_y < map->height)
	{
		nb_x = -1;
		while (++nb_x < map->width)
		{
			if (nb_y == map->p_pos[1] && nb_x == map->p_pos[0])
				mlx_put_image_to_window(ptr->mlx, ptr->win,
					sprites->player, nb_x * 144, nb_y * 144);
		}
	}
}

int	ft_displayall(t_game *game)
{
	ft_display_background(&game->map, &game->sprites, &game->ptr);
	ft_display_map(&game->map, &game->sprites, &game->ptr);
	ft_display_player(&game->map, &game->sprites, &game->ptr);
	return (0);
}