/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openwindow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafnasci <rafnasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 10:38:46 by rafnasci          #+#    #+#             */
/*   Updated: 2024/02/21 20:29:22 by rafnasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_createwin(t_game *game)
{
	ft_init_ptr(&game->ptr, &game->map);
	ft_init_img(&game->sprites, &game->ptr);
	ft_displayall(game);
	mlx_key_hook(game->ptr.win, ft_key_handler, game);
	mlx_loop(game->ptr.mlx);
}
