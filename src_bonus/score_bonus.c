/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafnasci <rafnasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 05:47:56 by rafnasci          #+#    #+#             */
/*   Updated: 2024/05/20 00:01:08 by rafnasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	ft_count_digit(int nb)
{
	int	digits;

	if (nb == 0)
		return (1);
	digits = 0;
	while (nb > 0)
	{
		nb = nb / 10;
		digits++;
	}
	return (digits);
}

void	ft_show_num2(t_game *game, int digit, char *num)
{
	if (num[digit] == '7')
		mlx_put_image_to_window(game->ptr.mlx, game->ptr.win,
			game->sprites.num7, 16 * digit, 0);
	else if (num[digit] == '8')
		mlx_put_image_to_window(game->ptr.mlx, game->ptr.win,
			game->sprites.num8, 16 * digit, 0);
	else if (num[digit] == '9')
		mlx_put_image_to_window(game->ptr.mlx, game->ptr.win,
			game->sprites.num9, 16 * digit, 0);
}

void	ft_show_num(t_game *game, int digit, char *num)
{
	if (num[digit] == '0')
		mlx_put_image_to_window(game->ptr.mlx, game->ptr.win,
			game->sprites.num0, 16 * digit, 0);
	else if (num[digit] == '1')
		mlx_put_image_to_window(game->ptr.mlx, game->ptr.win,
			game->sprites.num1, 16 * digit, 0);
	else if (num[digit] == '2')
		mlx_put_image_to_window(game->ptr.mlx, game->ptr.win,
			game->sprites.num2, 16 * digit, 0);
	else if (num[digit] == '3')
		mlx_put_image_to_window(game->ptr.mlx, game->ptr.win,
			game->sprites.num3, 16 * digit, 0);
	else if (num[digit] == '4')
		mlx_put_image_to_window(game->ptr.mlx, game->ptr.win,
			game->sprites.num4, 16 * digit, 0);
	else if (num[digit] == '5')
		mlx_put_image_to_window(game->ptr.mlx, game->ptr.win,
			game->sprites.num5, 16 * digit, 0);
	else if (num[digit] == '6')
		mlx_put_image_to_window(game->ptr.mlx, game->ptr.win,
			game->sprites.num6, 16 * digit, 0);
	else
		ft_show_num2(game, digit, num);
}

void	ft_display_num(t_game *game)
{
	int		digits;
	char	*num;
	int		i;

	digits = ft_count_digit(game->state.moves);
	num = ft_itoa(game->state.moves);
	i = -1;
	while (++i < digits)
		ft_show_num(game, i, num);
	free(num);
}
