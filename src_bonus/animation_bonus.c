/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafnasci <rafnasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:46:14 by rafnasci          #+#    #+#             */
/*   Updated: 2024/05/20 00:17:48 by rafnasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	ft_player_anim(t_game *game, int i)
{
	if (!i)
	{
		if (game->sprites.angle == 'f')
			game->sprites.player = game->sprites.p_angle.p_f_m1;
		else if (game->sprites.angle == 'l')
			game->sprites.player = game->sprites.p_angle.p_l_m1;
		else if (game->sprites.angle == 'r')
			game->sprites.player = game->sprites.p_angle.p_r_m1;
		else
			game->sprites.player = game->sprites.p_angle.p_b_m1;
	}
	else
	{
		if (game->sprites.angle == 'f')
			game->sprites.player = game->sprites.p_angle.p_f_m2;
		else if (game->sprites.angle == 'l')
			game->sprites.player = game->sprites.p_angle.p_l_m2;
		else if (game->sprites.angle == 'r')
			game->sprites.player = game->sprites.p_angle.p_r_m2;
		else
			game->sprites.player = game->sprites.p_angle.p_b_m2;
	}
}

int	ft_loop_collec(t_game *game)
{
	if (game->state.loop < 10)
	{
		game->state.loop++;
		return (0);
	}
	game->state.loop = 0;
	if (game->state.img_col == 0)
		game->sprites.collectibe = game->sprites.pokeferme;
	else if (game->state.img_col == 1)
		game->sprites.collectibe = game->sprites.pokeouvert;
	return (0);
}

int	ft_loop_miaous(t_game *game)
{
	if (game->state.loop3 < 5)
		return (game->state.loop3++, 0);
	game->state.loop3 = 0;
	if (game->state.img_col == 0)
	{
		game->sprites.miaous = game->sprites.miaous_f;
		game->state.img_col++;
	}
	else if (game->state.img_col == 1)
	{
		game->sprites.miaous = game->sprites.miaous_l;
		game->state.img_col++;
	}
	else if (game->state.img_col == 2)
	{
		game->sprites.miaous = game->sprites.miaous_f;
		game->state.img_col++;
	}
	else if (game->state.img_col == 3)
	{
		game->sprites.miaous = game->sprites.miaous_r;
		game->state.img_col = 0;
	}
	return (0);
}

int	ft_loop_player(t_game *game)
{
	if (game->state.loop2 < 7)
	{
		ft_loop_miaous(game);
		ft_loop_collec(game);
		game->state.loop2++;
		return (0);
	}
	game->state.loop2 = 0;
	if (game->state.img_col2 == 0)
	{
		ft_player_anim(game, game->state.img_col2);
		game->state.img_col2++;
	}
	else if (game->state.img_col2 == 1)
	{
		ft_player_anim(game, game->state.img_col2);
		game->state.img_col2 = 0;
	}
	return (0);
}

