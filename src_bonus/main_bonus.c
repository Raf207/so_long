/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafnasci <rafnasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:38:21 by rafnasci          #+#    #+#             */
/*   Updated: 2024/05/20 00:52:59 by rafnasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	ft_checkfile(char *file)
{
	if ((file[ft_strlen(file) - 1] == 'r') && (file[ft_strlen(file) - 2] == 'e')
		&& (file[ft_strlen(file) - 3] == 'b')
		&& (file[ft_strlen(file) - 4] == '.'))
		return (1);
	else
	{
		ft_putstr_fd("Error\nWrong type of file\n", 2);
		exit(EXIT_FAILURE);
	}
	return (0);
}

void	ft_gameloop(t_game *game)
{
	mlx_loop_hook(game->ptr.mlx, ft_displayall, game);
	mlx_hook(game->ptr.win, 17, 0, ft_exit, game);
	mlx_hook(game->ptr.win, 2, 1L << 0, ft_key_handler, game);
	mlx_loop(game->ptr.mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		if (ft_checkfile(argv[1]) && ft_checkmap(argv[1], &game.map,
				&game.state) && ft_checkpath(argv[1], &game.map))
		{
			ft_init_ptr(&game.ptr, &game.map);
			ft_init_img(&game.sprites, &game.ptr);
			ft_gameloop(&game);
		}
	}
	return (0);
}
