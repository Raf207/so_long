/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafnasci <rafnasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:51:46 by rafnasci          #+#    #+#             */
/*   Updated: 2024/05/20 00:45:29 by rafnasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_destroy_img(t_game *game)
{
	mlx_destroy_image(game->ptr.mlx, game->sprites.pokeouvert);
	mlx_destroy_image(game->ptr.mlx, game->sprites.grass);
	mlx_destroy_image(game->ptr.mlx, game->sprites.tree);
	mlx_destroy_image(game->ptr.mlx, game->sprites.exit);
	mlx_destroy_image(game->ptr.mlx, game->sprites.p_angle.p_back);
	mlx_destroy_image(game->ptr.mlx, game->sprites.p_angle.p_front);
	mlx_destroy_image(game->ptr.mlx, game->sprites.p_angle.p_left);
	mlx_destroy_image(game->ptr.mlx, game->sprites.p_angle.p_right);
}

int	ft_exit(t_game *game)
{
	ft_freeplan(game->map.plan);
	ft_destroy_img(game);
	mlx_destroy_window(game->ptr.mlx, game->ptr.win);
	free(game->ptr.mlx);
	exit(0);
}

void	ft_freeplan(char **plan)
{
	int	i;

	i = -1;
	while (plan[++i])
		free(plan[i]);
	free(plan);
}
