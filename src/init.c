/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafnasci <rafnasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:12:53 by rafnasci          #+#    #+#             */
/*   Updated: 2024/05/16 16:39:10 by rafnasci         ###   ########.fr       */
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
			"Pandoul");
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
	assets->pokeferme = mlx_xpm_file_to_image(ptr->mlx,
			"Assets/pokeball/pokeball1.xpm", &img_width, &img_height);
	ft_init_move(assets, ptr);
	ft_init_num(assets, ptr);
	ft_init_miaouss(assets, ptr);
	assets->collectibe = assets->pokeferme;
}

void	ft_init_move(t_sprites *assets, t_ptr *ptr)
{
	int	img_width;
	int	img_height;

	assets->angle = 'f';
	assets->player = assets->p_angle.p_front;
	assets->p_angle.p_f_m1 = mlx_xpm_file_to_image(ptr->mlx,
			"Assets/tiplouf/tiplouf_f_m1.xpm", &img_width, &img_height);
	assets->p_angle.p_f_m2 = mlx_xpm_file_to_image(ptr->mlx,
			"Assets/tiplouf/tiplouf_f_m2.xpm", &img_width, &img_height);
	assets->p_angle.p_b_m1 = mlx_xpm_file_to_image(ptr->mlx,
			"Assets/tiplouf/tiplouf_b_m1.xpm", &img_width, &img_height);
	assets->p_angle.p_b_m2 = mlx_xpm_file_to_image(ptr->mlx,
			"Assets/tiplouf/tiplouf_b_m2.xpm", &img_width, &img_height);
	assets->p_angle.p_l_m1 = mlx_xpm_file_to_image(ptr->mlx,
			"Assets/tiplouf/tiplouf_pg_m1.xpm", &img_width, &img_height);
	assets->p_angle.p_l_m2 = mlx_xpm_file_to_image(ptr->mlx,
			"Assets/tiplouf/tiplouf_pg_m2.xpm", &img_width, &img_height);
	assets->p_angle.p_r_m1 = mlx_xpm_file_to_image(ptr->mlx,
			"Assets/tiplouf/tiplouf_pd_m1.xpm", &img_width, &img_height);
	assets->p_angle.p_r_m2 = mlx_xpm_file_to_image(ptr->mlx,
			"Assets/tiplouf/tiplouf_pd_m2.xpm", &img_width, &img_height);
}

void	ft_init_num(t_sprites *assets, t_ptr *ptr)
{
	int	img_width;
	int	img_height;

	assets->num0 = mlx_xpm_file_to_image(ptr->mlx,
			"Assets/Num/0.xpm", &img_width, &img_height);
	assets->num1 = mlx_xpm_file_to_image(ptr->mlx,
			"Assets/Num/1.xpm", &img_width, &img_height);
	assets->num2 = mlx_xpm_file_to_image(ptr->mlx,
			"Assets/Num/2.xpm", &img_width, &img_height);
	assets->num3 = mlx_xpm_file_to_image(ptr->mlx,
			"Assets/Num/3.xpm", &img_width, &img_height);
	assets->num4 = mlx_xpm_file_to_image(ptr->mlx,
			"Assets/Num/4.xpm", &img_width, &img_height);
	assets->num5 = mlx_xpm_file_to_image(ptr->mlx,
			"Assets/Num/5.xpm", &img_width, &img_height);
	assets->num6 = mlx_xpm_file_to_image(ptr->mlx,
			"Assets/Num/6.xpm", &img_width, &img_height);
	assets->num7 = mlx_xpm_file_to_image(ptr->mlx,
			"Assets/Num/7.xpm", &img_width, &img_height);
	assets->num8 = mlx_xpm_file_to_image(ptr->mlx,
			"Assets/Num/8.xpm", &img_width, &img_height);
	assets->num9 = mlx_xpm_file_to_image(ptr->mlx,
			"Assets/Num/9.xpm", &img_width, &img_height);
}

void	ft_init_miaouss(t_sprites *assets, t_ptr *ptr)
{
	int	img_width;
	int	img_height;

	assets->miaous_f = mlx_xpm_file_to_image(ptr->mlx,
			"Assets/Miaouss/mia-0.xpm", &img_width, &img_height);
	assets->miaous_l = mlx_xpm_file_to_image(ptr->mlx,
			"Assets/Miaouss/mia-1.xpm", &img_width, &img_height);
	assets->miaous_r = mlx_xpm_file_to_image(ptr->mlx,
			"Assets/Miaouss/mia-2.xpm", &img_width, &img_height);
	assets->miaous = assets->miaous_f;
}
