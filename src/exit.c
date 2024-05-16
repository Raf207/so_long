/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafnasci <rafnasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:51:46 by rafnasci          #+#    #+#             */
/*   Updated: 2024/05/16 19:51:13 by rafnasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_destroy_img(t_game *game)
{
	mlx_destroy_image(game->ptr.mlx, game->sprites.pokeferme);
	mlx_destroy_image(game->ptr.mlx, game->sprites.pokeouvert);
	mlx_destroy_image(game->ptr.mlx, game->sprites.grass);
	mlx_destroy_image(game->ptr.mlx, game->sprites.tree);
	mlx_destroy_image(game->ptr.mlx, game->sprites.exit);
	mlx_destroy_image(game->ptr.mlx, game->sprites.p_angle.p_f_m1);
	mlx_destroy_image(game->ptr.mlx, game->sprites.p_angle.p_f_m2);
	mlx_destroy_image(game->ptr.mlx, game->sprites.p_angle.p_b_m1);
	mlx_destroy_image(game->ptr.mlx, game->sprites.p_angle.p_b_m2);
	mlx_destroy_image(game->ptr.mlx, game->sprites.p_angle.p_r_m1);
	mlx_destroy_image(game->ptr.mlx, game->sprites.p_angle.p_r_m2);
	mlx_destroy_image(game->ptr.mlx, game->sprites.p_angle.p_l_m1);
	mlx_destroy_image(game->ptr.mlx, game->sprites.p_angle.p_l_m2);
	mlx_destroy_image(game->ptr.mlx, game->sprites.num0);
	mlx_destroy_image(game->ptr.mlx, game->sprites.num1);
	mlx_destroy_image(game->ptr.mlx, game->sprites.num2);
	mlx_destroy_image(game->ptr.mlx, game->sprites.num3);
	mlx_destroy_image(game->ptr.mlx, game->sprites.num4);
	mlx_destroy_image(game->ptr.mlx, game->sprites.num5);
	mlx_destroy_image(game->ptr.mlx, game->sprites.num6);
	mlx_destroy_image(game->ptr.mlx, game->sprites.num7);
	mlx_destroy_image(game->ptr.mlx, game->sprites.num8);
	mlx_destroy_image(game->ptr.mlx, game->sprites.num9);
}

int	ft_exit(t_game *game)
{
	ft_freeplan(game->map.plan);
	ft_destroy_img(game);
	mlx_destroy_window(game->ptr.mlx, game->ptr.win);
	free(game->ptr.mlx);
	//system("leaks so_long");
	exit(0);
	return (1);
}

void	ft_freeplan(char **plan)
{
	int	i;

	i = -1;
	while (plan[++i])
		free(plan[i]);
	free(plan);
}
