/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafnasci <rafnasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:38:21 by rafnasci          #+#    #+#             */
/*   Updated: 2024/02/25 13:10:20 by rafnasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../libft/include/libft.h"

int	ft_checkfile(char *file)
{
	if ((file[ft_strlen(file) - 1] == 'r') && (file[ft_strlen(file) - 2] == 'e')
		&& (file[ft_strlen(file) - 3] == 'b')
		&& (file[ft_strlen(file) - 4] == '.'))
		return (1);
	else 
	{
		perror("Wrong type of file");
		exit(EXIT_FAILURE);
	}
	return (0);
}

void	ft_createwin(t_game *game)
{
	ft_init_ptr(&game->ptr, &game->map);
	ft_init_img(&game->sprites, &game->ptr);
	ft_displayall(game);
	mlx_key_hook(game->ptr.win, ft_key_handler, game);
	mlx_loop(game->ptr.mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		if (ft_checkfile(argv[1]) && ft_checkmap(argv[1], &game.map,
				&game.state)
			&& ft_checkpath(argv[1], &game.map))
		{
			ft_createwin(&game);
		}
	}
	return (0);
}
