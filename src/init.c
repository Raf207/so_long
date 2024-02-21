/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafnasci <rafnasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:12:53 by rafnasci          #+#    #+#             */
/*   Updated: 2024/02/21 13:30:12 by rafnasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_init_ptr(t_ptr *ptr, t_map *map)
{
	ptr->mlx = mlx_init();
	if (!ptr->mlx)
	{
		perror("Error\nFail to connect to server\n");
		exit(EXIT_FAILURE);
	}
	ptr->win = mlx_new_window(ptr->mlx, map->width * 144, map->height * 144,
			"Pandoul");
}

void	ft_init_img(t_sprites *assets, t_ptr *ptr)
{
	int			img_width;
	int			img_height;

	assets->collectible1 = mlx_xpm_file_to_image(ptr->mlx,
			"Assets/bamboo/bamboo.xpm", &img_width, &img_height);
	assets->grass = mlx_xpm_file_to_image(ptr->mlx,
			"Assets/env/minecraft_grass.xpm", &img_width, &img_height);
	assets->tree = mlx_xpm_file_to_image(ptr->mlx,
			"Assets/env/jungle_tree_144.xpm", &img_width, &img_height);
	assets->player = mlx_xpm_file_to_image(ptr->mlx,
			"Assets/Pandoul/Pandoul_f.xpm", &img_width, &img_height);
}