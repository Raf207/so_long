/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafnasci <rafnasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:12:53 by rafnasci          #+#    #+#             */
/*   Updated: 2024/05/20 00:44:33 by rafnasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_init_ptr(t_ptr *ptr, t_map *map)
{
	ptr->mlx = mlx_init();
	if (!ptr->mlx)
	{
		ft_putstr_fd("Error\nFail to connect to server\n", 2);
		exit(EXIT_FAILURE);
	}
	ptr->win = mlx_new_window(ptr->mlx, map->width * 64, map->height * 64,
			"so_long");
}

void	ft_init_img(t_sprites *assets, t_ptr *ptr)
{
	int			img_width;
	int			img_height;

	assets->pokeouvert = mlx_xpm_file_to_image(ptr->mlx,
			"Assets/pokeball/pokeball2.xpm", &img_width, &img_height);
	assets->grass = mlx_xpm_file_to_image(ptr->mlx,
			"Assets/env/pokegrass.xpm", &img_width, &img_height);
	assets->tree = mlx_xpm_file_to_image(ptr->mlx,
			"Assets/env/tallgrass.xpm", &img_width, &img_height);
	assets->exit = mlx_xpm_file_to_image(ptr->mlx,
			"Assets/env/hole.xpm", &img_width, &img_height);
	ft_init_move(assets, ptr);
	assets->collectibe = assets->pokeouvert;
}

void	ft_init_move(t_sprites *assets, t_ptr *ptr)
{
	int	img_width;
	int	img_height;

	assets->p_angle.p_front = mlx_xpm_file_to_image(ptr->mlx,
			"Assets/tiplouf/tiplouf_f.xpm", &img_width, &img_height);
	assets->p_angle.p_back = mlx_xpm_file_to_image(ptr->mlx,
			"Assets/tiplouf/tiplouf_b.xpm", &img_width, &img_height);
	assets->p_angle.p_left = mlx_xpm_file_to_image(ptr->mlx,
			"Assets/tiplouf/tiplouf_pg.xpm", &img_width, &img_height);
	assets->p_angle.p_right = mlx_xpm_file_to_image(ptr->mlx,
			"Assets/tiplouf/tiplouf_pd.xpm", &img_width, &img_height);
	assets->player = assets->p_angle.p_front;
}
